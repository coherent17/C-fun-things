CC = gcc
CFLAGS = -g -Wall

BINS = sync async

all: $(BINS)

%:%.c
	$(CC) $(CFLAGS) $< -o $@ -lrt


clean:
	rm $(BINS) $(OBJS)