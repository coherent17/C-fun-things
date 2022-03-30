CC = gcc
CFLAGS = -g -Wall

BINS = enum

all: $(BINS)

%:%.c
	$(CC) $(CFLAGS) $< -o $@

do:
	./$(BINS)


clean:
	rm $(BINS) $(OBJS)