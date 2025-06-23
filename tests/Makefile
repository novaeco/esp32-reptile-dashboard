CC ?= gcc
CFLAGS = -I.. -I../components -I../components/core/animals -I../components/storage \
         -I../components/core/utils -I../components/core/ui -Istubs

TESTS = test_animals test_storage test_logging test_ui

COMMON_SRCS = ../components/core/animals/animals.c \
              ../components/storage/storage.c \
              ../components/core/utils/logging.c \
              ../components/core/ui/ui_animals.c \
              stubs/lvgl.c \
              stubs/esp_log.c

all: $(TESTS)

%: %.c $(COMMON_SRCS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TESTS)

.PHONY: all clean
