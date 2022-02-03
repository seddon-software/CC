# https://www.gnu.org/software/make/manual/

CC := gcc
WARNINGS := -Wall
CFLAGS := -g -O0 $(WARNINGS) -std=c11 
F_SOURCES := $(wildcard f*.c)
G_SOURCES := $(wildcard g*.c)
F_OBJECTS := $(F_SOURCES:.c=.o)
G_OBJECTS := $(G_SOURCES:.c=.o)


all: f.exe g.exe
	
f.exe: $(F_OBJECTS)
	$(CC) $(CFLAGS) $? -o $@

g.exe: $(G_OBJECTS)
	$(CC) $(CFLAGS) $? -o $@

$(F_OBJECTS): f%.o: f%.c
	$(CC) $(CFLAGS) $? -c

$(G_OBJECTS): g%.o: g%.c
	$(CC) $(CFLAGS) $? -c

run: all
	f.exe
	g.exe
	
clean:
	-rm -f *.o
	-rm -f *.exe
	
	
print:
	@echo $(F_SOURCES)
	@echo $(G_SOURCES)
	@echo $(F_OBJECTS)
	@echo $(G_OBJECTS)
	