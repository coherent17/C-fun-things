CC = gcc
CFLAGS = -g -Wall

BINS = main

all: $(BINS)

%:%.c
	$(CC) $(CFLAGS) $< -o $@ -lpthread -lrt

do:
	./$(BINS)

clean:
	rm $(BINS) $(OBJS)