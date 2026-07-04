/*
Project: Relay Controlled Device
Author: SATYAM KUMAR
Desc: temperature turns a relay (led) on above 32 C and off below 28 C with hysteresis, plus manual override
Date: 2026-07-04
*/

int tempPin=A0;
int relay=8;
int button=2;

int relayState=0;
int override=0;

void setup(){
pinMode(relay,OUTPUT);
pinMode(button,INPUT_PULLUP);
Serial.begin(9600);}

void loop(){
if(digitalRead(button)==LOW){
override=!override;
Serial.println("Manual override toggled");
delay(400);}

int reading=analogRead(tempPin);
float voltage=reading*5.0/1024.0;
float tempC=(voltage-0.5)*100;

if(override==1){
relayState=1;}
else{
if(tempC>32){relayState=1;}
if(tempC<28){relayState=0;}}

digitalWrite(relay,relayState);

Serial.print("Temp: ");
Serial.print(tempC);
Serial.print(" C | Relay: ");
if(relayState==1){Serial.println("ON");}
else{Serial.println("OFF");}

delay(500);}
