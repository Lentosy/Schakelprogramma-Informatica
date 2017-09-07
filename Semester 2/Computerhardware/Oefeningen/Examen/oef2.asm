$include (c8051f120.inc)
cseg at 0000h
	jmp main
cseg at 0013h
	jmp ISR_INT1 ; External Interrupt 1
cseg at 0080h


main:	
	clr EA
	mov WDTCN, #0DEh
	mov WDTCN, #0ADh
	setb EA
	setb EX1 ; Enable External Interrupt 1
	mov SFRPAGE, #0Fh  ; Pagina F voor Crossbar
	mov XBR2, #40h     ; Crossbar aanzetten
	mov XBR1, #10h     ; /INT1 beschikbaar stellen
	mov P1MDOUT, #07h ; P1.0 , P1.1 , P1.2 als uitvoer

	mov REF0CN, #03h   ; Internal Bias Generator On | Internal Reference Buffer On

	; Vertraging om condensator op te laden
	mov R3,#255d
	delay:
		mov R2, #255d
		djnz R2, $
		djnz R3, delay

	; AIN0.3 Instellen
	mov AMX0CF, #00h ; Rij   0000 
	mov AMX0SL, #03h ; Kolom 0011 


	setb AD0EN ; ADC0 klaarzetten voor te converteren
	clr AD0INT

	loop:
		setb AD0BUSY
		jnb AD0INT, $
		clr AD0INT
		mov B, ADC0H
		mov A, ADC0L


		; Bij B: ?? vervangen door hoogste 4 bits dat overeenkomt met de spanning van de schakeling
		; Bij A: ?? vervangen door laagste 8 bits dat overeenkomt met de spanning van de schakeling
		; Onmogelijk aangezien het verband niet gegeven is
		s1:
			cjne B, ??, s2
			cjne A, ??, s2
			mov P1, #01h
			jmp next


		s2:
			cjne B, ??, s3
			cjne A, ??, s3
			mov P1, #02h
			jmp next


		s3: 
			cjne B, ??, s4
			cjne A, ??, s4
			mov P1, #03h
			jmp next

		s4:
			cjne B, ??, next
			cjne A, ??, next
			mov P1, #04h

		next:
			jmp loop


	jmp $

ISR_INT1: ; Stoppen programma
	clr AD0EN ; ADC0 Uitzetten
	clr EX1   ; Disable External Interrupt
	reti