CC = gcc
CFLAGS = -g -Wall
BIN = print_int

all: $(BIN)

%:%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(BIN)