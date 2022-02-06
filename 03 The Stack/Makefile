CC := gcc
WARNINGS := -Wall
CFLAGS := -g $(WARNINGS) -std=c11 
LFLAGS := -lm  -pthread
SOURCES := $(wildcard *.c)
EXECUTABLES := $(SOURCES:.c=.exe)


all: $(EXECUTABLES)


$(EXECUTABLES): %.exe: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)



clean:
	-rm -f *.o
	-rm -f *.exe
	
	
