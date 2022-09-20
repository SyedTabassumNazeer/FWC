#include <Arduino.h>
int A=0,B=1,C=1,D=1;

int a,b,c,d,e,f,g;

//Code, released under GNU GPL. Free to use for anything. 
void disp_7447(int a, int b, int c, int d, int e, int f,int g){

digitalWrite(2, a); 

digitalWrite(3, b);

digitalWrite(4, c);

digitalWrite(5, d); 
digitalWrite(6, e);

digitalWrite(7, f); 
digitalWrite(8, g);

} // the setup function runs once when you press reset or power the board

void setup() {

pinMode(2, OUTPUT);

pinMode(3, OUTPUT);

pinMode(4, OUTPUT);

pinMode(5, OUTPUT);

pinMode(6, OUTPUT);

pinMode(7, OUTPUT);

pinMode(8, OUTPUT);

}

// the loop function runs over and over again forever

void loop() {

a=(!A&&!B&&!C&&D) || (!A&&B&&!C&&!D) || (!A&&B&&C&&!D); 
b=(!A&&B&&!C&&!D) || (!A&&B&&!C&&D) || (!A&&B&&C&&!D);

c=(!A&&!B&&C&&!D);

d=(!A&&!B&&!C&&D) || (!A&&B&&!C&&!D) || (!A&&B&&C&&D); 
e=(!A&&!B&&!C&&D) || (!A&&!B&&C&&D) || (!A&&B&&!C&&!D) || (!A&&B&&!C&&D) || (!A&&B&&C&&D) || (A&&!B&&!C&&D);

f=(!A&&!B&&!C&&D) || (!A&&! B&&C&&!D) || (!A&&!B&&C&&D);

g=(!A&&!B&&!C&&!D) || (!A&&!B&&!C&&D) || (!A&&B&&C&&D);

disp_7447(a,b,c,d,e,f,g);

}
