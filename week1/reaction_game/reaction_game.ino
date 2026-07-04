/*
Project: Reaction Time Game
Author: SATYAM KUMAR
Desc: 3 leds blink random, green signals go, measures reaction time in ms
Date: 2026-07-04
*/

int leds[3]={9,10,11};
int green=11;
int button=2;
long startTime;

void setup(){
for(int i=0;i<3;i++){pinMode(leds[i],OUTPUT);}
pinMode(button,INPUT_PULLUP);
Serial.begin(9600);
randomSeed(analogRead(A0));}

void loop(){
Serial.println("Get ready...");
delay(1000);

for(int i=0;i<5;i++){
int pick=random(0,3);
digitalWrite(leds[pick],HIGH);
delay(random(300,900));
digitalWrite(leds[pick],LOW);}

digitalWrite(green,HIGH);
startTime=millis();

while(digitalRead(button)==HIGH){}

long reaction=millis()-startTime;
digitalWrite(green,LOW);

Serial.print("Reaction time: ");
Serial.print(reaction);
Serial.println(" ms");

delay(3000);}
