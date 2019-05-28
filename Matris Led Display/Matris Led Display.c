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
#use fast_io(c)

int   A[]={0x03,0x75,0x76,0x75,0x03},
     B[]={0x00,0x36,0x36,0x36,0x49},
     C[]={0x41,0x3E,0x3E,0x3E,0x5D},
     D[]={0x00,0x3E,0x3E,0x3E,0x41},
        E[]={0x00,0xB6,0xB6,0xB6,0xBE},
   arti[]={0x77,0x77,0x41,0x77,0x77},
cift_ok[]={0x6B,0x5D,0x00,0x5D,0x6B};

int sutunsec(int s)
{
   switch(s)
   {
      case 0: return(0x10);break;
      case 1: return(0x08);break;
      case 2: return(0x04);break;
      case 3: return(0x02);break;
      case 4: return(0x01);break;
   }
}
void matris_karakter_gonder(char harf[],int tekrar)
{
   int i,j,k;
   for(i=1;i<tekrar;i++)
   {
      for(k=0;k<10;k++)
      {
         for(j=0;j<5;j++)
         {
            output_c(sutunsec(j));
            output_b(harf[j]);
            delay_ms(1);   
         }

      }
   }
   
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
   set_tris_c(0x00);
   

   while(1)
   {
   matris_karakter_gonder(A,20);
   matris_karakter_gonder(B,20);
   matris_karakter_gonder(C,20);
   matris_karakter_gonder(D,20);
   matris_karakter_gonder(E,20);
   matris_karakter_gonder(arti,20);
   matris_karakter_gonder(cift_ok,20);
   }
}


