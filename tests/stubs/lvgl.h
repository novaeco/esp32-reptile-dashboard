#pragma once
#include <stdarg.h>

typedef struct lv_obj_s {
    int type;
    char text[64];
    struct lv_obj_s *parent;
    struct lv_obj_s *children[16];
    int child_count;
} lv_obj_t;

static inline int lv_pct(int v) { return v; }

lv_obj_t *lv_obj_create(lv_obj_t *parent);
lv_obj_t *lv_list_create(lv_obj_t *parent);
lv_obj_t *lv_btn_create(lv_obj_t *parent);
lv_obj_t *lv_label_create(lv_obj_t *parent);
void lv_obj_set_size(lv_obj_t *obj, int w, int h);
void lv_obj_clean(lv_obj_t *obj);
void lv_label_set_text_fmt(lv_obj_t *label, const char *fmt, ...);
