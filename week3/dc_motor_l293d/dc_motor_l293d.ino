/*
Project: DC Motor Speed Control
Author: SATYAM KUMAR
Desc: potentiometer sets motor speed, one button changes direction, another starts or stops it
Date: 2026-07-04
*/

int ena=9;
int in1=8;
int in2=7;
int pot=A0;
int dirBtn=2;
int stopBtn=3;

int forward=1;
int running=1;

void setup(){
pinMode(ena,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode(dirBtn,INPUT_PULLUP);
pinMode(stopBtn,INPUT_PULLUP);
Serial.begin(9600);}

void loop(){
if(digitalRead(dirBtn)==LOW){
forward=!forward;
delay(400);}

if(digitalRead(stopBtn)==LOW){
running=!running;
delay(400);}

int value=analogRead(pot);
int speed=map(value,0,1023,0,255);
int percent=map(value,0,1023,0,100);

if(forward==1){
digitalWrite(in1,HIGH);
digitalWrite(in2,LOW);}
else{
digitalWrite(in1,LOW);
digitalWrite(in2,HIGH);}

if(running==1){
analogWrite(ena,speed);}
else{
analogWrite(ena,0);}

Serial.print("Direction: ");
if(forward==1){Serial.print("Forward");}
else{Serial.print("Reverse");}
Serial.print(" | Speed: ");
Serial.print(percent);
Serial.print("% | State: ");
if(running==1){Serial.println("RUNNING");}
else{Serial.println("STOPPED");}

delay(200);}
