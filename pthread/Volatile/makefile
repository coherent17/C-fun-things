CC = gcc
CFLAGS = -g -Wall -O2

BINS = main

all: $(BINS)

%:%.c
	$(CC) $(CFLAGS) $< -o $@ -lpthread

do:
	./$(BINS)

clean:
	rm $(BINS) $(OBJS)