#include <16F877A.h>
#FUSES hs
#use delay(clock=8MHz)
#USE I2C(MASTER,SLOW,SDA=PIN_c4,SCL=PIN_c3)
#include <i2c_flex_lcd.c>
////////////CAU HINH CHAN////////////
#define RELAY  PIN_D3
#define MENU   input(PIN_C7)
#define TANG   input(PIN_C6)
#define  GIAM   input(PIN_C5)
#define SENSOR input(PIN_D2)

////////////KHAI BAO CHUONG TRINH CON////////////
void _Delay(unsigned int16 Time);
void _DemSanPham(void);
void main ()
{
 lcd_init(0x4E,16,2);
lcd_backlight_led(ON); //Enciende la luz de Fondo 
output_high(RELAY);
delay_ms(10);
  WHILE(true)
  {
      _DemSanPham();
  }
}
void _Delay(unsigned int16 Time)
{
   while(Time>1)
   {
      Time--;
      delay_ms(10);
      if(MENU==0 || TANG==0 || GIAM==0)
      {
         return;
      }
   }
}
void _DemSanPham(void)
{
   signed char SPCD =5,STCD=5,SHCD=5;//san pham cai dat, so thung cai dat
   signed char SoThung=0,SoSP=0,SoHop=0;
   char CheDo=0;
   
   while(TRUE)
   {
      while(CheDo==0)
      {
         lcd_gotoxy(1,1);//cot 1 hang 1
         printf(lcd_putc,"THUNG");
         lcd_gotoxy(9,1);//cot 1 hang 1
         printf(lcd_putc,"HOP");
         lcd_gotoxy(14,1);
         printf(lcd_putc,"SP");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%2d",SoThung);
         lcd_gotoxy(9,2);
         printf(lcd_putc,"%2d",SoHop);
         lcd_gotoxy(14,2);
         printf(lcd_putc,"%2d",SoSP);
         
         if(SENSOR==0)
         {
            output_low(RELAY);
            delay_ms(10);
            while(SENSOR==0);//chong doi phim nhan
            SoSP++;    
            if(SoSP>=SPCD)
            {
               lcd_gotoxy(1,1);//cot 1 hang 1
               printf(lcd_putc,"THUNG");
               lcd_gotoxy(9,1);//cot 1 hang 1
               printf(lcd_putc,"HOP");
               lcd_gotoxy(14,1);
               printf(lcd_putc,"SP");
               lcd_gotoxy(1,2);
               printf(lcd_putc,"%2d",SoThung);
               lcd_gotoxy(9,2);
               printf(lcd_putc,"%2d",SoHop);
               lcd_gotoxy(14,2);
               printf(lcd_putc,"%2d",SoSP);
               _Delay(10);
               SoSP=0;
               SoHop++;
               if(SoHop>=SHCD)
               {
                 _delay(20);
                  SoHop=0;
                  SoThung++;
               }
            }
         }
         else output_high(RELAY);
            delay_ms(10);
         if(MENU==0)
         {
            while(MENU==0);
            CheDo++;
            lcd_putc('\f');
            if(CheDo>3)
            {
               CheDo=0;
            }
         }
      }
      while(CheDo==1)
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc,"STCD");
         lcd_gotoxy(7,1);
         printf(lcd_putc,"SHCD");
         lcd_gotoxy(13,1);
         printf(lcd_putc,"SPCD");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%2d",STCD);
         lcd_gotoxy(7,2);
         printf(lcd_putc,"%2d",SHCD);
         lcd_gotoxy(13,2);
         printf(lcd_putc,"%2d",SPCD);
         _Delay(20);
         lcd_gotoxy(1,2);
         printf(lcd_putc,"**");
         _Delay(20);
         
         if(TANG==0)
         {
            while(TANG==0);
            STCD++;
         }
         else if(GIAM==0)
         {
            while(GIAM==0);
            STCD--;
            if(STCD<=0)
            {
               STCD =5;
            }
         }
         else if(MENU==0)
         {
            while(MENU==0);
            CheDo++;
            lcd_putc('\f');
            if(CheDo>3)
            {
               CheDo=0;
            }
         }
      }
      while(CheDo==2)
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc,"STCD");
         lcd_gotoxy(7,1);
         printf(lcd_putc,"SHCD");
         lcd_gotoxy(13,1);
         printf(lcd_putc,"SPCD");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%2d",STCD);
         lcd_gotoxy(7,2);
         printf(lcd_putc,"%2d",SHCD);
         lcd_gotoxy(13,2);
         printf(lcd_putc,"%2d",SPCD);
         _Delay(20);
         lcd_gotoxy(7,2);
         printf(lcd_putc,"**");
         _Delay(20);
         
         if(TANG==0)
         {
            while(TANG==0);
            SHCD++;
         }
         else if(GIAM==0)
         {
            while(GIAM==0);
            SHCD--;
            if(SHCD<=0)
            {
               SHCD =5;
            }
         }
         else if(MENU==0)
         {
            while(MENU==0);
            CheDo++;
            lcd_putc('\f');
            if(CheDo>3)
            {
               CheDo=0;
            }
         }
      }
      while(CheDo==3)
      {
         lcd_gotoxy(1,1);
         printf(lcd_putc,"STCD");
         lcd_gotoxy(7,1);
         printf(lcd_putc,"SHCD");
         lcd_gotoxy(13,1);
         printf(lcd_putc,"SPCD");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"%2d",STCD);
         lcd_gotoxy(7,2);
         printf(lcd_putc,"%2d",SHCD);
         lcd_gotoxy(13,2);
         printf(lcd_putc,"%2d",SPCD);
         _Delay(20);
         lcd_gotoxy(13,2);
         printf(lcd_putc,"**");
         _Delay(20);
         
         if(TANG==0)
         {
            while(TANG==0);
            SPCD++;
         }
         else if(GIAM==0)
         {
            while(GIAM==0);
            SPCD--;
            if(SHCD<=0)
            {
               SHCD =5;
            }
         }
         else if(MENU==0)
         {
            while(MENU==0);
            CheDo++;
            lcd_putc('\f');
            if(CheDo>3)
            {
               CheDo=0;
            }
         }
      }
   }
}

