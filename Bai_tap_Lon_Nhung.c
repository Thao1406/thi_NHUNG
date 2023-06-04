#include <16f877a.h>
#device *=16 ADC=10
#use delay(clock=12M)

// Khai bao chan LCD 
#define LCD_ENABLE_PIN  PIN_C0
#define LCD_RS_PIN      PIN_C1
#define LCD_RW_PIN      PIN_C2
#define LCD_DATA4       PIN_C4
#define LCD_DATA5       PIN_C5
#define LCD_DATA6       PIN_C6
#define LCD_DATA7       PIN_C7
#include <lcd.c>
void main()
  {
   int8 a;
   int8 b =1 ;
   int8 key  = 0 ;
   lcd_init();   
   while(true) 
      {
       // Neu cma bien 1 nhan dc gia tri trc 
       //cam bien bien 2 nhan gia tri sau thi 
       // so nguoi tang len 1 
       if(key <= 10)
       {
           if(INPUT(PIN_B0) == 0 && a == 1  && b == 2)
               {    
                     a= 2 ;//
                     delay_ms(250);
               }
           if(INPUT(PIN_B1) == 0 && a == 2 && b == 2 )
              {
                     a= 1;
                    key +=1;
                    delay_ms(250);
              }
       }
       // Neu cam bien 2 nhan gia tri truoc 
       // cam bien 1 thi so nguoi giam 
       if(key > 0)
       {
            if(INPUT(PIN_B1) == 0 && a == 1 && b == 2 )
             {    
              a= 3;
              delay_ms(250);
              }
             if(INPUT(PIN_B0) == 0 && a ==3 && b == 2)
             {
            a= 1;
            key = key -1;
            delay_ms(250);
              }      
       }
       // Bam nut BT3 de mo cua thu vien 
       if(INPUT(PIN_B2) == 0 && b == 1 )
       {
          key =0 ;
          a= 1 ;
          b = 2;
          lcd_gotoxy(0,1);
          printf(lcd_putc,"\c                            "); 
          lcd_gotoxy(0,0);
          printf(lcd_putc,"\c Thu Vien Da Mo            " ); 
          delay_ms(3000);
       }
       
      // Neu bam nut BT4 thi thu vien dong 
      if(INPUT(PIN_B3) == 0 && b ==2 )
       {
         key = 0 ;
         b = 1 ;
         lcd_gotoxy(0,1);
         printf(lcd_putc,"\c                             ");  
         lcd_gotoxy(0,0);
         printf(lcd_putc,"\cThu Vien Da dong            " ); 
         delay_ms(3000);
       } 
       
       // Neu user nho hon 10
       // dieu kien thu vien da mo
       if(key > 0 && key < 10 && b == 2) 
       {  output_d(1);// den1 sang
          lcd_gotoxy(0,1);
          printf(lcd_putc,"\c                           :");  
          lcd_gotoxy(0,0);
          printf(lcd_putc,"\c SL user :%d " ,Key);  
       }
       
       // Neu thu vien dat 10 nguoi 
       // thi TB toi da so nguoi 
       if(key == 10 && b ==2 )
       { 
        a= 3;
        output_d(3);
        lcd_gotoxy(0,1);
        printf(lcd_putc,"\cDa Ta Toi Da        ");  
        lcd_gotoxy(0,0);
        printf(lcd_putc,"\cNumber User           "); 
       }
       
       // Neu ko co ai 
       //TB ko co ai 
       if(key == 0 && b == 2)
       {  
      
        output_d(0);
        lcd_gotoxy(0,1);
        printf(lcd_putc,"\c                           :");  
        lcd_gotoxy(0,0);
        printf(lcd_putc,"\cKhong co ai                :");  
       }          
      }      
}

