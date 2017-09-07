$include (c8051f120.inc)

cseg at 0000h
	jmp main
cseg at 000Bh
	jmp ISR_TR0 ; Timer 0 Overflow
cseg at 001Bh
	jmp ISR_TR1 ; Timer 1 Overflow
cseg at 0080h


main:
	; Disable Watchdog Timer
	clr EA
	mov WDTCN, #0DEh
	mov WDTCN, #0ADh
	setb EA

	; Interrupts
	setb ET0 ; Enable Timer 0 Overflow
	setb ET1 ; Enable Timer 1 Overflow

	; Uitvoer
	mov SFRPAGE, #0Fh ; Pagina F voor XBR2 (crossbar)
	mov XBR2, #40     ; Crossbar aanzetten voor P1.6 en P1.7
	mov P1MDOUT, #C0h ; P1.6 en P1.7 als uitvoerpin


	mov SFRPAGE, #00h ; Pagina 0 voor Timer 0 en Timer 1
	;timer 0 = autoreload (255 - 218)
	;timer 1 = 16 bit (65535 - 6125)

	; Timer 0 = Mode 2: 8-bit timer with auto-reload
	; Timer 1 = Mode 1: 16-bit timer
	mov TMOD, #12h 

	; Timer 0 uses the system clock
	; Timer 1 uses the system clock
	mov CKCON, #17h

	mov TH0, #-218d

	mov TH1, #0E8h
	mov TL1, #12h


	setb TR0
	setb TR1

	jmp $
	


ISR_TR0:
	cpl P1.7
	reti
ISR_TR1:
	cpl P1.6
	reti