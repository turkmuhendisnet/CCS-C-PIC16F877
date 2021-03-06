#include <16F877.h>

#FUSES NOWDT              //Watch Dog Timer Kullanma
#FUSES XT                 //Kristal  Osilat�r ile CLKOUT
#FUSES NOPUT              //Power Up Timer Kullanma
#FUSES NOPROTECT          //Rom'a Yaz�lan Veriler Okunabilir
#FUSES NOBROWNOUT         //Brownout Reset Kullanma
#FUSES NOLVP              //D���k Gerilimler ile Programlamay� Kapt
#FUSES NOCPD              //Data EEPROM Korumas�z
#FUSES NOWRT              //Program Belle�i Yazmaya A��k
#FUSES NODEBUG            //ICD i�in Hata Ay�klama Modu Kapal�

#use delay(clock=4000000)

#define buton pin_A0

#use fast_io(b)

int i;
/* Dizi tan�mlamas� Yap�l�yor*/
const int dizi[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7C,0x07,0x7F,0x6F};

void main()
{
  /* PIC  ayarlar� ya�p�l�yor*/
   setup_psp(PSP_DISABLED);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF); 
   
/* b portu ��k�� olarak y�nlendiriliyor*/ 
set_tris_b(0x00);

/* b portunun ��k��lar� lojik-0 yap�l�yor*/
output_b(0x00);

   while(1)
   {
         for(i=0;i<11;i++)
            {
               output_b(dizi[i]);
               delay_ms(500);
           }
   }
}

