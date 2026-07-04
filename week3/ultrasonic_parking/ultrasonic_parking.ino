/*
Project: Ultrasonic Parking Sensor
Author: SATYAM KUMAR
Desc: measures distance with HC-SR04 and warns with leds and buzzer as it gets closer
Date: 2026-07-04
*/

int trig=9;
int echo=10;
int green=4;
int red=5;
int buzzer=6;

void setup(){
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(green,OUTPUT);
pinMode(red,OUTPUT);
pinMode(buzzer,OUTPUT);
Serial.begin(9600);}

void loop(){
digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);

long duration=pulseIn(echo,HIGH);
long distance=(duration*0.034)/2;

Serial.print("Distance: ");
Serial.print(distance);
Serial.println(" cm");

if(distance>50){
Serial.println("SAFE");
digitalWrite(green,LOW);
digitalWrite(red,LOW);
noTone(buzzer);}

else if(distance>=20 && distance<=50){
digitalWrite(green,HIGH);
digitalWrite(red,LOW);
tone(buzzer,1000);
delay(300);
noTone(buzzer);}

else if(distance>=10 && distance<20){
digitalWrite(green,LOW);
digitalWrite(red,HIGH);
tone(buzzer,1500);
delay(150);
noTone(buzzer);}

else{
digitalWrite(green,HIGH);
digitalWrite(red,HIGH);
tone(buzzer,2000);}

delay(200);}
