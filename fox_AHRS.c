/*
 * File: main.c
 * Autor: Federico LOlli
 *  *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * @author Federico Lolli <federicololli@hotmail.com>
 * @version 0.1
 * @date 21/01/2011
 *
 * Model version                        : 0.1
 * C/C++ source on      	        : 11 03 2011
 *
 * 
 * 
 * 
 * 
 */


#include<math.h>
#include <time.h>
#include <errno.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h> 
#include <termios.h> 
#include <sys/ioctl.h>
#include <stdlib.h>

#include "IMU/iduec.h"
#include "IMU/daisysette.h"

#include "IMU/global_sensor.h"
#include "comunication_descriptor_data.h"
#include "udpsocketlib.h"
#include "globaldata.h"
#include "config/loadconf.h"

/*kalman*/
#include "kalman/EKF.h"              /* Model's header file */
#include "kalman/EKF_private.h"
#include "kalman/rtwtypes.h"  
#include "lpf/lpf0.h"                      /* Model's header file */
#include "lpf/rtwtypes.h" 
/*gps*/
#include "gps/gps.h"
#include"seriallib.h"

void sighandlersigterm(int sig);

clock_t BeginTimer();

int crccal(data_AHRS_Struct a);
/*global data*/
load_data_struct load_data;

     
int main(int argc, char *argv[])
{ 

  /*************load global data*****************/
  load_data=load_configuration();
  /*end load data*/
  char ethconfig_comand[30]="ifconfig eth0 ";
  char serial_port_send[30]="";
  strcpy(serial_port_send, load_data.serial_port);
  printf("inizialize control serial port send  %s \n",serial_port_send);
  printf("inizialize control gadget serial port send  %s \n",GADGETPORT);

  strcpy(ip_dest_addrs, load_data.ip_dest_addrs);
  printf("inizialize control ip dest %s \n",ip_dest_addrs);
  strcpy(ip_local_addrs, load_data.ip_local_addrs);
  printf("inizialize control ip local %s \n",ip_local_addrs);
  strcpy(imu_port, load_data.imu_port);
  printf("inizialize control imu port %s \n",imu_port);
  strcpy(gps_port, load_data.gps_port);
  printf("inizialize control gps port %s \n",gps_port);
  //configuro il sitema
  strcat(ethconfig_comand,ip_local_addrs);
  printf("execute command: %s \n",ethconfig_comand);
  system(ethconfig_comand);
  printf("configure gadget\n");
  system("modprobe g_serial");

  //time
  double elapTicks,elapTicks_prec, deltatime;
  //tempo inizio processo
  double elapTicks_init=BeginTimer();
  //dati comunicazione
  data_AHRS_Struct send ;//data to send
  memset(&send,0,sizeof(send));
  NavInputs_t gpsData1;
  int cnt_gps=0;
  int cnt_baro=0;
  int statusbaro=0; 
  int update_tmp_cnt=0;
  float tmp_altitude=0,altitude=0;
  //float degtorad=0.017453292;
  /*global data and inizializzation*/
  /*inizialize kalman*/
  /* Initialize model */
  EKF_initialize();
  lpf0_initialize();
 
  EKF_U.deviazione_std_accell=load_data.dev_std_accell;
  EKF_U.deviazione_std_magneto=load_data.dev_std_mag;
  EKF_U.dt=load_data.kalman_delta_time;
  EKF_U.Q_quat[0]=load_data.Q_quat0;
  EKF_U.Q_quat[1]=load_data.Q_quat1;
  EKF_U.Q_quat[2]=load_data.Q_quat2;
  EKF_U.Q_quat[3]=load_data.Q_quat3;

  EKF_U.Q_bias[0]=load_data.KQ_bias0;
  EKF_U.Q_bias[1]=load_data.KQ_bias1;
  EKF_U.Q_bias[2]=load_data.KQ_bias2;
  EKF_U.GPS_Reset=1;

  EKF_U.Accel_Cal[0]=load_data.ACC11;
  EKF_U.Accel_Cal[1]=load_data.ACC12;
  EKF_U.Accel_Cal[2]=load_data.ACC13;
  EKF_U.Accel_Cal[3]=load_data.ACC21;
  EKF_U.Accel_Cal[4]=load_data.ACC22;
  EKF_U.Accel_Cal[5]=load_data.ACC23;
  EKF_U.Accel_Cal[6]=load_data.ACC31;
  EKF_U.Accel_Cal[7]=load_data.ACC32;
  EKF_U.Accel_Cal[8]=load_data.ACC33;
  EKF_U.Accel_Cal[9]=load_data.ACC10;
  EKF_U.Accel_Cal[10]=load_data.ACC20;
  EKF_U.Accel_Cal[11]=load_data.ACC30;

  EKF_U.Mag_Cal[0]=load_data.MAG11;
  EKF_U.Mag_Cal[1]=load_data.MAG12;
  EKF_U.Mag_Cal[2]=load_data.MAG13;
  EKF_U.Mag_Cal[3]=load_data.MAG21;
  EKF_U.Mag_Cal[4]=load_data.MAG22;
  EKF_U.Mag_Cal[5]=load_data.MAG23;
  EKF_U.Mag_Cal[6]=load_data.MAG31;
  EKF_U.Mag_Cal[7]=load_data.MAG32;
  EKF_U.Mag_Cal[8]=load_data.MAG33;
  EKF_U.Mag_Cal[9]=load_data.MAG10;
  EKF_U.Mag_Cal[10]=load_data.MAG20;
  EKF_U.Mag_Cal[11]=load_data.MAG30;

  EKF_U.Gyro_Cal[0]=load_data.GYRO10;
  EKF_U.Gyro_Cal[1]=load_data.GYRO20;
  EKF_U.Gyro_Cal[2]=load_data.GYRO30;

  printf("open serial port send \n");
  fd_serial_send=open_serial_port_com(serial_port_send,(int)load_data.serial_port_badu);
  if( fd_serial_send<0)
	{
	printf("error to open send serial port\n");
	}
  printf("open serial gadget port send \n");
  fd_serial_gadget=open_serial_port_com(GADGETPORT, 115200);
  if( fd_serial_send<0)
	{
	printf("error to open send serial gadget port\n");
	}


/*fine inizializzazione kalman*/
  datasensincomp datasensor;
  /*opendevice esterni*/
  /*apertura i2c*/
  if((int)load_data.imu_type==1){fd_iduec=openi2c();}
  if((int)load_data.enable_GPS>0){
	fd_gps= open_gps(gps_port,load_data.badu_gps);
	}
 //create soket udp stream
   if ((sk = create_udp_server (ip_local_addrs, (int)load_data.internal_port)) == 0)
   {
      fprintf (stderr, "cannot open server socket\n");
      //exit (EXIT_FAILURE);
   }
   set_d7_initialize(fd_iduec);

  /*collego il segnale di terminazione*/
  signal(SIGTERM,sighandlersigterm);

 /*ciclo principale*/
 while (1) {
	/*global udp*/

	/*****************time************************/
    	elapTicks = (BeginTimer()-elapTicks_init)/time_divisor_clk;
	if(elapTicks<=elapTicks_prec)
		{
		elapTicks=elapTicks_prec+fake_deltat;
		}
	deltatime=elapTicks-elapTicks_prec;
	elapTicks_prec=elapTicks;

	if((int)load_data.debug_mode==1)	{printf("time %f deltatime %f \n ",elapTicks,deltatime);}

	/*****************************GPS enable*********************************/
	if((int)load_data.enable_GPS==1)
	{
		cnt_gps ++;
		if(cnt_gps>GPSTIMEOUTCOUNT)
		{
			cnt_gps=0;
			send.gps=1;
			if(getUserPosition(fd_gps)<0)//salva i dati in varibile globale gpsData
			{printf("parser nemea string problem");}
			gpsData1=read_nav_data();
		}		
	}
	if((int)load_data.enable_GPS==0)
	{//fake gps		
		gpsData1.lat=LATITUDINE_FAKE ;
		gpsData1.lon=LONGITUDINE_FAKE;
		gpsData1.heigth=ALTITUDINE_FAKE;
		gpsData1.speed=0.0;
		gpsData1.gpsFixQuality=0;
		send.gps=0;
	}
	if(gpsData1.lat==0||gpsData1.lon==0)
	{
		gpsData1.lat=LATITUDINE_FAKE ;
		gpsData1.lon=LONGITUDINE_FAKE;
		gpsData1.heigth=ALTITUDINE_FAKE;
		gpsData1.speed=0.0;
		gpsData1.gpsFixQuality=0;
		send.gps=0;
	}
	send.latitude=gpsData1.lat;
	send.longitude=gpsData1.lon;
	send.vel_gps=gpsData1.speed;
	send.altitudine=gpsData1.heigth;
	send.gps=gpsData1.gpsFixQuality;
	if((int)load_data.debug_mode==1)
	{
	printf("lat %f lon %f vel %f  altitude %f \n",send.latitude,send.longitude,send.vel_gps,send.altitudine);
	}
	//aggiornamento altitudine
	cnt_baro ++;
	if(cnt_baro>TMP_PRESS_TIMEOUTCOUNT)
	{
		cnt_baro=0;
		tmp_altitude=readaltitude_press(fd_iduec ,statusbaro);

		if((int)load_data.debug_mode==1)
		{
			printf("altitude %f \n",altitude);
		}
		statusbaro ++;
		if(statusbaro>3){statusbaro=0;}

		
	}	
	if(tmp_altitude>-500){altitude=tmp_altitude;}	
	send.altitudine=altitude;
	/******************IMU D7*************************/
	if((int)load_data.imu_type==1)
	{
		//acquisisco dati inerziali da i2c
		datasensor = myupdatesensor(fd_iduec);
		/*aggiorno filtro passabasso*/
		lpf0_U.acc_x=datasensor.acc_X[0];
		lpf0_U.acc_y=datasensor.acc_Y[0];
		lpf0_U.acc_z=datasensor.acc_Z[0];
		lpf0_U.gyro_x=datasensor.gyro_X[0]/(75*DegToRadIMU);
		lpf0_U.gyro_y=datasensor.gyro_Y[0]/(75*DegToRadIMU);
		lpf0_U.gyro_z=datasensor.gyro_Z[0]/(75*DegToRadIMU);
		lpf0_U.mag_x=datasensor.mag_X[0];
		lpf0_U.mag_y=datasensor.mag_Y[0];
		lpf0_U.mag_z=datasensor.mag_Z[0];
		  /* Step the model */
 		 lpf0_step();
		/*aggiorno filtro passabasso*/
		lpf0_U.acc_x=datasensor.acc_X[1];
		lpf0_U.acc_y=datasensor.acc_Y[1];
		lpf0_U.acc_z=datasensor.acc_Z[1];
		lpf0_U.gyro_x=datasensor.gyro_X[1]/(75*DegToRadIMU);
		lpf0_U.gyro_y=datasensor.gyro_Y[1]/(75*DegToRadIMU);
		lpf0_U.gyro_z=datasensor.gyro_Z[1]/(75*DegToRadIMU);
		lpf0_U.mag_x=datasensor.mag_X[1];
		lpf0_U.mag_y=datasensor.mag_Y[1];
		lpf0_U.mag_z=datasensor.mag_Z[1];
		  /* Step the model */
 		 lpf0_step();
		/*aggiorno filtro passabasso*/
		lpf0_U.acc_x=datasensor.acc_X[2];
		lpf0_U.acc_y=datasensor.acc_Y[2];
		lpf0_U.acc_z=datasensor.acc_Z[2];
		lpf0_U.gyro_x=datasensor.gyro_X[2]/(75*DegToRadIMU);
		lpf0_U.gyro_y=datasensor.gyro_Y[2]/(75*DegToRadIMU);
		lpf0_U.gyro_z=datasensor.gyro_Z[2]/(75*DegToRadIMU);
		lpf0_U.mag_x=datasensor.mag_X[2];
		lpf0_U.mag_y=datasensor.mag_Y[2];
		lpf0_U.mag_z=datasensor.mag_Z[2];
		  /* Step the model */
 		 lpf0_step();
			if((int)load_data.debug_mode==1)
			{
		  	printf("acc0: %f %f %f mag0: %f %f %f gyro0: %f %f %f \n",
				datasensor.acc_X[0],datasensor.acc_Y[0],datasensor.acc_Z[0],
				 datasensor.mag_X[0],datasensor.mag_Y[0],datasensor.mag_Z[0],
				datasensor.gyro_X[0],datasensor.gyro_Y[0],datasensor.gyro_Z[0]);
		  	printf("acc1: %f %f %f mag1: %f %f %f gyro1: %f %f %f \n",
				datasensor.acc_X[1],datasensor.acc_Y[1],datasensor.acc_Z[1],
				 datasensor.mag_X[1],datasensor.mag_Y[1],datasensor.mag_Z[1],
				datasensor.gyro_X[1],datasensor.gyro_Y[1],datasensor.gyro_Z[1]);
		  	printf("acc2: %f %f %f mag2: %f %f %f gyro2: %f %f %f \n",
				datasensor.acc_X[2],datasensor.acc_Y[2],datasensor.acc_Z[2],
				 datasensor.mag_X[2],datasensor.mag_Y[2],datasensor.mag_Z[2],
				datasensor.gyro_X[2],datasensor.gyro_Y[2],datasensor.gyro_Z[2]);
		  	printf("accf: %f %f %f magf: %f %f %f gyrof: %f %f %f \n",
				lpf0_Y.acc_x_f,lpf0_Y.acc_y_f,lpf0_Y.acc_z_f,lpf0_Y.mag_x_f,lpf0_Y.mag_y_f,lpf0_Y.mag_z_f,
				lpf0_Y.gyro_x_f,lpf0_Y.gyro_y_f,lpf0_Y.gyro_z_f);
			set_d7_debug_mode(1);
			}

		if((int)load_data.kalman_enable==1)
		{
			/*input kalman*/
			EKF_U.latlonalti[0]=gpsData1.lat;//latitudine
			EKF_U.latlonalti[1]=gpsData1.lon;//longitudine
			EKF_U.latlonalti[2]=gpsData1.heigth;
			EKF_U.accell[0]=lpf0_Y.acc_x_f;
			EKF_U.accell[1]=lpf0_Y.acc_y_f;
			EKF_U.accell[2]=lpf0_Y.acc_z_f;
			EKF_U.mag[0]=lpf0_Y.mag_x_f;
			EKF_U.mag[1]=lpf0_Y.mag_y_f;
			EKF_U.mag[2]=lpf0_Y.mag_z_f;
			//i gyro devono essere trasformati in radianti
			EKF_U.gyro[0]=lpf0_Y.gyro_x_f*DegToRadIMU;
			EKF_U.gyro[1]=lpf0_Y.gyro_y_f*DegToRadIMU;
			EKF_U.gyro[2]=lpf0_Y.gyro_z_f*DegToRadIMU;
			EKF_U.tau=load_data.tau_comp_filter;

			if(deltatime>0.01&&deltatime<0.06)
			{
  		 	 	EKF_U.dt=(float)deltatime;
			}else
			{
		 		 EKF_U.dt=fake_deltat;
			}
			/*step the kalman*/
			EKF_step();
			/*otput*/
			send.roll=(double)EKF_Y.eulero[0];
			send.pitch=(double)EKF_Y.eulero[1];
			send.yaw=(double)EKF_Y.eulero[2];
			//caso in cui sia negativo lo converto 0-360
			if(send.yaw<0)
			{
		 	 send.yaw= 360 + send.yaw;
			}
			//debug controllo dati filtrati
			if((int)load_data.debug_mode==1)
			{
			  	printf("kalman roll: %f kalman pitch: %f kalman yaw: %f \n",send.roll,send.pitch,send.yaw );
			}
			send.gyro_X=(double)EKF_Y.pqr[0];
			send.gyro_Y=(double)EKF_Y.pqr[1];
			send.gyro_Z=(double)EKF_Y.pqr[2];
			send.q1=(double)EKF_Y.quaternioni[0];
			send.q2=(double)EKF_Y.quaternioni[1];
			send.q3=(double)EKF_Y.quaternioni[2];
			send.q4=(double)EKF_Y.quaternioni[3];
			send.q1_dot=(double)EKF_Y.quat_dot[0];
			send.q2_dot=(double)EKF_Y.quat_dot[1];
			send.q3_dot=(double)EKF_Y.quat_dot[2];
			send.q4_dot=(double)EKF_Y.quat_dot[3];
		}
		/*slow for debug*/
		if((int)load_data.debug_mode==1){sleep(1);}
		/*cpy accel data*/
		//deg/sec
		if((int)load_data.imu_type!=1)
		{
			send.gyro_X=(double)lpf0_Y.gyro_x_f;
			send.gyro_Y=(double)lpf0_Y.gyro_y_f;
			send.gyro_Z=(double)lpf0_Y.gyro_z_f;
		}
		send.Acc_X=(double)lpf0_Y.acc_x_f;
		send.Acc_Y=(double)lpf0_Y.acc_y_f;
		send.Acc_Z=(double)lpf0_Y.acc_z_f;
		send.mag_X=(double)lpf0_Y.mag_x_f;
		send.mag_Y=(double)lpf0_Y.mag_y_f;
		send.mag_Z=(double)lpf0_Y.mag_z_f;

		update_tmp_cnt ++;
		if(update_tmp_cnt>TMP_PRESS_TIMEOUTCOUNT)
		{	
			update_tmp_cnt=0;
			send.temperature=readtemp( fd_iduec);
			send.static_pressure=1;
		}
		send.tic=elapTicks;
		send.id_dispositivo=load_data.ID;
		send.number_of_packet ++;
		send.end='*';
		send.init='#';
		send.init1='s';
		send.init2='n';
		send.init3='y';
		send.vel_X=0;
		send.vel_Y=0;
		send.vel_Z=0;
		send.crc=crccal(send);
		usleep(200);

	}
	if(sk>=0)
	{
		udp_send (sk, send, ip_dest_addrs, (int)load_data.destination_port);
		udp_send (sk, send,"127.0.0.1", INTERNALUSEPORT);
	}
	if(fd_serial_send>=0){serial_send (fd_serial_send,send);}
	if(fd_serial_gadget>=0){serial_send (fd_serial_gadget,send);}
	}//end main loop

  /*device close*/
  //chiudo i device aperti
  //close udp
  close_udp_socket (sk);
  EKF_terminate();
  lpf0_terminate();

  if((int)load_data.imu_type==1)
	{closei2c(fd_iduec);}
  if((int)load_data.enable_GPS !=0)
  	{close_gps(fd_gps);}
  if(fd_serial_send>=0){close (fd_serial_send);}
  if(fd_serial_gadget>=0){close (fd_serial_gadget);}

  return 0;
}

/*signal*/
void sighandlersigterm(int sig)
{

	close_udp_socket (sk);
	EKF_terminate();
	lpf0_terminate();
	if((int)load_data.imu_type==1)
	{closei2c(fd_iduec);}
	if((int)load_data.enable_GPS !=0)
	{close_gps(fd_gps);}
	if(fd_serial_send>=0){close (fd_serial_send);}
	if(fd_serial_gadget>=0){close (fd_serial_gadget);}
	exit(1);
}

/*timer*/
clock_t BeginTimer()
{
    //timer declaration
    clock_t Begin; //initialize Begin
    Begin = clock() ; //start the timer
    return Begin;
}

int crccal(data_AHRS_Struct a)
{
 /*int ret=(int)(a.latitude +  a.longitude +a.vel_gps + a.altitudine +a.roll+a.pitch +	a.yaw + a.q1 + a.q2 + a.q3 +
	a.q4 + 	a.Acc_X + a.Acc_Y + a.Acc_Z + a.gyro_X + a.gyro_Y + a.gyro_Z +	a.mag_X + a.mag_Y + a.mag_Z +
	a.static_pressure + a.tic + a.temperature + a.gps + a.satellite_number + a.number_of_packet +  a.id_dispositivo);*/
 int ret=1;

return ret;
}





