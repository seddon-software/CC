CC := clang
WARNINGS := -Wall
CFLAGS := -g -O0 $(WARNINGS) -std=c11 -pthread 
SOURCES := $(wildcard *.c)
OBJECTS := $(SOURCES:.c=.o)



all: Problems.exe

Problems.exe: $(OBJECTS)
	@echo $(CC) $? -o $@
	$(CC) $? -o $@
	
$(OBJECTS): %.o: %.c
	@echo $(CC) -c $(CFLAGS) $<
	$(CC) -c $(CFLAGS) $<

clean:
	-rm -f *.o
	-rm -f *.exe
	-rm -r *.exe.dSYM
	
print:
	@echo SOURCES= $(SOURCES)
	@echo OBJECTS= $(OBJECTS)
	@ls -l
	