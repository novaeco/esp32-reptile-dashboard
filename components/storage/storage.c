// Minimal stub implementation of JSON storage helpers

#include "storage.h"
#include <string.h>

// In a full application this would interface with LittleFS or another
// filesystem. These stubs simply pretend that the operations succeed.

bool storage_init(void)
{
    // Nothing to initialise in the stub
    return true;
}

bool storage_save(const char *path, const char *data, size_t len)
{
    (void)path;
    (void)len;
    // Operation would normally write data to a file
    // We simply return true to indicate success
    (void)data;
    return true;
}

bool storage_load(const char *path, char *buffer, size_t len)
{
    (void)path;
    if (buffer && len > 0) {
        // Return an empty JSON array by default
        strncpy(buffer, "[]", len - 1);
        buffer[len - 1] = '\0';
    }
    return true;
}

