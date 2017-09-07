$include (c8051f120.inc)

cseg at 0000h
	jmp main
cseg at 0080h


main:
	clr EA
	mov WDTCN, #0DEh
	mov WDTCN, #0ADh
	setb EA


	; STAP 1: c_string definiëren
	; STAP 2: c_string en lengte op de stack plaatsen
	; STAP 3: bereken_lengte aanroepen
	; STAP 4: c_string en lengte van de stack halen
	; STAP 5: zolang de pointer van c_string niet verwijst naar een 0 
	;				verhogen we de c_string pointer en lengte met 1 en keren we terug naar stap 2
	; STAP 6: Als de pointer van c_string verwijst naar een 0 hebben we de totale lengte van de array.
	; 				Deze waarde stoppen we in de accumulator
	; STAP 7: Afbreken subroutine
	; STAP 8: Programma beëindigen


	; 1
	mov 40h, #68h ; h
	mov 41h, #61h ; a
	mov 42h, #6Ch ; l
	mov 43h, #6Ch ; l
	mov 44h, #6Fh ; o
	mov 45h, #00h ; NUL


	; 2 
	mov A, #40h ; startadres c_string
	push ACC    ; startadres c_string op stack
	mov A, #30h ; adres lengte 
	push ACC    ; adres lengte op stack

	;3
	call bereken_lengte

	;8
	mov SP, #07h
	jmp $


bereken_lengte:
	; 4
	push 00h ; R0 op stack
	mov R0, SP ; R0 laten verwijzen naar de Stack Pointer
	push 01h ; R1 op stack
	push 02h ; R2 op stack
	dec R0   ; High Byte returnadres
	dec R0   ; Low Byte returnadres
	dec R0   ; #30h
	mov R1, @R0 ; R1 = #30h
	dec R0   ; #40h
	mov R2, @R0 ; R2 = #40h

	; 5
	cjne R2, #00h, recursion

	; 6

	mov @R0, 01h
	mov A, 30h ; A = waarde van lengte

	; 7
	pop 02h
	pop 01h
	pop 00h
	ret

recursion:
	mov A, @R1
	inc A ; lengte++
 	mov R1, A
	inc R2 ; ++c_string

	push 02h ; c_string op stack
	push 01h ; lengte op stack
	call bereken_lengte
	pop 02h
	pop 01h
	pop 00h
	ret

