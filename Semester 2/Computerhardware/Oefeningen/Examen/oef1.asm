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

	; AND schakeling
	mov A, P1.0  ; A = 0de bit
	anl ACC.0, F0
	mov R2, A    ; R2 = 0de bit

	; OR schakeling
	mov A, 22H.4 ; A = 4de bit
	orl ACC.4, F1
	rr A ; A = 3de bit
	rr A ; A = 2de bit
	rr A ; A = 1ste bit
	rr A ; A = 0de bit

	; XOR schakeling
	xrl A, R2

	; NOT schakeling
	mov C, ACC.0 ;
	cpl C;  EINDRESULTAAT C

	; P1.6
	jb ACC.0, set
	jnb ACC.0, unset



set:
	setb P1.6

unset:
	clr P1.6
