CC = gcc
CFLAGS = -g -Wall

BINS = abort assert

all: $(BINS)

%:%.c
	$(CC) $(CFLAGS) $< -DNDEBUG -o $@

clean:
	rm $(BINS) $(OBJS)