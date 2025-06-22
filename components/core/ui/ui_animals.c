// LVGL screen for displaying a list of animals

#include "ui_animals.h"
#include "core/animals/animals.h"

static lv_obj_t *s_screen = NULL;
static lv_obj_t *s_list = NULL;

// Populate the list widget with the current animals
void ui_animals_refresh(void)
{
    if (!s_list) {
        return;
    }

    lv_obj_clean(s_list);

    size_t count = animals_get_count();
    for (size_t i = 0; i < count; ++i) {
        const animal_t *a = animals_get(i);
        if (!a) {
            continue;
        }

        lv_obj_t *btn = lv_btn_create(s_list);
        lv_obj_t *label = lv_label_create(btn);
        lv_label_set_text_fmt(label, "%s (%d)", a->name, a->age);
    }
}

// Create the animal screen and initial list
lv_obj_t *ui_animals_create(void)
{
    if (s_screen) {
        return s_screen;
    }

    s_screen = lv_obj_create(NULL);
    s_list = lv_list_create(s_screen);
    lv_obj_set_size(s_list, lv_pct(100), lv_pct(100));

    ui_animals_refresh();

    return s_screen;
}
