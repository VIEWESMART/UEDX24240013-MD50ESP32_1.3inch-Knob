idf_component_register(SRCS "src/base/iot_knob.c" "src/ESP_Knob.cpp"
                        INCLUDE_DIRS "src"
                        REQUIRES driver
                        PRIV_REQUIRES esp_timer)
