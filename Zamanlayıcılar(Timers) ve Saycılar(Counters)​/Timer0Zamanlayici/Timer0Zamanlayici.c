unsigned char salise=0,saniye=0,saniye_eski=0;
//---------------------------------------------
void InitTimer0()
{
  OPTION_REG.T0CS=0; // sistem clocktan sayma
  OPTION_REG.PSA=0; // ölçeklendirme timer0 için
  OPTION_REG.PS2 = 1; // bits 2-0 PS2:PS0: Prescaler Rate 1:64 Select bits
  OPTION_REG.PS1 = 0;
  OPTION_REG.PS0 = 1;
  TMR0=100; // Timer0 ön deðerini yükle
  INTCON.T0IE=1; // timer0 kesmesine izin ver
  INTCON.GIE=1; // bütün kesmelere izin ver
}
//-------------------------------------
void Interrupt()
{
  if (INTCON.T0IF) // eðer Timer0 kesme bayraðý dikilmiþse
  {
    TMR0 = 100; // TMR0 içeriðini ön deðeri (100) yükle
    INTCON.T0IF = 0; // kesme bayraðýný sýfýrla
    salise++; //salise'yi 1 arttýr
    PORTA.B0=~PORTA.B0; // salise bilgisini görmek için PORTA pin0 tersleniyor.
    if(salise==100) // eðer salise 100 olduysa;
    {
      saniye++; // saniyeyi 1 arttýr
      salise=0; // saliseyi sýfýrla

    }
  }
}
//------------------------------
void kurulum()
{
  CMCON=7;
  TRISA=0;
  TRISB=0; // PORTB çýkýþ
  PORTA=0; // PORTA'yý sýfýrla
  PORTB=0; // PORTB'yi sýfýrla
  InitTimer0(); // timer 0 kurulum ayarlarýný çalýþtýr
}
void main()
{
  kurulum(); // kurulum fonksiyonunu çalýþtýr.
  do // sonsuz döngü baþlangýcý
  {
    if(saniye_eski!=saniye) // eðer saniye deðeri eski deðerinden farklý ise;
    {
      PORTB=saniye; // PORTB'ye TMR0 içeriðini yükle
      saniye_eski=saniye; // saniye_eski deðerini tazele
    }
  }while(1);
}