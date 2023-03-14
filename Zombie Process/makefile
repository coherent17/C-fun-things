CC = gcc
CFLAGS = -g -Wall

BINS = zombie

all: $(BINS)

%:%.c
	$(CC) $(CFLAGS) $< -o $@

do:
	./$(BINS)

clean:
	rm $(BINS) $(OBJS)