#CC=arm-linux-gnueabi-g++
CC=g++
CFLAGS=-I. -Wall -O2
LFLAGS=-lrt

OBJSTATIC = EKF.o EKF_data.o rt_backsubrr_dbl.o rt_forwardsubrr_dbl.o rtGetInf.o rtGetNaN.o rt_lu_real.o rt_matdivrr_dbl.o rt_matrixlib_dbl.o rt_nonfinite.o


all: static 

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

static: $(OBJSTATIC)
	ar rcs libdiiamicskm.a $^

clean:
	rm -f *.o
	rm -f libdiiamicskm.a
	rm -f libdiiamicskm.so
