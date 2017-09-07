$include (c8051f120.inc)

cseg at 0000h
	jmp main
cseg at 0080h


; A * 62
main:
	clr EA
	mov WDTCN, #0DEh
	mov wDTCN, #0ADh
	setb EA

	mov A, #147d ; Dummy-waarde
	push ACC     ; 147 op de stack
	mov B, #00d
	mov R2, #6d



	; A * 64
	multiply:
		rlc A
		push ACC
		mov A, B
		rlc A
		mov B, A
		pop ACC
		djnz R2, multiply


	; -(A * 2)
	pop 03h ; R3 = 147
	mov R2, #2d
	subtract:
		subb A, R3
		push ACC
		mov A, B
		subb A, #00d
		mov B, A
		pop ACC
		djnz R2, subtract

