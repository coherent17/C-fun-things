CC = gcc
CFLAGS = -g -Wall
BINS = libplus1.so libplus2.so test.elf

all: $(BINS)

%.so: %.c
	$(CC) $(CFLAGS) -fPIC -shared $^ -o $@

# link libdl
%.elf: %.c
	$(CC) $(CFLAGS) $^ -o $@ -ldl

do:
	./test.elf ./libplus1.so 3
	./test.elf ./libplus2.so 3

clean:
	rm $(BINS)