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
	mov P1MDOUT, #40h //01000000b
	mov P1, #40h
einde: 
	jmp einde
