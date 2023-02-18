# Important gcc flags are discussed at:
#		https://www.linuxfordevices.com/tutorials/linux/important-gcc-flags

.SILENT:

CC := gcc
WARNINGS := -Wall
CFLAGS := -g -O0 $(WARNINGS) -std=c11 
SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)

all: all.exe

all.exe: $(OBJECTS)
	$(CC) $(FLAGS) $(CFLAGS) $? -o $@

clean:
	rm *.o *.i *.s *.exe
