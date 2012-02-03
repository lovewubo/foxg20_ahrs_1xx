#CC=arm-linux-gnueabi-g++
CC=g++
CFLAGS=-I. -Wall -O2
LFLAGS=-lrt

OBJSTATIC = lpf0_data.o lpf0.o 

all: static 

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

static: $(OBJSTATIC)
	ar rcs liblpf.a $^

clean:
	rm -f *.o
	rm -f liblpf.a
	rm -f liblpf.so
