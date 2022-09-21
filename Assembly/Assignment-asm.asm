.include "/home/hp/Tabassum/Assembly/m328Pdef.inc"

ldi r16,0b00000100  ;2 pins
out DDRD,r16

ldi r17, 0b11111000 ; identifying input pins 8,9,10
	out DDRB,r17		; declaring pins as input
ldi r17, 0b11111000 ;
	out PORTB,r17		; activating internal pullup for pins 8,9,10 
	
ldi r27, 0b11111011 ; 
	out DDRB,r27		; 
ldi r27, 0b11111111 ;
	out PORTB,r27		; 

ldi r18,0b00000001 ; value
ldi r19,0b00000001 ; value
ldi r20,0b00000001; value


;in r17,PINB

and r18,r17 ; C
lsr r17;
and r19,r17;B
lsr r17;
and r20,r17; A
lsr r17;

ldi r21,0b00000001;
eor r21,r18;  C'
ldi r22,0b00000001;
eor r22,r19; B'
ldi r23,0b00000001;
eor r23,r20; A'

ldi r16,0b00000000;
mov r16,r18; c
and r16,r22; B'c
and r16,r23; A'B'c

ldi r24,0b00000000;
mov r24,r21; c'
and r24,r19; BC'
and r24,r23; A'BC'

ldi r25,0b00000000;
mov r25,r18; C
and r25,r19; BC
and r25,r23; A'BC

ldi r26,0b00000000;
mov r26,r21; C'
and r26,r19; BC'
and r26,r20; ABC'

or r16, r24;A'B'C+A'BC'
or r16, r25;A'B'C+A'BC'+A'BC
or r16, r26;A'B'C+A'BC'+A'BC+ABC'

mov r24,r21; C'
and r24,r23; A'C'

mov r25,r21; C'
and r25,r19; BC'

mov r26,r19; B'
and r26,r23; A'B

or r24, r25; A'C'+BC'
or r24, r26; A'C'+BC'+A'B

cpse r16,r24; jump to the next instruction only if both the values in r16 and r24 are equal
out PORTD,r27 ;F output
start:
rjmp start
