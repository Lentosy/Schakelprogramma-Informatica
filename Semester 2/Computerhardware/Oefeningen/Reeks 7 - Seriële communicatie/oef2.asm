$include (c8051f120.inc)

cseg at 0000h
	jmp main
cseg at 0080h

main:
	clr EA
	mov WDTCN, #0DEh
	mov WDTCN, #0ADh
	setb EA

	mov SFRPAGE, #0Fh
	mov XBR2, #40h
	mov XBR0, #04h
	mov P0MDOUT, #0FFh

	mov 20h, #00111111b
   mov 21h, #00000110b
   mov 22h, #01011011b
   mov 23h, #01001111b
   mov 24h, #01100110b
   mov 25h, #01101101b
   mov 26h, #01111101b
   mov 27h, #00000111b
   mov 28h, #01111111b
   mov 29h, #01101111b

	mov SFRPAGE, #00h
	mov TMOD, #20h
	mov CKCON, #10h
	mov TH1, #246d

	mov SCON0, #40h
	mov SSTA0, #00h

	setb TR1

	cjne SBUF0, #30h, $
	mov R2, SBUF0
	mov A, #20h
	add A, R2

	mov R0, A
	mov P0, @R0
