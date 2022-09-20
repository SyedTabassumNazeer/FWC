#include <Arduino.h>

int A,B,C,D; 
int W,X,Y,Z;

//Code released under GNU GPL. Free to use for anything. 
void disp_7447(int D, int C, int B, int A)
{


 W= digitalRead(6);

X=digitalRead(7);
Y=digitalRead(8);

Z=digitalRead(9); 
digitalWrite(2,A);

digitalWrite(3,B);
digitalWrite(4,C);

digitalWrite(5,D);
}

void setup() {

pinMode(2, OUTPUT);

pinMode(3, OUTPUT);

pinMode(4, OUTPUT);

pinMode(5, OUTPUT); pinMode(6, INPUT);

pinMode(7, INPUT); pinMode(8, INPUT);

pinMode(9, INPUT);

}

//the loop function runs over and over ag

void loop() {

A=(!W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z) || (!W&&!X&&!Y&&Z);
B=(W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
C=(W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z); 
D = (W&&X&&Y&&!Z)||(!W&&!X&&!Y&&Z);

disp_7447 (D,C,B,A);

}
