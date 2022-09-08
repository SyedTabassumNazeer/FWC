#include <Arduino.h>
int Z=0,Y=0,X=0,W=1;
int D,C,B,A,a,b,c,d,e,f,g;

//Code released under GNU GPL.  Free to use for anything.
void disp_7447(int a,int b,int c,int d,int e,int f,int g)
{
  digitalWrite(2, a); 
  digitalWrite(3, b); 
  digitalWrite(4, c); 
  digitalWrite(5, d); 
  digitalWrite(6, e); 
  digitalWrite(7, f);     
  digitalWrite(8, g);

}
// the setup function runs once when you press reset or power the board
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
  D=(!W&&!Z)||(!W&&!X&&!Y);         
  C=(W&&!X&&!Z) || (!W&&X&&!Z);                                            
  B=(W&&X&&!Y&&!Z) || (!X&&Y&&!Z) || (!W&&Y&&!Z);                         
  A= (W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z); 
  a=(!A&&!B&&!C&&D) || (!A&&B&&!C&&!D) || (!A&&B&&C&&!D); 
  b=(!A&&B&&!C&&!D) || (!A&&B&&!C&&D) || (!A&&B&&C&&!D);
  c=(!A&&!B&&C&&!D);
  d=(!B&&!C&&D) || (!A&&B&&!C&&!D) || (!A&&B&&C&&D); 
  e=(!A&&D) || (!A&&B&&!C) || (!B&&!C&&D);
  f=(!A&&!B&&D) || (!A&&C&&D) || (!A&&!B&&C);
  g=(!A&&!B&&!C) || (!A&&B&&C&&D);
  disp_7447(a,b,c,d,e,f,g);
}
