#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP     //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=400000)
#USE  I2C(MASTER,SLOW,SDA=PIN_c4,SCL=PIN_c3)
#include <i2c_flex_lcd.c>

#define MENU   input(PIN_A0)
#define TANG   input(PIN_A1)
#define  GIAM   input(PIN_A2)
#define SENSOR input(PIN_A4)
