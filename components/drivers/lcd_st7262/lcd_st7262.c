// Minimal stub implementation of an ST7262 LCD driver

#include "lcd_st7262.h"
#include "core/utils/logging.h"

static lv_disp_draw_buf_t s_draw_buf;
static lv_color_t s_buf1[LV_HOR_RES_MAX * 10];
static lv_color_t s_buf2[LV_HOR_RES_MAX * 10];

// Flush callback used by LVGL. A real implementation would transmit the
// pixel data contained in `color_p` for the area defined by `area`.
static void st7262_flush(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_p)
{
    (void)area;
    (void)color_p;

    // Signal to LVGL that flushing is finished
    lv_disp_flush_ready(drv);
}

// Initialise the LCD controller and register the LVGL driver
void lcd_st7262_init(void)
{
    lv_disp_draw_buf_init(&s_draw_buf, s_buf1, s_buf2, LV_HOR_RES_MAX * 10);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = st7262_flush;
    disp_drv.draw_buf = &s_draw_buf;
    disp_drv.hor_res = 480;
    disp_drv.ver_res = 320;

    lv_disp_drv_register(&disp_drv);

    log_info("ST7262", "display driver initialised");
}

