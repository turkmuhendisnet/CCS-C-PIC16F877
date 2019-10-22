#include <16F877.h>

#FUSES NOWDT              //Watch Dog Timer Kullanma
#FUSES XT                 //Kristal  Osilatör ile CLKOUT
#FUSES NOPUT              //Power Up Timer Kullanma
#FUSES NOPROTECT          //Rom'a Yazýlan Veriler Okunabilir
#FUSES NOBROWNOUT         //Brownout Reset Kullanma
#FUSES NOLVP              //Düþük Gerilimler ile Programlamayý Kapt
#FUSES NOCPD              //Data EEPROM Korumasýz
#FUSES NOWRT              //Program Belleði Yazmaya Açýk
#FUSES NODEBUG            //ICD için Hata Ayýklama Modu Kapalý

#use delay(clock=4000000)

#use fast_io(a)
#use fast_io(b)

unsigned int kesme=0;

#int_timer2
void timer2_kesme()
{
   kesme++;

   output_high(pin_b0);
   delay_ms(1000);
   output_low(pin_b0);
   delay_ms(1000);
}

void main()
{
   setup_psp(PSP_DISABLED);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF); 
   setup_timer_1(T1_DISABLED);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF); 
   
   set_tris_b(0x00);
   set_tris_a(0x01);
   
   output_b(0x00);
   
   
   
   setup_timer_2(T2_DIV_BY_16,250,16);
   
   
   enable_interrupts (int_timer2);
   enable_interrupts (GLOBAL); 
   
   while(1)
   {
      if(input(pin_a0))
         output_b(kesme);
   }
}


