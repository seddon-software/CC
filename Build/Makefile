# Important gcc flags are discussed at:
#		https://www.linuxfordevices.com/tutorials/linux/important-gcc-flags

CC := gcc
WARNINGS := -Wall
CFLAGS := -g -O0 $(WARNINGS) -std=c11 
SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)
FLAGS := -save-temps	# save intermediate file
#FLAGS := -E				# preprocessor only

all: all.exe

%.o: %.c
	$(CC) -c $(FLAGS) $<

all.exe: $(OBJECTS)
	@echo $(F_SOURCES)
	@echo $($<)
	@echo $($?)
	$(CC) $(FLAGS) $(CFLAGS) $? -o $@

clean:
	rm *.o *.i *.s *.exe