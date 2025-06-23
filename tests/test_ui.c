#include "../components/core/ui/ui_animals.h"
#include "../components/core/animals/animals.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

// Include stubs
#include "stubs/lvgl.h"

int main(void)
{
    animals_init();
    animal_t a = {"Gecko", 2};
    animals_create(&a);
    animal_t b = {"Snake", 4};
    animals_create(&b);

    lv_obj_t *screen = ui_animals_create();
    assert(screen);
    ui_animals_refresh();

    // screen should have one child list
    assert(screen->child_count == 1);
    lv_obj_t *list = screen->children[0];
    assert(list->child_count == 2);

    // each button has a label child with text
    for (int i=0;i<2;i++) {
        lv_obj_t *btn = list->children[i];
        assert(btn->child_count == 1);
        lv_obj_t *label = btn->children[0];
        if (i==0) {
            assert(strcmp(label->text, "Gecko (2)") == 0);
        } else {
            assert(strcmp(label->text, "Snake (4)") == 0);
        }
    }

    printf("test_ui: all tests passed\n");
    return 0;
}
