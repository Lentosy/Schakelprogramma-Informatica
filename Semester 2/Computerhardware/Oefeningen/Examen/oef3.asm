$include (c8051f120.inc)

cseg at 0000h
	jmp main
cseg at 0073h
	jmp ISR_TR3 ; Timer 3
cseg at 0080h


main:
	clr EA            ; 2 bytes
	mov WDTCN, #0DEh  ; 2 bytes
	mov WDTCN, #0ADh  ; 2 bytes 
	setb EA           ; 2 bytes
	mov EIE2, #01h ; Enable Timer 3 interrupts ; 2 bytes

	mov SFRPAGE, #01h ; Pagina 1 voor Timer 3 ; 2 bytes
	mov TMR3CF, #01h  ; Timer 3 is in Capture Mode ; 2 bytes
	mov TMR3CN, #07h  ; Timer Clock Source = SYSCLOCK ; 2 bytes

	; Om de 0.7 ms (0.0007 s)
	mov RCAP3H, #0F6h ; 2 bytes
	mov RCAP3L, #92h ; 2 bytes

	mov R0, #01001100b ; Startwaarde van R0 ; 2 bytes

	setb TR3 ; 2 bytes

	jmp $ ; 1 byte

ISR_TR3:
	mov A, R0 ; 1 byte
	rlc A     ; 1 byte
	mov ACC.0, C ; 3 bytes 
	mov R0, A ; 1 byte
	reti ; 1 byte

; 32 bytes
