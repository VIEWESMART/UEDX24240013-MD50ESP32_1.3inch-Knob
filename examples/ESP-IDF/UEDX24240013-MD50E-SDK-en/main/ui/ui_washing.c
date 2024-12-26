
#include <stdio.h>
#include <time.h>
#include "lvgl.h"
#include "ui.h"
#include "ui_washing.h"
#include "src/misc/lv_math.h"

static lv_obj_t  *page;
static ret_cb_t return_callback;
static lv_obj_t *img_bg;
static lv_obj_t *img_wave1, *img_wave2;
static lv_coord_t img_wave1_x, img_wave2_x;

LV_IMG_DECLARE(img_washing_bg);
LV_IMG_DECLARE(img_washing_wave1);
LV_IMG_DECLARE(img_washing_wave2);
LV_IMG_DECLARE(img_washing_bubble1);
LV_IMG_DECLARE(img_washing_bubble2);
LV_IMG_DECLARE(img_washing_stand);
LV_IMG_DECLARE(img_washing_shirt);
LV_IMG_DECLARE(img_washing_underwear);

#define FUNC_NUM 3
static const lv_img_dsc_t *wash_funcs[FUNC_NUM] = {
    &img_washing_stand,
    &img_washing_shirt,
    &img_washing_underwear,
};

static lv_obj_t *img_funcs[FUNC_NUM];
static int16_t func_index = 0;
static int16_t last_theta = 0;

static void arc_path_by_theta(int16_t theta, int16_t *x, int16_t *y)
{
    const int ox = -18, oy = 0;
    *x = ox + ((lv_trigo_sin(theta) * 85) >> LV_TRIGO_SHIFT);
    *y = oy + ((lv_trigo_sin(theta + 90) * 85) >> LV_TRIGO_SHIFT);
}

static void func_anim_cb(void *args, int32_t v)
{
    int dir = (int)args;
    int16_t x, y;
    for (size_t i = 0; i < FUNC_NUM; i++) {
        int theta = ((i + func_index) * 45) + (dir * v);
        arc_path_by_theta(theta, &x, &y);
        lv_obj_align(img_funcs[i], LV_ALIGN_CENTER, x, y);
        int32_t abs_t = LV_ABS(theta - 90);
        if (abs_t < 30) {
            lv_img_set_zoom(img_funcs[i], 256 * (100 - abs_t) / 70);
            lv_obj_set_style_img_recolor_opa(img_funcs[i], LV_OPA_COVER, 0);
            lv_obj_set_style_img_recolor(img_funcs[i], lv_color_hsv_to_rgb(200, (30-abs_t)*60/30, 100), 0);
        }
    }
}

static void func_anim_ready_cb(lv_anim_t *a)
{
    int dir = (int)lv_anim_get_user_data(a);
    func_index += dir;
}

static void washing_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    if (LV_EVENT_FOCUSED == code) {
        lv_group_set_editing(lv_group_get_default(), true);
    } else if (LV_EVENT_KEY == code) {
        uint32_t key = lv_event_get_key(e);
        int changed = 0;
        if (LV_KEY_LEFT == key) {
            if (func_index < FUNC_NUM - 1) {
                changed = 1;
            }
        } else if (LV_KEY_RIGHT == key) {
            if (func_index >= 1) {
                changed = -1;
            }
        }
        if (changed) {
            lv_anim_t a1;
            lv_anim_init(&a1);
            lv_anim_set_var(&a1, (void *)changed);
            lv_anim_set_delay(&a1, 0);
            lv_anim_set_values(&a1, 0, 45);
            lv_anim_set_exec_cb(&a1, func_anim_cb);
            lv_anim_set_path_cb(&a1, lv_anim_path_ease_in_out);
            lv_anim_set_ready_cb(&a1, func_anim_ready_cb);
            lv_anim_set_user_data(&a1, (void *)changed);
            lv_anim_set_time(&a1, 350);
            lv_anim_start(&a1);
        }

    } else if (LV_EVENT_LONG_PRESSED == code) {
        lv_indev_wait_release(lv_indev_get_next(NULL));
        ui_washing_delete();
    }
}

static void bub1_anim_cb(void *args, int32_t v)
{
    lv_obj_t *img_bub = (lv_obj_t *)args;
    lv_coord_t y = lv_obj_get_y_aligned(img_bub);
    int opa = 0;
    if (y > -60) {
        opa = 255 * (60 + y) / 60;
    }
    lv_obj_set_style_img_opa(img_bub, opa, 0);
    lv_obj_set_y(img_bub, v);
}

static void wave_anim_cb(void *args, int32_t v)
{
    lv_obj_set_x(img_wave1, img_wave1_x + LV_ABS(v));
    lv_obj_set_x(img_wave2, img_wave2_x - LV_ABS(v));
}

static void mask_event_cb(lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj = lv_event_get_target(e);

    static int16_t mask_id = -1;

    if (code == LV_EVENT_COVER_CHECK) {
        lv_event_set_cover_res(e, LV_COVER_RES_MASKED);
    } else if (code == LV_EVENT_DRAW_MAIN_BEGIN) {
        /* add mask */
        lv_area_t win_area;
        lv_obj_get_coords(img_bg, &win_area);
        lv_draw_mask_radius_param_t *mask_out_param = lv_mem_buf_get(sizeof(lv_draw_mask_radius_param_t));
        lv_draw_mask_radius_init(mask_out_param, &win_area, LV_RADIUS_CIRCLE, 0);
        mask_id = lv_draw_mask_add(mask_out_param, NULL);
    } else if (code == LV_EVENT_DRAW_POST_END) {
        lv_draw_mask_radius_param_t *mask = lv_draw_mask_remove_id(mask_id);
        lv_draw_mask_free_param(mask);
        lv_mem_buf_release(mask);
        mask_id = -1;
    }
}

void ui_washing_init(ret_cb_t ret_cb)
{
    if (page) {
        LV_LOG_WARN("washing page already created");
        return;
    }

    return_callback = ret_cb;

    page = lv_obj_create(lv_scr_act());
    lv_obj_set_size(page, lv_obj_get_width(lv_obj_get_parent(page)), lv_obj_get_height(lv_obj_get_parent(page)));
    lv_obj_set_style_border_width(page, 5, 0);
    lv_obj_set_style_radius(page, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(page, lv_color_make(20, 20, 20), 0);
    lv_obj_set_style_border_color(page, lv_palette_main(LV_PALETTE_LIGHT_BLUE), 0);
    lv_obj_clear_flag(page, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_center(page);
    lv_obj_refr_size(page);

    img_bg = lv_img_create(page);
    lv_img_set_src(img_bg, &img_washing_bg);
    lv_obj_align(img_bg, LV_ALIGN_LEFT_MID, -7, 0);
    img_wave1 = lv_img_create(img_bg);
    lv_img_set_src(img_wave1, &img_washing_wave1);
    lv_obj_align(img_wave1, LV_ALIGN_BOTTOM_MID, -15, 10);
    img_wave2 = lv_img_create(img_bg);
    lv_img_set_src(img_wave2, &img_washing_wave2);
    lv_obj_align(img_wave2, LV_ALIGN_BOTTOM_MID, 20, 10);
    lv_obj_t *img_bub1 = lv_img_create(img_bg);
    lv_img_set_src(img_bub1, &img_washing_bubble1);
    lv_obj_center(img_bub1);
    lv_obj_t *img_bub2 = lv_img_create(img_bg);
    lv_img_set_src(img_bub2, &img_washing_bubble2);
    lv_obj_center(img_bub2);
    lv_obj_add_event_cb(img_wave1, mask_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(img_wave2, mask_event_cb, LV_EVENT_ALL, NULL);

    int16_t x, y;
    for (size_t i = 0; i < FUNC_NUM; i++) {
        arc_path_by_theta(i * 45, &x, &y);
        img_funcs[i] = lv_img_create(page);
        lv_img_set_src(img_funcs[i], wash_funcs[i]);
        lv_obj_align(img_funcs[i], LV_ALIGN_CENTER, x, y);
    }
    func_anim_cb((void*)0, 0);

    lv_obj_t *label1 = lv_label_create(page);
    lv_obj_set_style_text_font(label1, &lv_font_montserrat_16, 0);
    lv_label_set_text(label1, "- 45 min -");
    lv_obj_set_style_text_opa(label1, LV_OPA_70, 0);
    lv_obj_set_width(label1, 150);  /*Set smaller width to make the lines wrap*/
    lv_obj_set_style_text_align(label1, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_align(label1, LV_ALIGN_CENTER, 60, 27);

    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_var(&a1, img_bub1);
    lv_anim_set_delay(&a1, 0);
    lv_anim_set_values(&a1, lv_obj_get_y_aligned(img_bub1), lv_obj_get_y_aligned(img_bub1) - 90);
    lv_anim_set_exec_cb(&a1, bub1_anim_cb);
    lv_anim_set_path_cb(&a1, lv_anim_path_ease_in_out);
    lv_anim_set_time(&a1, lv_rand(1800, 2300));
    lv_anim_set_repeat_count(&a1, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a1);

    lv_anim_t a2;
    lv_anim_init(&a2);
    lv_anim_set_var(&a2, img_bub2);
    lv_anim_set_delay(&a2, 0);
    lv_anim_set_values(&a2, lv_obj_get_y_aligned(img_bub2), lv_obj_get_y_aligned(img_bub2) - 90);
    lv_anim_set_exec_cb(&a2, bub1_anim_cb);
    lv_anim_set_path_cb(&a2, lv_anim_path_ease_in_out);
    lv_anim_set_time(&a2, lv_rand(2000, 2800));
    lv_anim_set_repeat_count(&a2, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a2);

    img_wave1_x = lv_obj_get_x_aligned(img_wave1);
    img_wave2_x = lv_obj_get_x_aligned(img_wave2);
    lv_anim_t a3;
    lv_anim_init(&a3);
    lv_anim_set_var(&a3, img_wave1);
    lv_anim_set_delay(&a3, 0);
    lv_anim_set_values(&a3, -40, 40);
    lv_anim_set_exec_cb(&a3, wave_anim_cb);
    lv_anim_set_path_cb(&a3, lv_anim_path_ease_in_out);
    lv_anim_set_time(&a3, lv_rand(3200, 4000));
    lv_anim_set_repeat_count(&a3, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a3);

    lv_obj_add_event_cb(page, washing_event_cb, LV_EVENT_FOCUSED, NULL);
    lv_obj_add_event_cb(page, washing_event_cb, LV_EVENT_LONG_PRESSED, NULL);
    lv_obj_add_event_cb(page, washing_event_cb, LV_EVENT_KEY, NULL);
    ui_add_obj_to_encoder_group(page);
}

void ui_washing_delete(void)
{
    if (page) {
        ui_remove_all_objs_from_encoder_group();
        lv_anim_del_all();
        lv_obj_del(page);
        page = NULL;
        if (return_callback) {
            return_callback(NULL);
        }
    }
}
