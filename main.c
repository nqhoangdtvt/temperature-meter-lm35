#include <main.h>

#INT_RDA
void _NgatUART(void)
{
   
}

void main()
{

   float GiaTriADC,DienAp,NhietDo;
   
   setup_adc(ADC_CLOCK_INTERNAL);//Khởi tạo ngắt ADC
   setup_adc_ports(AN0_AN1_VSS_VREF);//Chọn Port đọc dữ liệu ADC
   set_adc_channel(0);//Chọn kênh hay chân đọc dữ liệu từ ADC từ cảm biến LM35
   
   enable_interrupts(GLOBAL);//Cho phép ngắt toàn cục
   
   lcd_init();//Khởi động LCD
   lcd_putc('\f');//Xóa trang màn hình LCD
   
   lcd_gotoxy(1,1);//Hàng 1 cột 1
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
      
      lcd_gotoxy(1,2);//Hàng 2 cột 1
      printf(lcd_putc,"NHIET DO:%.0f",NhietDo);
      lcd_putc(223);
      lcd_putc("C");
      
      printf("NHIET DO:%.0f\r",NhietDo);//Gửi dữ liệu lên  app/ truyền dữ liệu đi
      
      delay_ms(1000);//Tạo trễ 1s
      
   } 
   
}
