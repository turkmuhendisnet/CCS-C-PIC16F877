#line 1 "E:/Mikroc/ornek/Web_Blog/Timer0Zamanlayici/Timer0Zamanlayici.c"
unsigned char salise=0,saniye=0,saniye_eski=0;

void InitTimer0()
{
 OPTION_REG.T0CS=0;
 OPTION_REG.PSA=0;
 OPTION_REG.PS2 = 1;
 OPTION_REG.PS1 = 0;
 OPTION_REG.PS0 = 1;
 TMR0=100;
 INTCON.T0IE=1;
 INTCON.GIE=1;
}

void Interrupt()
{
 if (INTCON.T0IF)
 {
 TMR0 = 100;
 INTCON.T0IF = 0;
 salise++;
 PORTA.B0=~PORTA.B0;
 if(salise==100)
 {
 saniye++;
 salise=0;

 }
 }
}

void kurulum()
{
 CMCON=7;
 TRISA=0;
 TRISB=0;
 PORTA=0;
 PORTB=0;
 InitTimer0();
}
void main()
{
 kurulum();
 do
 {
 if(saniye_eski!=saniye)
 {
 PORTB=saniye;
 saniye_eski=saniye;
 }
 }while(1);
}
