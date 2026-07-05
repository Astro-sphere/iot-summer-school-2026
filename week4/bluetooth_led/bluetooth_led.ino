/*
Project: Bluetooth LED Controller
Author: SATYAM KUMAR
Desc: esp32 bluetooth receives letters from phone to control 3 leds
Date: 2026-07-05
*/

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

int green=18;
int white=19;
int blue=21;

void setup(){
Serial.begin(115200);
SerialBT.begin("ESP32-SATYAM");
pinMode(green,OUTPUT);
pinMode(white,OUTPUT);
pinMode(blue,OUTPUT);
Serial.println("Bluetooth started. Pair with ESP32-SATYAM");}

void loop(){
if(SerialBT.available()){
char c=SerialBT.read();

if(c=='G'){digitalWrite(green,HIGH);SerialBT.println("Green ON");}
if(c=='W'){digitalWrite(white,HIGH);SerialBT.println("White ON");}
if(c=='B'){digitalWrite(blue,HIGH);SerialBT.println("Blue ON");}
if(c=='X'){
digitalWrite(green,LOW);
digitalWrite(white,LOW);
digitalWrite(blue,LOW);
SerialBT.println("All OFF");}
if(c=='F'){
for(int i=0;i<5;i++){
digitalWrite(green,HIGH);digitalWrite(white,HIGH);digitalWrite(blue,HIGH);
delay(300);
digitalWrite(green,LOW);digitalWrite(white,LOW);digitalWrite(blue,LOW);
delay(300);}
SerialBT.println("Flashed");}}}
