/*
Project: Digital Piano
Author: SATYAM KUMAR
Desc: 4 button piano with a buzzer, plays notes, chord for two buttons, and major/minor toggle
Date: 2026-07-04
*/

int buzzer=8;
int b1=2;
int b2=3;
int b3=4;
int b4=5;
int b5=6;

int minorMode=0;

void setup(){
pinMode(buzzer,OUTPUT);
pinMode(b1,INPUT_PULLUP);
pinMode(b2,INPUT_PULLUP);
pinMode(b3,INPUT_PULLUP);
pinMode(b4,INPUT_PULLUP);
pinMode(b5,INPUT_PULLUP);
Serial.begin(9600);
Serial.println("Major mode");}

void loop(){
if(digitalRead(b5)==LOW){
minorMode=!minorMode;
if(minorMode==1){Serial.println("Minor mode");}
else{Serial.println("Major mode");}
delay(400);}

int p1=digitalRead(b1);
int p2=digitalRead(b2);
int p3=digitalRead(b3);
int p4=digitalRead(b4);

if(p1==LOW && p2==LOW){
tone(buzzer,392);}

else if(p1==LOW){
if(minorMode==0){tone(buzzer,262);}
else{tone(buzzer,247);}}

else if(p2==LOW){
if(minorMode==0){tone(buzzer,294);}
else{tone(buzzer,277);}}

else if(p3==LOW){
if(minorMode==0){tone(buzzer,330);}
else{tone(buzzer,311);}}

else if(p4==LOW){
tone(buzzer,349);}

else{
noTone(buzzer);}}
