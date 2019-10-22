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

#use fast_io(b)

int i=0;

#int_timer1
void timer1_kesme()
{
   set_timer1(63016);
   i++;   
      if(i==50)
         output_high(pin_b0);
      
      if(i==100)
      {
         output_low(pin_b0);
         i=0;
      }
}

void main()
{
   setup_psp(PSP_DISABLED);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF); 
   setup_timer_2(T2_DISABLED,0,1);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF); 
   
   set_tris_b(0x00);
   set_timer1(63036);
   output_b(0x00);
   
   setup_timer_1(T1_INTERNAL | T1_DIV_BY_8);
   
   
   enable_interrupts (int_timer1);
   enable_interrupts (GLOBAL); 
   while(1);
}


