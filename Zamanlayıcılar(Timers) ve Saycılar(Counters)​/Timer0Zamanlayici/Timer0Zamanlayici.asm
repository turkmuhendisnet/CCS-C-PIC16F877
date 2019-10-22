
_InitTimer0:

;Timer0Zamanlayici.c,3 :: 		void InitTimer0()
;Timer0Zamanlayici.c,5 :: 		OPTION_REG.T0CS=0; // sistem clocktan sayma
	BCF        OPTION_REG+0, 5
;Timer0Zamanlayici.c,6 :: 		OPTION_REG.PSA=0; // ölçeklendirme timer0 için
	BCF        OPTION_REG+0, 3
;Timer0Zamanlayici.c,7 :: 		OPTION_REG.PS2 = 1; // bits 2-0 PS2:PS0: Prescaler Rate 1:64 Select bits
	BSF        OPTION_REG+0, 2
;Timer0Zamanlayici.c,8 :: 		OPTION_REG.PS1 = 0;
	BCF        OPTION_REG+0, 1
;Timer0Zamanlayici.c,9 :: 		OPTION_REG.PS0 = 1;
	BSF        OPTION_REG+0, 0
;Timer0Zamanlayici.c,10 :: 		TMR0=100; // Timer0 ön deðerini yükle
	MOVLW      100
	MOVWF      TMR0+0
;Timer0Zamanlayici.c,11 :: 		INTCON.T0IE=1; // timer0 kesmesine izin ver
	BSF        INTCON+0, 5
;Timer0Zamanlayici.c,12 :: 		INTCON.GIE=1; // bütün kesmelere izin ver
	BSF        INTCON+0, 7
;Timer0Zamanlayici.c,13 :: 		}
L_end_InitTimer0:
	RETURN
; end of _InitTimer0

_Interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;Timer0Zamanlayici.c,15 :: 		void Interrupt()
;Timer0Zamanlayici.c,17 :: 		if (INTCON.T0IF) // eðer Timer0 kesme bayraðý dikilmiþse
	BTFSS      INTCON+0, 2
	GOTO       L_Interrupt0
;Timer0Zamanlayici.c,19 :: 		TMR0 = 100; // TMR0 içeriðini ön deðeri (100) yükle
	MOVLW      100
	MOVWF      TMR0+0
;Timer0Zamanlayici.c,20 :: 		INTCON.T0IF = 0; // kesme bayraðýný sýfýrla
	BCF        INTCON+0, 2
;Timer0Zamanlayici.c,21 :: 		salise++; //salise'yi 1 arttýr
	INCF       _salise+0, 1
;Timer0Zamanlayici.c,22 :: 		PORTA.B0=~PORTA.B0; // salise bilgisini görmek için PORTA pin0 tersleniyor.
	MOVLW      1
	XORWF      PORTA+0, 1
;Timer0Zamanlayici.c,23 :: 		if(salise==100) // eðer salise 100 olduysa;
	MOVF       _salise+0, 0
	XORLW      100
	BTFSS      STATUS+0, 2
	GOTO       L_Interrupt1
;Timer0Zamanlayici.c,25 :: 		saniye++; // saniyeyi 1 arttýr
	INCF       _saniye+0, 1
;Timer0Zamanlayici.c,26 :: 		salise=0; // saliseyi sýfýrla
	CLRF       _salise+0
;Timer0Zamanlayici.c,28 :: 		}
L_Interrupt1:
;Timer0Zamanlayici.c,29 :: 		}
L_Interrupt0:
;Timer0Zamanlayici.c,30 :: 		}
L_end_Interrupt:
L__Interrupt8:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _Interrupt

_kurulum:

;Timer0Zamanlayici.c,32 :: 		void kurulum()
;Timer0Zamanlayici.c,34 :: 		CMCON=7;
	MOVLW      7
	MOVWF      CMCON+0
;Timer0Zamanlayici.c,35 :: 		TRISA=0;
	CLRF       TRISA+0
;Timer0Zamanlayici.c,36 :: 		TRISB=0; // PORTB çýkýþ
	CLRF       TRISB+0
;Timer0Zamanlayici.c,37 :: 		PORTA=0; // PORTA'yý sýfýrla
	CLRF       PORTA+0
;Timer0Zamanlayici.c,38 :: 		PORTB=0; // PORTB'yi sýfýrla
	CLRF       PORTB+0
;Timer0Zamanlayici.c,39 :: 		InitTimer0(); // timer 0 kurulum ayarlarýný çalýþtýr
	CALL       _InitTimer0+0
;Timer0Zamanlayici.c,40 :: 		}
L_end_kurulum:
	RETURN
; end of _kurulum

_main:

;Timer0Zamanlayici.c,41 :: 		void main()
;Timer0Zamanlayici.c,43 :: 		kurulum(); // kurulum fonksiyonunu çalýþtýr.
	CALL       _kurulum+0
;Timer0Zamanlayici.c,44 :: 		do // sonsuz döngü baþlangýcý
L_main2:
;Timer0Zamanlayici.c,46 :: 		if(saniye_eski!=saniye) // eðer saniye deðeri eski deðerinden farklý ise;
	MOVF       _saniye_eski+0, 0
	XORWF      _saniye+0, 0
	BTFSC      STATUS+0, 2
	GOTO       L_main5
;Timer0Zamanlayici.c,48 :: 		PORTB=saniye; // PORTB'ye TMR0 içeriðini yükle
	MOVF       _saniye+0, 0
	MOVWF      PORTB+0
;Timer0Zamanlayici.c,49 :: 		saniye_eski=saniye; // saniye_eski deðerini tazele
	MOVF       _saniye+0, 0
	MOVWF      _saniye_eski+0
;Timer0Zamanlayici.c,50 :: 		}
L_main5:
;Timer0Zamanlayici.c,51 :: 		}while(1);
	GOTO       L_main2
;Timer0Zamanlayici.c,52 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
