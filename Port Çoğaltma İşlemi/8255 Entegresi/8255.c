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

#use standard_io(a)
#use standard_io(b)


int data;

/* Yazma  Fonksiyonu*/
void _8255_yazma (char x, char bilgi)
{

   switch(x)
   {
      case 'k':
         output_a(0b00001101);
         output_b(bilgi);
         break;
      case 'a':
         output_a(0b00000001);
         output_b(bilgi);
         break;
      case 'b':
         output_a(0b00000101);
         output_b(bilgi);
         break;
      case 'c':
         output_a(0b00001001);
         output_b(bilgi);
         break;
      default:
         break;
   }   
}
/*Okuma Fonksiyonu*/
int _8255_okuma(char x)
{
   switch(x)
   {
   
      case 'k':
         output_a(0b00001110);
         return(input_b());
         break;
      case 'a':
         output_a(0b00000010);
         return(input_b());
         break;
      case 'b':
         output_a(0b00000110);
         return(input_b());
         break;
      case 'c':
         output_a(0b00001010);
         return(input_b());
         break;
      default:
         break;
   }
}

/* Ana fonksiyon*/
void main()
{
   setup_psp(PSP_DISABLED);
   setup_adc_ports(NO_ANALOGS);
   setup_adc(ADC_OFF);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_CCP1(CCP_OFF);
   setup_CCP2(CCP_OFF); 
   
   _8255_yazma('k',0b10001001);
   _8255_yazma('a',0x00);
   
   while(1)
   {
      data=(_8255_okuma('c'));
      _8255_yazma('a',data);
   }
 
}


