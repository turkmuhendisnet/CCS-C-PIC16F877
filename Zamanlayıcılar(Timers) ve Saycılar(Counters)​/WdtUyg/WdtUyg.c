#include <16F877.h>

#FUSES WDT              //Watch Dog Timer Kullanma
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
   
   
   
   setup_WDT(WDT_2304MS);
   
   while(1)
   {
      output_toggle(pin_b0);
      
         while(input(pin_a0))
            restart_wdt();
            
      sleep();
   }
}


