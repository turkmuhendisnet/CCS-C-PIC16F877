#include <16F877.h>

#FUSES NOWDT              //Watch Dog Timer Kullanma
#FUSES RC                 //Resistor/Capacitor Osilatör ile CLKOUT
#FUSES NOPUT              //Power Up Timer Kullanma
#FUSES PROTECT            //Rom'a Yazýlan Verilerin Okunamasýný Engelle
#FUSES NOBROWNOUT         //Brownout Reset Kullanma
#FUSES NOLVP              //Düþük Gerilimler ile Programlamayý Kapt
#FUSES NOCPD              //Data EEPROM Korumasýz
#FUSES NOWRT              //Program Belleði Yazmaya Açýk
#FUSES NODEBUG            //ICD için Hata Ayýklama Modu Kapalý

#use fast_io(a)
#use fast_io(b)

int1 x;

void main()
{
/*Genel Pic de bölmlerinin ayarlamalarý yapýlýyor*/
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);

/* A pinleri a0 giriþ hariç lojik-0 çýkýþ  yapýlýyor*/
set_tris_a(0b00000001);

/* B pinleri komle lojik-0 çýkýþ  yapýlýyor */
set_tris_b(0x00);

while(1)
{
/* a0 pininden okunan deðer x'e atanýyor*/
  x=input(pin_a0);
/* x tek bitlik deðeri b0' atanýyor*/ 
  output_bit(pin_b0,x);
 
}
}
