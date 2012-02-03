#CC =arm-linux-gnueabi-gcc
CC=g++
LFLAGS=-lrt
OBJSTATIC=udpsocketlib.o seriallib.o
OBJSTATICKALMAN=kalman/EKF.o kalman/EKF_data.o kalman/rt_backsubrr_dbl.o kalman/rt_forwardsubrr_dbl.o kalman/rtGetInf.o kalman/rtGetNaN.o kalman/rt_lu_real.o kalman/rt_matdivrr_dbl.o kalman/rt_matrixlib_dbl.o kalman/rt_nonfinite.o
OBJSTATICIMU=IMU/iduec.o IMU/daisysette.o
OBJSTATICGPS=gps/gps.o gps/nmeap01.o
OBJSTATICONFIG= config/loadconf.o
OBJSTATICCALACCMAG=cal_acc_mag/calibrazione_acc_mag0_data.o cal_acc_mag/calibrazione_acc_mag0.o cal_acc_mag/rtGetInf.o cal_acc_mag/rtGetNaN.o cal_acc_mag/rt_nonfinite.o
OBJSTATICLPF=lpf/lpf0_data.o lpf/lpf0.o
CFLAGS =-I. -g -Wall -Wunused -lm -lncurses -lconfig++ -O2

SUBDIRS = 	IMU \
		lpf \
		gps \
		cal_acc_mag \
		config \
		kalman

all: dire static fox_AHRS fox_AHRS_calib

dire:	
	list='$(SUBDIRS)'; \
	for subdir in $$list; do \
	  (cd $$subdir && $(MAKE)); \
	done

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS)  -c -o $@ $< 

fox_AHRS: fox_AHRS.c 
	$(CC) $(CFLAGS) $(LFLAGS)  $(OBJSTATIC) $(OBJSTATICKALMAN) $(OBJSTATICIMU) $(OBJSTATICLPF) $(OBJSTATICONFIG) $(OBJSTATICGPS) fox_AHRS.c -o  fox_AHRS

fox_AHRS_calib: fox_AHRS_calib.c
	$(CC) $(CFLAGS) $(LFLAGS)  $(OBJSTATIC) $(OBJSTATICIMU) $(OBJSTATICONFIG) $(OBJSTATICGPS) $(OBJSTATICCALACCMAG) fox_AHRS_calib.c -o  fox_AHRS_calib

static: $(OBJSTATIC)
	ar rcs fox_AHRS.a $^
	
clean: 
	rm -f fox_AHRS
	rm -f fox_AHRS_calib
	rm -f *.o
	rm -f fox_AHRS.a
	rm -f libfox_AHRS.a
	rm -f libfox_AHRS.so
	list='$(SUBDIRS)'; \
	for subdir in $$list; do \
	  (cd $$subdir && $(MAKE) clean); \
	done
