#include "lvgl.h"
#include <stdio.h>
#include "esp_system.h"
#ifdef ESP_IDF_VERSION
#include "esp_log.h"
#endif
#include "ui.h"
#include "ui_weather.h"

static lv_obj_t *page;
static ret_cb_t return_callback;

static void weather_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    if (LV_EVENT_FOCUSED == code) {
        lv_group_set_editing(lv_group_get_default(), true);
    } else if (LV_EVENT_KEY == code) {
        uint32_t key = lv_event_get_key(e);

    } else if (LV_EVENT_LONG_PRESSED == code) {
        lv_indev_wait_release(lv_indev_get_next(NULL));
        ui_weather_delete();
    }
}

void ui_weather_init(ret_cb_t ret_cb)
{
    if (page) {
        LV_LOG_WARN("weather page already created");
        return;
    }

    return_callback = ret_cb;

    page = lv_obj_create(lv_scr_act());
    lv_obj_set_size(page, lv_obj_get_width(lv_obj_get_parent(page)), lv_obj_get_height(lv_obj_get_parent(page)));
    lv_obj_set_style_border_width(page, 0, 0);
    lv_obj_set_style_radius(page, 0, 0);
    lv_obj_clear_flag(page, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_center(page);

    LV_IMG_DECLARE(img_weather);
    lv_obj_t *img = lv_img_create(page);
    lv_img_set_src(img, &img_weather);
    lv_obj_align(img, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_img_opa(img, LV_OPA_80, 0);

    lv_obj_t *label_city = lv_label_create(img);
    lv_label_set_text(label_city, "Shang hai");
    lv_obj_set_style_text_font(label_city, &lv_font_montserrat_20, 0);
    lv_obj_set_size(label_city, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_style_text_align(label_city, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(label_city, LV_ALIGN_CENTER, 0, -70);

    lv_obj_t *label_temperature = lv_label_create(img);
    lv_label_set_text(label_temperature, "24℃");
    LV_FONT_DECLARE(font_cn_48);
    lv_obj_set_style_text_font(label_temperature, &font_cn_48, 0);
    lv_obj_set_size(label_temperature, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
    lv_obj_set_style_text_align(label_temperature, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align_to(label_temperature, label_city, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);

    LV_IMG_DECLARE(img_cloudy);
    lv_obj_t *img_icon = lv_img_create(img);
    lv_img_set_src(img_icon, &img_cloudy);
    lv_obj_align_to(img_icon, label_temperature, LV_ALIGN_OUT_BOTTOM_MID, 0, 8);

    lv_obj_t *label_state = lv_label_create(img);
    lv_label_set_text_fmt(label_state, "Mostly sunny\nMin:%02d℃ Max:%02d℃", 22, 28);
    LV_FONT_DECLARE(font_cn_12);
    lv_obj_set_style_text_font(label_state, &font_cn_12, 0);
    lv_obj_set_width(label_state, 150);
    lv_obj_set_style_text_align(label_state, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align_to(label_state, img_icon, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);

    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_var(&a1, label_city);
    lv_anim_set_values(&a1, lv_obj_get_y_aligned(label_city) - 20, lv_obj_get_y_aligned(label_city));
    lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_path_cb(&a1, lv_anim_path_overshoot);
    lv_anim_set_time(&a1, 400);
    lv_anim_start(&a1);

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_var(&a2, img_icon);
    lv_anim_set_values(&a2, lv_obj_get_y_aligned(img_icon) + 30, lv_obj_get_y_aligned(img_icon));
    lv_anim_set_exec_cb(&a2, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_path_cb(&a2, lv_anim_path_overshoot);
    lv_anim_set_time(&a2, 400);
    lv_anim_start(&a2);

    lv_anim_t a3;
    lv_anim_init(&a3);
    lv_anim_set_var(&a3, label_state);
    lv_anim_set_values(&a3, lv_obj_get_y_aligned(label_state) + 40, lv_obj_get_y_aligned(label_state));
    lv_anim_set_exec_cb(&a3, (lv_anim_exec_xcb_t)lv_obj_set_y);
    lv_anim_set_path_cb(&a3, lv_anim_path_overshoot);
    lv_anim_set_time(&a3, 400);
    lv_anim_start(&a3);

    lv_obj_add_event_cb(page, weather_event_cb, LV_EVENT_FOCUSED, NULL);
    lv_obj_add_event_cb(page, weather_event_cb, LV_EVENT_LONG_PRESSED, NULL);
    ui_add_obj_to_encoder_group(page);

}

void ui_weather_delete(void)
{
    if (page) {
        ui_remove_all_objs_from_encoder_group();
        lv_obj_del(page);
        page = NULL;
        if (return_callback) {
            return_callback(NULL);
        }
    }
}


