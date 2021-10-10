CC  = gcc
CFLAGS = -g -Wall -std=c99 -D_XOPEN_SOURCE_EXTENDED
OBJS = main.o

all: main

main: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ -lncurses -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf *.o main