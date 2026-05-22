SRCMODULES = src/config.c src/math.c src/files/file_searching.c
OBJMODULES = $(SRCMODULES:.c=.o) 


CC = gcc
CFLAGS = -g -Wall

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

prog: src/main.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -o bin/app
