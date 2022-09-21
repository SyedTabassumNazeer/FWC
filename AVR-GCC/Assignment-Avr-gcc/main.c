#include <avr/io.h>

#include <util/delay.h>

#include <stdbool.h>


int main (void)

{

 bool G,F;

 bool A=1,B=1,C=0;

 DDRD = 0b00000100;

 DDRB = 0b00100000;

 PORTD = 0b11000000;

 PORTB = 0b00000011;

 while(1){

  F = ((!A&&!B&&!C) || (!A&&B&&!C) || (!A&&B&&C) || (A&&B&&!C)); 

  G = ((!A&&!C) || (B&&!C) || (!A&&B)); 

  if (F == G){

    PORTD = (1 << 2);

  }
  else{

   PORTD = ( 0 << 2);
  
  }

}

        return 0;

}
