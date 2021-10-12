CC = gcc
CFLAGS = -g -Wall
OBJ = byrow bycol

all: $(OBJ)

%: %.c
	$(CC) $(CFLAGS) $< -o $@

#evaluate the time of the two kinds of program
time: $(OBJ)
	time ./byrow
	time ./bycol

clean:
	rm $(OBJ)