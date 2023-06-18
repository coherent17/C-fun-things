CC = gcc
CFLAGS = -g -Wall
BIN = pthread

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lpthread

clean:
	rm -rf $(BIN)