CC = gcc
CFLAGS = -g -Wall
BINS = uuid
LINKER = -luuid

all: $(BINS)

%:%.c
	$(CC) $(CFLAGS) $< -o $@ $(LINKER)

do:
	./$(BINS)


clean:
	rm $(BINS) $(OBJS)