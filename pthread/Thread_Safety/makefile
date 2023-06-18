CC = gcc
CFLAGS = -g -Wall
BIN = pthread1 pthread2 mutex

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@ -lpthread

clean:
	rm -rf $(BIN)