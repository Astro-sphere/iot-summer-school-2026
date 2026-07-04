/*
Project: Smart Street Light
Author: <your name>
Desc: reads an LDR, turns LED on when it is dark (value below 300)
Date: 2026-07-04
*/

int ldr=A0;
int led=8;

void setup(){
pinMode(led,OUTPUT);
Serial.begin(9600);}

void loop(){
int value=analogRead(ldr);
Serial.println(value);
if(value<300){digitalWrite(led,HIGH);}
else{digitalWrite(led,LOW);}
delay(200);}
