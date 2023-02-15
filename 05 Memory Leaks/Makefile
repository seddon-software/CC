WARNINGS = -Wall
CC = gcc
CFLAGS := $(CFLAGS) -ggdb -O0 $(WARNINGS) # -std=c++20
#CFLAGS = -g -O0 $(WARNINGS) -std=c++17
LFLAGS := $(LFLAGS)   
SOURCES = $(wildcard *.c)
EXECUTABLES = $(SOURCES:.c=.exe)


all:: $(EXECUTABLES)


$(EXECUTABLES): %.exe: %.c
	$(CC) $(CFLAGS) $< -o $@ $(LFLAGS)



clean::
	- rm -f *.exe
	- rm -f *.out.*
	- rm -f *.log

	
	
