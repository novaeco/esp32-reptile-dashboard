#include "core/animals/animals.h"
#include "storage/storage.h"
#include "drivers/lcd_st7262/lcd_st7262.h"
#include "drivers/touch_gt911/gt911.h"

void app_main(void)
{
    animals_init();
    storage_init();
    lcd_st7262_init();
    gt911_init();
}
