CC = gcc
CFLAGS = -g -Wall

BINS = donut

all: $(BINS)

%:%.c
	$(CC) $(CFLAGS) $< -o $@ -lm

do:
	./$(BINS)

clean:
	rm $(BINS) $(OBJS)