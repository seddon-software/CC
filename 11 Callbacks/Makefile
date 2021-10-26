CC := gcc
WARNINGS := -Wall
CFLAGS := -g -D_POSIX_C_SOURCE=200112L -O0 $(WARNINGS) $(CFLAGS) -std=c11 -pthread 
SOURCES := $(wildcard *.c)
EXECUTABLES := $(SOURCES:.c=.exe)


all: $(EXECUTABLES)


$(EXECUTABLES): %.exe: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)



clean:
	-rm -f *.o
	-rm -f *.exe
	
	
