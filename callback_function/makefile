CC = gcc
CFLAGS = -g -Wall
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s

BINS = callback

all: $(BINS)

%:%.c
	$(CC) $(CFLAGS) $< -o $@

do:
	./$(BINS)

check:
	$(CHECKCC) $(CHECKFLAGS) ./$(BINS)

clean:
	rm $(BINS) $(OBJS)
