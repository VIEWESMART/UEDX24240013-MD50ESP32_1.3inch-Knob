#ifndef UI_UI_H__
#define UI_UI_H__

#include "lvgl.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*ret_cb_t)(void *args);

void ui_init(void);
void ui_add_obj_to_encoder_group(lv_obj_t *obj);
void ui_remove_all_objs_from_encoder_group(void);

#ifdef __cplusplus
}
#endif

#endif
