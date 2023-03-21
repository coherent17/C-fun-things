CC = gcc
CFLAGS = -g -Wall
BINS = librarytest libmycode.so runtime_librarytest libmystaticcode.a static_librarytest

all: $(BINS)

libmycode.o: libmycode.c mycode.h
	$(CC) $(CFLAGS) -c libmycode.c

librarytest: librarytest.c libmycode.o
	$(CC) $(CFLAGS) $^ -o $@

#share object (dynamic linked) dll file on windows
#load when program runs
#-fPIC Position-Independent Code
#-shared make a shared library
libmycode.so: libmycode.c mycode.h
	$(CC) $(CFLAGS) -fPIC -shared libmycode.c -o $@ -lc

# r - replace
# c - create
# s - index
# bundle up to the static library
libmystaticcode.a: libmycode.o
	ar rcs libmystaticcode.a libmycode.o

#-L . tell compiler to look into the current directory for library
#-lmycode link the program with libmycode
# -l is abbrv of -lib, ex -lc -> (libc) -lmycode (libmycode)
runtime_librarytest: librarytest.c
	$(CC) $(CFLAGS) $^ -L. -o $@ -lmycode

#can't find library find library by adding it to the LD_LIBRARY_PATH environment variable
#tells the loader where to find the library, idiot method
run:
	LD_LIBRARY_PATH="/uhome/home/coherent17/C-fun-things/Library;$LD_LIBRARY_PATH" ./runtime_librarytest abc


# result
# objdump -t librarytest | grep reverse
# 0000000000400591 g     F .text  0000000000000090              reverse
# objdump -t runtime_librarytest | grep reverse
# 0000000000000000       F *UND*  0000000000000000              reverse

compare_objdump:
	objdump -t librarytest | grep reverse
	objdump -t runtime_librarytest | grep reverse

static_librarytest: librarytest.c
	$(CC) $(CFLAGS) $^ -L. -o $@ -lmystaticcode

clean:
	rm *.o $(BINS) *.so