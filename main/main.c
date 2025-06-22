#include "core/animals/animals.h"
#include "storage/storage.h"
#include "drivers/lcd_st7262/lcd_st7262.h"

void app_main(void)
{
    animals_init();
    storage_init();
    lcd_st7262_init();
}
