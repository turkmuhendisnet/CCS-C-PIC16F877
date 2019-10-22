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

#int_timer0 NOCLEAR

int i=0;

#int_timer0
void timer0_kesme()
{
   set_timer0(60);
   i++;
   if(i==10)
      output_high(pin_b0);
   if(i==20)
      output_low(pin_b0);
}

void main()
{
   setup_psp(PSP_DISABLED);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF); 
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF); 
 
   set_tris_b(0x00);
   
   output_b(0x00);
   set_timer0(60);
setup_timer_0(RTCC_INTERNAL | RTCC_DIV_256);
disable_interrupts(int_timer0);

   if(interrupt_active(int_timer0)){
      
      enable_interrupts (int_timer0);
      enable_interrupts (GLOBAL);
      output_low(pin_b1);
      delay_ms(1000);}
      enable_interrupts (int_timer0);
      enable_interrupts (GLOBAL);
      output_high(pin_b1);

   while(1);
}


