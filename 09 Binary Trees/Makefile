CC := gcc
WARNINGS := -Wall
CFLAGS := -g -O0 $(WARNINGS) -std=c11
SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)



all: all.exe

all.exe: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	
$(OBJECTS): %.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	-rm -f *.o
	-rm -f *.exe
	
print:
	@echo SOURCES= $(SOURCES)
	@echo OBJECTS= $(OBJECTS)
	@ls -l
	
