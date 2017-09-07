# Computerhardware 
# 1. 7-segment displaymodule
De 7-segment displaymodule kan tot maximaal 4 poorten ingesteld worden waarbij elke poort een 7-segment display voorstelt.  Uiteraard is het mogelijk dat andere poorten gebruikt worden.

```bash
mov P0MDOUT, #0FFh
mov P1MDOUT, #0FFh
mov P2MDOUT, #0FFh
mov P3MDOUT, #0FFh
```
De 7-segment display bevat, zoals de naam het doet vermoeden, 7 zegmenten die elk onafhankelijk aan of uit kunnen staan. De getallen 0 tot en met 9 worden dus bepaald door een bitpatroon. In het volgende voorbeeld schrijven we deze bitpatronen weg van **20h** tot en met **29h. **De underscores zijn enkel bedoeld voor de leesbaarheid en dienen niet in het codesegment te komen. Merk op dat het 8ste bit nooit gebruikt wordt. Logisch aangezien het een 7-segment display is. Het is ook mogelijk om letters af te beelden maar is minder beperkt.

```bash
mov 20h, #0011_1111b //0
mov 21h, #0000_0110b //1
mov 22h, #0101_0011b //2
mov 23h, #0100_1011b //3
mov 24h, #0110_0110b //4
mov 25h, #0110_1101b //5
mov 26h, #0111_1101b //6
mov 27h, #0000_0111b //7
mov 28h, #0111_1111b //8
mov 29h, #0110_1111b //9
```
Om een getal af te beelden wordt er gebruik gemaakt van de accumulator en een register waarin één van de 9 waarden in zit. In dit geval is dit het **R2 **register.

```bash
mov A, #20h
add A, R2
mov P0, R2
mov P0, @R0
```
Als in R2 het getal 4 zit, zal in de accumulator **24h **zitten, wat overeenkomt met het bitpatroon om een 4 af te beelden. Deze wordt in R0 gestopt aangezien je naar een uitvoerpin een pointer moet wegschrijven. A heeft die functionaliteit niet, R0 en R1 wel.
# 2. Timers
Er wordt eerst een voorbeeld gedemonstreerd om de context te begrijpen, daarna wordt elk individueel component toegelicht. De commando's voorafgegaan door -- hebben betrekking tot timers

```bash
cseg at 0000h
    jmp main
cseg at 000Bh
    jmp ISR_TR0
cseg at 0080h
main:
    clr EA
    mov WDTCN, #0DEh
    mov WDTCN, #0ADh
    setb EA
 -- setb ET0
    mov SFRPAGE, #0Fh
    mov XBR2, #40h
 -- mov TMOD, #01h 
    mov CKCON, #00h
 -- mov TH0, #06h  
 -- mov TL0, #0C5h 
 -- setb TR0 
    jmp, $
ISR_TR0:    
 -- clr TF0 
    cpl P1.6
 -- mov TH0, #06h 
 -- mov TL0, #0C5h 
 -- setb TR0 
    reti
```


























# 3. Analoog naar digitaal converter
## 3.1 Meten van de chiptemperatuur
Om de chiptemperatuur te meten worden volgende commando's gebruikt
































