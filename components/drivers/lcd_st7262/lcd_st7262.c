// Minimal stub implementation of an ST7262 LCD driver

#include "lcd_st7262.h"
#include "core/utils/logging.h"

static lv_display_t *s_disp = NULL;
static lv_color_t s_buf1[480 * 10];
static lv_color_t s_buf2[480 * 10];

// Flush callback used by LVGL. A real implementation would transmit the
// pixel data contained in `color_p` for the area defined by `area`.
static void st7262_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
    (void)area;
    (void)px_map;

    // Signal to LVGL that flushing is finished
    lv_display_flush_ready(disp);
}

// Initialise the LCD controller and register the LVGL driver
void lcd_st7262_init(void)
{
    s_disp = lv_display_create(480, 320);
    lv_display_set_buffers(s_disp, s_buf1, s_buf2, sizeof(s_buf1),
                           LV_DISPLAY_RENDER_MODE_PARTIAL);
    lv_display_set_flush_cb(s_disp, st7262_flush);

    log_info("ST7262", "display driver initialised");
}

