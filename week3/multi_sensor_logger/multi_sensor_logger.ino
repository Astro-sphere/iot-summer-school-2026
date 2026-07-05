/*
Project: Multi Sensor Data Logger
Author: SATYAM KUMAR
Desc: reads ldr, temperature and ultrasonic distance and prints a formatted log every 5 seconds
Date: 2026-07-04
*/

int ldr=A0;
int tempPin=A1;
int trig=9;
int echo=10;

void setup(){
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
Serial.begin(9600);}

void loop(){
int lightRaw=analogRead(ldr);
int lightPercent=map(lightRaw,0,1023,0,100);

int reading=analogRead(tempPin);
float voltage=reading*5.0/1024.0;
float tempC=(voltage-0.5)*100;

digitalWrite(trig,LOW);
delayMicroseconds(2);
digitalWrite(trig,HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
long duration=pulseIn(echo,HIGH);
long distance=(duration*0.034)/2;

Serial.println("=== SENSOR LOG ===");
Serial.print("Time : ");
Serial.print(millis());
Serial.println(" ms");
Serial.print("Temp : ");
Serial.print(tempC);
Serial.println(" C");
Serial.print("Light : ");
Serial.print(lightPercent);
Serial.println(" %");
Serial.print("Distance : ");
Serial.print(distance);
Serial.println(" cm");
Serial.println("==================");

delay(5000);}
