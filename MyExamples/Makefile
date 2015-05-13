CC := gcc
WARNINGS := -Wall
CFLAGS := -g -O0 $(WARNINGS) -std=c11

SOURCES := $(wildcard *.c)
EXECUTABLES := $(SOURCES:.c=)


all: $(EXECUTABLES)


$(EXECUTABLES): % : %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(EXECUTABLES)

