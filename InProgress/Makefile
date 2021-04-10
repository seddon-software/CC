CC := gcc
WARNINGS := -Wall
CFLAGS := -g $(WARNINGS) -std=c11 -pthread 
SOURCES := $(wildcard *.c)
EXECUTABLES := $(SOURCES:.c=.exe)


all.exe: $(EXECUTABLES)


$(EXECUTABLES): %.exe: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)



clean:
	-rm -f *.o
	-rm -f *.exe
	
	
