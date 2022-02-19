CC = gcc
CFLAGS = -g -Wall
BIN = ProgressBar

all: $(BIN)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(BIN)