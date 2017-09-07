$include (c8051f120.inc)

cseg at 0000h
	jmp main
cseg at 0080h


main:
	clr EA
	mov WDTCN, #0DEh
	mov WDTCN, #0ADh
	setb EA



	;int factorial(int n){
	;
	;	if(n == 1){
	;		return 1;	
	;	}	
	;
	;	return n * factorial(n - 1);
	;}



	; STAP 1: 'n' definiëren
	; STAP 2: factorial aanroepen
	; STAP 3: n van de stack halen
	; STAP 4: als 'n' niet gelijk is aan 1, moeten we recursie doen
	; STAP 5: Verminden n - 1 en roep factorial terug op met deze waarde
	; STAP 6: Vermenigvuldig n met n - 1
	; STAP 7: Als n = 1 , dan wordt B = 1
	; STAP 8: Subroutine afbreken
	; STAP 9: Programma stopzetten

	; 1
	mov A, #5d ; n = 5
	push ACC   ; De waarde 5 op de stack

	; 2
	call factorial

	; 9
	jmp $

factorial:
	; 3
	push 00h ; R0 op de stack
	mov R0, SP
	push 01h ; R1 op de stack
	dec R0   ; R0 = High Byte Returnadres
	dec R0   ; R0 = Low Byte returnadres
	dec R0   ; R0 = 5
	mov A, @R0 ; A = 5

	; 4
	cjne A, #1d, recursion
	; 7
	mov B, #1d
	mul AB

	pop 01h
	pop 00h
	ret


recursion:
	; 5
	dec A ; n - 1
	push ACC 
	call factorial
	; 6
	inc A
	mul AB
	pop 00h
	ret
