$include (c8051f120.inc)

cseg at 0000h
	jmp main
cseg at 0080h



main:
	clr EA
	mov WDTCN, #0DEh
	mov WDTCN, #0ADh
	setb EA

	; Vermenigvuldig de accumulator met 61,25

	mov A, #167d ; Startwaarde accumulator | LSB van het eindresultaat
	mov B, #00d  ; MSB van het eindresultaat
	mov R2, #6d ; R2 wordt gebruikt om het aantal rotaties te bepalen. Eerst vermenigvuldigen we de accumulator met 64, dus 6 rotaties

	push ACC     ; 167 op de stack plaatsen
	
	rotate_left:
		rlc A ; rotate left op accumulator = Accumulator + 167
		push ACC ; Huidige waarde van accumulator op de stack plaatsen
		mov A, B ; De waarde van B in A steken zodat we een rlc kunnen uitvoeren
		rlc A ; rotate left op de accumulator met de waarde van B
		mov B, A
		pop ACC 
		djnz R2, #0d, rotate_left

	; Op dit moment is de accumulator vermenigvuldigt met 64. 
	; De volgende stap is om hier 3 * 167 van af te trekken zodat we het resultaat hebben
	; 	van 167 * 61

	pop 03h ; R3 bevat 167
	mov R2, #3d ; R2 bevat het aantal aftrekkingen
	subtract:
		subb A, R3
		push ACC
		mov A, B
		subb A, #00d
		pop ACC
		djnz R2, #0d, subtract

	; Op dit moment is de accumulator vermenigvuldigt met 61.
	; De volgende stap is om hier 0.25 * 167 bij op te tellen zodat we het eindresultaat bekomen (167 * 61.25)






	jmp $





