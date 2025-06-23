#include "core/animals/animals.h"
#include "core/ui/ui_animals.h"
#include "core/utils/logging.h"
#include "storage/storage.h"
#include "drivers/lcd_st7262/lcd_st7262.h"
#include "drivers/touch_gt911/gt911.h"
#include "lvgl.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    log_info("MAIN", "initialising LVGL");
    lv_init();

    log_info("MAIN", "initialising animals module");
    animals_init();

    log_info("MAIN", "initialising storage");
    storage_init();

    log_info("MAIN", "initialising display");
    lcd_st7262_init();

    log_info("MAIN", "initialising touch");
    gt911_init();

    log_info("MAIN", "registering input device");
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = gt911_read;
    lv_indev_drv_register(&indev_drv);

    log_info("MAIN", "creating animal screen");
    lv_obj_t *screen = ui_animals_create();
    lv_scr_load(screen);

    log_info("MAIN", "initialisation complete");
    while (1) {
        lv_timer_handler();
        vTaskDelay(pdMS_TO_TICKS(10));
    }
}
