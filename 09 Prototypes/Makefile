CC := gcc
WARNINGS := -Wall
CFLAGS := -g -O0 $(WARNINGS) -std=c11
SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)



all: Main.exe

Main.exe: $(OBJECTS)
	$(CC) $(OBJECTS) -o $@
	mv Main.exe all.exe
	
$(OBJECTS): %.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	-rm -f *.o
	-rm -f *.exe
	
print:
	@echo SOURCES= $(SOURCES)
	@echo OBJECTS= $(OBJECTS)
	@ls -l
	
