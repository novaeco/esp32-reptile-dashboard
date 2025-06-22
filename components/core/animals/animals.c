// Simple in-memory CRUD implementation for animal entries

#include "animals.h"
#include <string.h>

#define MAX_ANIMALS 10

static animal_t s_animals[MAX_ANIMALS];
static size_t s_count = 0;

void animals_init(void)
{
    s_count = 0;
    memset(s_animals, 0, sizeof(s_animals));
}

bool animals_create(const animal_t *animal)
{
    if (!animal || s_count >= MAX_ANIMALS) {
        return false;
    }
    s_animals[s_count] = *animal;
    s_count++;
    return true;
}

const animal_t *animals_get(size_t index)
{
    if (index >= s_count) {
        return NULL;
    }
    return &s_animals[index];
}

bool animals_update(size_t index, const animal_t *animal)
{
    if (!animal || index >= s_count) {
        return false;
    }
    s_animals[index] = *animal;
    return true;
}

bool animals_delete(size_t index)
{
    if (index >= s_count) {
        return false;
    }

    for (size_t i = index; i + 1 < s_count; ++i) {
        s_animals[i] = s_animals[i + 1];
    }

    memset(&s_animals[s_count - 1], 0, sizeof(animal_t));
    s_count--;
    return true;
}

size_t animals_get_count(void)
{
    return s_count;
}

