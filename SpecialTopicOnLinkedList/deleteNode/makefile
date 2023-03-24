CC = gcc
CFLAGS = -g -Wall
OBJS = list.o
BINS = main
CHECKCC = valgrind
CHECKFLAGS = --leak-check=full -s --show-leak-kinds=all --track-origins=yes 


all: $(BINS)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BINS): main.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

debug:
	$(CHECKCC) $(CHECKFLAGS) ./main


clean:
	rm $(BINS) $(OBJS)