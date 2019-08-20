CC := clang
WARNINGS := -Wall
CFLAGS := -g -O0 $(WARNINGS) -std=c11 -pthread 
SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)



all: Main.exe

Main.exe: $(OBJECTS)
	$(CC) $? -o $@
	
$(OBJECTS): %.o: %.c
	$(CC) -c $(CFLAGS) $<

clean:
	-rm -f *.o
	-rm -f *.exe
	-rm -r *.exe.dSYM
	
print:
	@echo SOURCES= $(SOURCES)
	@echo OBJECTS= $(OBJECTS)
	@ls -l
	