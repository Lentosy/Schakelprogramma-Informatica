$include (c8051f120.inc)

cseg at 0000h
	jmp main
cseg at 000Bh
	jmp ISR_TR0       ; Timer 0 Overflow
cseg at 0080h

main:
	clr EA
	mov WDTCN, #0DEh
	mov WDTCN, #0ADh
	setb EA
	setb ET0          ; Enable Timer 0 Overflow

	mov SFRPAGE, #0Fh ; Pagina voor Crossbar
	mov XBR2, #40h    ; Crossbar aanzetten voor P1.6
	mov P1MDOUT, #70h ; P1.6 als uitvoerpin

	mov SFRPAGE, #00h ; Pagina voor Timer 0
	mov TMOD, #01h    ; Timer 0 Mode 1: 16-bit timer
	mov CKCON, #20h   ; System clock divided by 48
	mov TH0, #06h     ; High Byte Timer 0 
	mov TL0, #0C5h    ; Low Byter Timer 0

	setb TR0          ; Timer 0 activeren
	clr C             ; Ik gebruik de carry om te bepalen of het lampje moet branden of niet
	jmp $


ISR_TR0:
	cpl C              
	jc aan
	jnc uit
	reti

aan:
	setb P1.6         ; P1.6 aanzetten
uit:
	clr P1.6          ; P1.6 uitzetten



