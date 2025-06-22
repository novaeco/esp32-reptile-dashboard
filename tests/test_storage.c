#include "../components/storage/storage.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    assert(storage_init());

    char buffer[16];
    memset(buffer, 0, sizeof(buffer));
    assert(storage_load("/animals.json", buffer, sizeof(buffer)));
    assert(strcmp(buffer, "[]") == 0);

    assert(storage_save("/animals.json", "{}", 2));

    printf("test_storage: all tests passed\n");
    return 0;
}
