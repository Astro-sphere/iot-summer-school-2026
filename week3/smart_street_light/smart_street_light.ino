/*
Project: Smart Street Light
Author: SATYAM KUMAR
Desc: led turns on full when dark and motion detected, dims when no motion, off in daylight
Date: 2026-07-04
*/

int ldr=A0;
int pir=2;
int led=9;

void setup(){
pinMode(pir,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);}

void loop(){
int light=analogRead(ldr);
int motion=digitalRead(pir);

if(light<300){
if(motion==1){
analogWrite(led,255);
Serial.println("Dark + Motion -> FULL brightness");}
else{
analogWrite(led,50);
Serial.println("Dark + No motion -> DIM");}}
else{
analogWrite(led,0);
Serial.println("Daylight -> OFF");}

delay(500);}
