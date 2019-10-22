unsigned char salise=0,saniye=0,saniye_eski=0;
//---------------------------------------------
void InitTimer0()
{
  OPTION_REG.T0CS=0; // sistem clocktan sayma
  OPTION_REG.PSA=0; // �l�eklendirme timer0 i�in
  OPTION_REG.PS2 = 1; // bits 2-0 PS2:PS0: Prescaler Rate 1:64 Select bits
  OPTION_REG.PS1 = 0;
  OPTION_REG.PS0 = 1;
  TMR0=100; // Timer0 �n de�erini y�kle
  INTCON.T0IE=1; // timer0 kesmesine izin ver
  INTCON.GIE=1; // b�t�n kesmelere izin ver
}
//-------------------------------------
void Interrupt()
{
  if (INTCON.T0IF) // e�er Timer0 kesme bayra�� dikilmi�se
  {
    TMR0 = 100; // TMR0 i�eri�ini �n de�eri (100) y�kle
    INTCON.T0IF = 0; // kesme bayra��n� s�f�rla
    salise++; //salise'yi 1 artt�r
    PORTA.B0=~PORTA.B0; // salise bilgisini g�rmek i�in PORTA pin0 tersleniyor.
    if(salise==100) // e�er salise 100 olduysa;
    {
      saniye++; // saniyeyi 1 artt�r
      salise=0; // saliseyi s�f�rla

    }
  }
}
//------------------------------
void kurulum()
{
  CMCON=7;
  TRISA=0;
  TRISB=0; // PORTB ��k��
  PORTA=0; // PORTA'y� s�f�rla
  PORTB=0; // PORTB'yi s�f�rla
  InitTimer0(); // timer 0 kurulum ayarlar�n� �al��t�r
}
void main()
{
  kurulum(); // kurulum fonksiyonunu �al��t�r.
  do // sonsuz d�ng� ba�lang�c�
  {
    if(saniye_eski!=saniye) // e�er saniye de�eri eski de�erinden farkl� ise;
    {
      PORTB=saniye; // PORTB'ye TMR0 i�eri�ini y�kle
      saniye_eski=saniye; // saniye_eski de�erini tazele
    }
  }while(1);
}