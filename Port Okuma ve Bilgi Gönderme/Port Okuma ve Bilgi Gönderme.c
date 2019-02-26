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

/*Programda zamanlama kullan�lacaksa*/
#use delay(clock=4000000) 

/*Port y�nlendirme yap�l�yor */
#use fast_io(b)
#use fast_io(a)

/* Portb kelimesi b portunun adresine yerle�tirilmi�tir*/
#byte portb=6

int x;
void main()
{
/*Genel Pic de b�lmlerinin ayarlamalar� yap�l�yor*/
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_spi(SPI_SS_DISABLED);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);

/* A pinleri hexadecimal g�sterimle lojik-1 giri� yap�lm��t�r binary 11111111*/
set_tris_a(0xFF);
/*B pinleri t�m�yle ��k�� yap�lm��t�r binary g�steri*/
set_tris_b(0xFF);

/* B portu giri� lojik-1 yap�l�yor*/
output_b(0x00);
// b portun t�m pinleri enerjilendi

while(1)
{  /* a portu t�m pinleri okunuyor*/
   x=input_a();
   /* x de�i�kenin son iki biti s�f�rlanm��t�r*/
   x=x&0b00111111;
   
   /* x degeri b portuna ��k�� olarak g�nderiliyor.*/
   portb=x;
   
}
}


