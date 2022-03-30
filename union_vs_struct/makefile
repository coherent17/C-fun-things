CC = gcc
CFLAGS = -g -Wall

BINS = test_union

all: $(BINS)

%:%.c
	$(CC) $(CFLAGS) $< -o $@

do:
	./$(BINS)


clean:
	rm $(BINS) $(OBJS)