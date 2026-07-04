/*
Project: Servo Motor Control
Author: SATYAM KUMAR
Desc: potentiometer controls servo angle 0 to 180, a button does one full sweep
Date: 2026-07-04
*/

#include <Servo.h>

Servo myServo;
int pot=A0;
int button=2;

void setup(){
myServo.attach(9);
pinMode(button,INPUT_PULLUP);
Serial.begin(9600);}

void loop(){
if(digitalRead(button)==LOW){
Serial.println("Sweeping...");
for(int a=0;a<=180;a++){myServo.write(a);delay(15);}
for(int a=180;a>=0;a--){myServo.write(a);delay(15);}
delay(300);}

int value=analogRead(pot);
int angle=map(value,0,1023,0,180);
myServo.write(angle);

Serial.print("Angle: ");
Serial.println(angle);

delay(100);}
