$include (c8051f120.inc)

cseg at 0000h
	jmp main
cseg at 0003h
	jmp ISR_TR0 ; Timer 0 Overflow
cseg at 0013h
	jmp ISR_TR1 ; Timer 1 Overflow
cseg at 0080h

main:
	clr EA
	mov WDTCN, #0DEh
	mov WDTCN, #0ADh
	setb EA

	setb ET0 ; Enable Timer 0 Overflow
	setb ET1 ; Enable Timer 1 Overflow

	mov SFRPAGE, #0Fh ; Pagina F voor XBR2
	mov XBR2, #40h    ; Crossbar aanzetten voor P1.7
	mov P1MDOUT, #80h ; P1.7 als uitvoerpin

	mov SFRPAGE, #00h ; Pagina 0 voor Timer 0 en Timer 1
	mov TMOD, #21     ; Timer 0 = 16-bit | Timer 1 = 8-bit auto-reload
	mov CKCON, #00h   ; Systeemklok / 12

	mov TH0, #06h
	mov TL0, #0C5h

	; 3 KHz => 43
	; 1.5 Khz => 85

	mov TH1, #-85d
	mov TL1, #-85d

	clr C
	setb TR0

	jmp $

ISR_TR0:
	clr TR0
	mov TH0, #06h
	mov TL0, #0C5h
	setb TR0
	cpl C
	jc hoog
	jnc laag
	reti

ISR_TR1:
	cpl P1.7
	reti

hoog:
	mov TH1, #-43d
	mov TL1, #-43d
	reti


laag:
	mov TH1, #-85d
	mov TL1, #-85d
	reti