$include (c8051f120.inc)

cseg at 0000h
	jmp main
cseg at 0080h

main:
	clr EA
	mov WDTCN, #0DEh
	mov WDTCN, #0ADh
	setb EA	

	mov SFRPAGE, #0Fh ; Pagina F voor Crossbar
	mov XBR2, #40h ; Crossbar aazetten
	mov XBR0, #04h ; TX routed to P0.0, and RX routed to P0.1
	mov P0MDOUT, #01h ; TX : output | RX = input


	mov SFRPAGE, #00h
	mov TMOD, #20h  ; Timer 1 Mode 1: 8-bit timer with auto-reload
	mov CKCON, #10h ; Timer 1 uses the system clock
	mov TH1, #246d

	mov SCON0, #40h ; Mode 1: 8-bit UART, Variable Baud Rate
	mov SSTA0, #00h ; Timer 1 generates UART0 TX Baud Rate

	setb TR1

	mov A, #01h ; 2^0
	loop:
		mov SBUF0, A
		jnb TI0, $
		clr TI0
		rlc A
		jmp loop

