CC ?= gcc
CFLAGS = -I../components/core/animals -I../components/storage

TESTS = test_animals test_storage

all: $(TESTS)

%: %.c ../components/core/animals/animals.c ../components/storage/storage.c
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(TESTS)

.PHONY: all clean
