#include <main.h>

#INT_RDA
void _NgatUART(void)
{
   
}

void main()
{

   float GiaTriADC,DienAp,NhietDo;
   
   setup_adc(ADC_CLOCK_INTERNAL);//khoi tao ngat acd
   setup_adc_ports(AN0_AN1_VSS_VREF);//chon port doc du lieu adc
   set_adc_channel(0);//chon kenh hay chan doc du lieu adc tu cam bien lm35
   
   enable_interrupts(GLOBAL);//cho phep ngat toan cuc
   
   lcd_init();//khoi dong lcd
   lcd_putc('\f');//xoa trang man hinh lcd
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"DO NHIET DO LM35");
   
   while(TRUE)
   {
      //TODO: User Code
      GiaTriADC = read_adc();
      /*
         5V  ---> 1023
         xV  --->GiaTriADC
         xV = GiaTriADC *5/1023
      */
      DienAp = GiaTriADC*5/1023.0f;
      
       /*
         1mV ---> 1C
         DienAp --->xC
         xC = DienAp*1/10^-3
      */
      NhietDo = DienAp*100.0f;
      
      lcd_gotoxy(1,2);//hang 2 cot 1
      printf(lcd_putc,"NHIET DO:%.0f",NhietDo);
      lcd_putc(223);
      lcd_putc("C");
      
      printf("NHIET DO:%.0f\r",NhietDo);//gui du lieu di len app/truyen du lieu di
      
      delay_ms(1000);//tao tre 1giay
      
   } 
   
}
