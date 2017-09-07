$include (c8051f120.inc)

cseg at 0000h
	jmp main
cseg at 000Bh
	jmp ISR_TR0 ; Timer 0 Overflow
cseg at 0080h


; Stap 1: Chiptemperatuur meten
; Stap 2: De temperatuur op repetitieve manier meten
; Stap 3: De temperatuur doorsturen naar de computer

main:
	clr EA
	mov WDTCN, #0DEh
	mov WDTCN, #0ADh
	setb EA
	setb ET0 ; Enable Timer 0 Overflow

	mov SFRPAGE, #0Fh
	mov XBR2, #40h
	mov XBR0, #04h 
	mov P0MDOUT, #01h

	mov REF0CN, #07h

	mov R3, #255d
	delay:
		mov R2, #255d
		djnz R2, $
		djnz R3, delay

	mov AMX0CF, #00h ; Rij 0000
	mov AMX0SL, #08h ; Kolom 1xxx
	clr AD0INT

	mov TMOD, #21h ; Timer 0 Mode 1: 16-bit timer | Timer 1 Mode 2: 8-bit timer with auto-reload
	mov CKCON, 02h ; Timer 0 uses SYSCLOCK / 12 | Timer 1 uses SYSCLOCK
	mov TH0, #06h
	mov TL0, #0C5h
	mov TH1, #246d

	mov SCON0, #40h ; Mode 1: 8-bit UART, Variable Baud Rate
	mov SSTA0, #00h ; Timer 1 generates UART0 TX Baud Rate

	setb TR0

	jmp $
ISR_TR0: ; Meten van de chiptemperatuur
	clr TR0
	mov TH0, #06h
	mov TL0, #0C5h
	setb TR0

	setb AD0EN
	setb AD0BUSY
	jnb AD0INT, $
	clr AD0INT

	; T = 15 + (ADC0l - 64h) / 5
	mov A, ADC0L
	subb A, #64h
	add A, #15d
	mov B, #5d
	div AB
	mov R2, B
	mov B, #10d

	div AB
	mov R4, A
	mov R3, B

	; Tientallen
	mov SBUF0, A
	jnb TI0, $
	clr TI0

	; Eenheden
	mov A, B
	mov SBUF0, A
	jnb TI0, $
	clr TI0

	; Kommagetal
	mov A, R2
	mov SBUF0, A
	jnb TI0, $
	clr TIO	


	reti

