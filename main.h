#include <16F877A.h>
#device ADC=10

#FUSES HS
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=4000000)
#include <lcd.h>

#use rs232(uart1,Baud=9600)//khai bao thong so cong uart

