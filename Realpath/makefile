CC = gcc
CFLAGS = -g -Wall

BINS = main

all: $(BINS)

%:%.c
	$(CC) $(CFLAGS) $< -o $@

do:
	./$(BINS)

clean:
	rm $(BINS) $(OBJS)