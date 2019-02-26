#include <16F877.h>

#FUSES NOWDT              //Watch Dog Timer Kullanma
#FUSES RC                 //Resistor/Capacitor Osilat�r ile CLKOUT
#FUSES NOPUT              //Power Up Timer Kullanma
#FUSES PROTECT            //Rom'a Yaz�lan Verilerin Okunamas�n� Engelle
#FUSES NOBROWNOUT         //Brownout Reset Kullanma
#FUSES NOLVP              //D���k Gerilimler ile Programlamay� Kapt
#FUSES NOCPD              //Data EEPROM Korumas�z
#FUSES NOWRT              //Program Belle�i Yazmaya A��k
#FUSES NODEBUG            //ICD i�in Hata Ay�klama Modu Kapal�

#use fast_io(a)
#use fast_io(b)

int1 x;

void main()
{
/*Genel Pic de b�lmlerinin ayarlamalar� yap�l�yor*/
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);

/* A pinleri a0 giri� hari� lojik-0 ��k��  yap�l�yor*/
set_tris_a(0b00000001);

/* B pinleri komle lojik-0 ��k��  yap�l�yor */
set_tris_b(0x00);

while(1)
{
/* a0 pininden okunan de�er x'e atan�yor*/
  x=input(pin_a0);
/* x tek bitlik de�eri b0' atan�yor*/ 
  output_bit(pin_b0,x);
 
}
}
