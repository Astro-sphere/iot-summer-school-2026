/*
Project: Traffic Light Controller
Author: SATYAM KUMAR
Desc: red yellow green traffic light with pedestrian button, prints state with time
Date: 2026-07-04
*/

int red=8;
int yellow=9;
int green=10;
int button=2;

void setup(){
pinMode(red,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(green,OUTPUT);
pinMode(button,INPUT_PULLUP);
Serial.begin(9600);}

void loop(){
if(digitalRead(button)==LOW){
Serial.print(millis());
Serial.println(" PEDESTRIAN - RED forced");
allOff();
digitalWrite(red,HIGH);
delay(8000);
digitalWrite(red,LOW);}

Serial.print(millis());
Serial.println(" RED");
allOff();
digitalWrite(red,HIGH);
delay(5000);

Serial.print(millis());
Serial.println(" YELLOW");
allOff();
digitalWrite(yellow,HIGH);
delay(2000);

Serial.print(millis());
Serial.println(" GREEN");
allOff();
digitalWrite(green,HIGH);
delay(4000);}

void allOff(){
digitalWrite(red,LOW);
digitalWrite(yellow,LOW);
digitalWrite(green,LOW);}
