/*
 * SPDX-FileCopyrightText: 2023-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <functional>
#include "base/iot_knob.h"

typedef struct {
    void *knob;
    void *usr_data;
} event_callback_data_t;

class ESP_Knob {
public:

    /**
     * @brief Construct a new knob object
     *
     * @param gpio_encoder_a Encoder Pin A
     * @param gpio_encoder_b Encoder Pin B
     */
    ESP_Knob(int gpio_encoder_a, int gpio_encoder_b);

    /**
     * @brief Destroy the knob object
     *
     */
    ~ESP_Knob(void);

    /**
     * @brief Invert the roatae direction of the knob
     *
     * @note  This function will change the direction of count value increment
     * @note  This function should be called before `begin()`
     *
     */
    void invertDirection(void);

    /**
     * @brief create a knob
     *
     */
    void begin(void);

    /**
     * @brief Delete a knob
     *
     */
    void del(void);

    /**
     * @brief Get knob event
     *
     * @return knob_event_t Knob event
     */
    knob_event_t getEvent(void);

    /**
     * @brief Get knob count value
     *
     */
    int getCountValue(void);

    /**
     * @brief Clear knob cout value to zero
     *
     */
    void clearCountValue(void);

    /**
     * @brief Set the user date for all events
     *
     * @param usr_data
     */
    void setEventUserDate(void *usr_data);

    /**
     * @brief Attach the knob left callback function
     *
     * @param callback Callback function
     * @param usr_data user data
     */
    void attachLeftEventCallback(std::function<void(int, void *)> callback);

    /**
     * @brief Detach the knob right callback function
     *
     */
    void detachLeftEventCallback(void);

    /**
     * @brief Attach the knob right callback function
     *
     * @param callback Callback function
     * @param usr_data user data
     */
    void attachRightEventCallback(std::function<void(int, void *)> callback);

    /**
     * @brief Detach the knob right callback function
     *
     */
    void detachRightEventCallback(void);

    /**
     * @brief Attach the knob count reaches maximum limit callback function
     *
     * @note  High limit is set to `1000` default
     *
     * @param callback Callback function
     * @param usr_data user data
     */
    void attachHighLimitEventCallback(std::function<void(int, void *)> callback);

    /**
     * @brief Detach the knob count reaches maximum limit callback function
     *
     */
    void detachHighLimitEventCallback(void);

    /**
     * @brief Attach the knob count reaches minimum limit callback function
     *
     * @note  Low limit is set to `-1000` default
     *
     * @param callback Callback function
     * @param usr_data user data
     */
    void attachLowLimitEventCallback(std::function<void(int, void *)> callback);

    /**
     * @brief Detach the knob count reaches minimum limit callback function
     *
     */
    void detachLowLimitEventCallback(void);

    /**
     * @brief Attach the knob count reaches zero callback function
     *
     * @param callback Callback function
     * @param usr_data user data
     */
    void attachZeroEventCallback(std::function<void(int, void *)> callback);

    /**
     * @brief Detach the knob count reaches zero callback function
     *
     */
    void detachZeroEventCallback(void);

private:
    static void onEventCallback(void *arg, void *data);

    knob_handle_t _knob_handle; /**< Knob handle */

    int _direction;             /*!< Count increase direction */
    int _gpio_encoder_a;        /*!< Encoder Pin A */
    int _gpio_encoder_b;        /*!< Encoder Pin B */

    event_callback_data_t _event_data;
    std::function<void(int, void *)> _left_event_cb;    /*!< Callback function for knob left event */
    std::function<void(int, void *)> _right_event_cb;    /*!< Callback function for knob left event */
    std::function<void(int, void *)> _hight_limit_event_cb;    /*!< Callback function for knob left event */
    std::function<void(int, void *)> _low_limit_event_cb;    /*!< Callback function for knob left event */
    std::function<void(int, void *)> _zero_event_cb;    /*!< Callback function for knob left event */
};
