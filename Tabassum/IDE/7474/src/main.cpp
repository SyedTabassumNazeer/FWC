#include <Arduino.h>
int Z=0,Y=0,X=1,W=1;
int D,C,B,A;
void disp_7474(int D,int C,int B,int A)
{
digitalWrite(2, A);
digitalWrite(3, B);
digitalWrite(4, C);
digitalWrite(5, D);
}
void setup(){
    pinMode(13, OUTPUT);  
    pinMode(6, INPUT);
    pinMode(7, INPUT);
    pinMode(8, INPUT);
    pinMode(9, INPUT);
    pinMode(2, OUTPUT);  
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
digitalWrite(13, HIGH);
delay(1000);
digitalWrite(13, LOW);
delay(1000);
A=(!W&&!X&&!Y) || (!W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (!W&&X&&!Y&&!Z);
B=(W&&!X&&!Y&&!Z) || (!W&&X&&!Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
C=(W&&X&&!Y&&!Z) || (!W&&!X&&Y&&!Z) || (W&&!X&&Y&&!Z) || (!W&&X&&Y&&!Z);
D=(W&&X&&Y&&!Z) || (!W&&!X&&!Y&&Z);
disp_7474(D,C,B,A);
}
