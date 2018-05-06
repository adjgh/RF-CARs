#include <stc89c5xrc.h>
#include <string.h>
#include "NRF24L01_drv.h"

sbit right_wheel_back = P1^0;
sbit right_wheel_go = P1^1;
sbit left_wheel_back = P1^2;
sbit left_wheel_go = P1^3;

unsigned char count = 0x0;

bit f_go    = 0;
bit f_back  = 0;
bit f_left  = 0;
bit f_right = 0;
bit f_stop  = 0;
bit f_last  = 0;
bit f_sstop = 0;
bit f_next  = 0;
bit direct  = 0;

void go(void);

void back(void);

void left(void);

void right(void);

void stop(void);

void last(void);

void next(void);

void init_speaker(void);

int main(void)
{
  unsigned char rec = 0x0,status = 0x0;
  init_NRF24L01_B();
  SetRX_Mode_B();
  init_speaker();
  while(1)
 {
   status = SPI_Read_B(STATUS);
   if (status == 0x40)
{
   SPI_RW_Reg_B(WRITE_REG + STATUS,0x0);
   rec = SPI_Read_B(RD_RX_PLOAD);//Çå¼Ä´æÆ÷
   SPI_RW_Reg_B(FLUSH_RX,0);
   switch (rec)
  {
    case 0x1:{
	          f_go = 1;
	          f_back = 0;
			  f_left  = 0;
              f_right = 0;
              f_stop  = 0;
			  break;
			 }
	case 0x2:{
	          f_go = 0;
	          f_back = 1;
			  f_left  = 0;
              f_right = 0;
              f_stop  = 0;
			  break;
			 }
	case 0x3:{
	          f_go = 0;
	          f_back = 0;
			  f_left  = 1;
              f_right = 0;
              f_stop  = 0;
			  break;
			 }
	case 0x4:{
	          f_go = 0;
	          f_back = 0;
			  f_left  = 0;
              f_right = 1;
              f_stop  = 0;
			  break;
			 }
	case 0x5:{
	          f_go = 0;
	          f_back = 0;
			  f_left  = 0;
              f_right = 0;
              f_stop  = 1;
			  break;
			 }
	case 0x6:f_last  = 1;break;
	case 0x7:f_sstop = 1;break;
	case 0x8:f_next  = 1;break;
}
   rec = 0x0; 
 }
  if(f_go)
   	go();
  if(f_back)
	back();
  if(f_left)
	left();
  if(f_right)
   right();
  if(f_stop)
  	stop();
  if (f_last)
 {
   last();
   count--;
   f_last = 0;
 }
  if (f_sstop)
 {
   init_speaker();
   f_sstop = 0;
 }
  if (f_next)
{
   next();
   f_next = 0;
   count++;
}	
 }
}

void go(void)
{
 direct = 0;
 right_wheel_back = 0;
 right_wheel_go   = 1;
 left_wheel_back  = 0;
 left_wheel_go    = 1;
}

void back(void)
{
 direct = 1;
 right_wheel_back = 1;
 right_wheel_go   = 0;
 left_wheel_back  = 1;
 left_wheel_go    = 0;
} 

void left(void)
{
 if (direct == 0)
{
 right_wheel_back = 0;
 right_wheel_go   = 1;
 left_wheel_back  = 1;
 left_wheel_go    = 0;
}
 else 
{
 right_wheel_back = 1;
 right_wheel_go   = 0;
 left_wheel_back  = 0;
 left_wheel_go    = 1; 
}
}

void right(void)
{
 if (direct == 0)
{
 right_wheel_back = 1;
 right_wheel_go   = 0;
 left_wheel_back  = 0;
 left_wheel_go    = 1; 
}
 else
 {
   right_wheel_back = 0;
   right_wheel_go   = 1;
   left_wheel_back  = 1;
   left_wheel_go    = 0;
 }
}

void stop(void)
{
  P1 = 0x0;
}

void init_speaker(void)
{
  P0 = 0xff;
  count = 0x0;
}

void last(void)
{
  if (count > 0)
 { 
   switch (count)
  {
    case 0x7:P07 = 0;break;
	case 0x6:{P06 = 0;delayms(500);P07 = 1;break;}
	case 0x5:{P05 = 0;delayms(500);P06 = 1;break;}
	case 0x4:{P04 = 0;delayms(500);P05 = 1;break;}
	case 0x3:{P03 = 0;delayms(500);P04 = 1;break;}
	case 0x2:{P02 = 0;delayms(500);P03 = 1;break;}
	case 0x1:{P01 = 0;delayms(500);P02 = 1;break;}
	case 0x0:{P00 = 0;delayms(500);P01 = 1;break;}
  }
 }
   	else
		init_speaker();
}

void next(void)
{
  if (count < 0x8)
 {
   switch (count)
  {
    case 0x0:P00 = 0;break;
	case 0x1:{P00 = 1;delayms(500);P01 = 0;break;}
	case 0x2:{P01 = 1;delayms(500);P02 = 0;break;}
	case 0x3:{P02 = 1;delayms(500);P03 = 0;break;}
	case 0x4:{P03 = 1;delayms(500);P04 = 0;break;}
	case 0x5:{P04 = 1;delayms(500);P05 = 0;break;}
	case 0x6:{P05 = 1;delayms(500);P06 = 0;break;}
	case 0x7:{P06 = 1;delayms(500);P07 = 0;break;}
  }
 }
   	else
		init_speaker();
}