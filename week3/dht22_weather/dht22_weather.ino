/*
Project: DHT22 Weather Station
Author: SATYAM KUMAR
Desc: reads temperature and humidity on esp32, shows values on serial and warns with leds
Date: 2026-07-04
*/

#include <DHT.h>

int dhtPin=15;
int red=2;
int green=4;

DHT dht(dhtPin,DHT22);

void setup(){
Serial.begin(115200);
dht.begin();
pinMode(red,OUTPUT);
pinMode(green,OUTPUT);}

void loop(){
float temp=dht.readTemperature();
float hum=dht.readHumidity();

Serial.print("Temp: ");
Serial.print(temp);
Serial.print(" C | Humidity: ");
Serial.print(hum);
Serial.println(" %");

if(temp>35 || hum>80){
digitalWrite(red,HIGH);
digitalWrite(green,LOW);}
else{
digitalWrite(green,HIGH);
digitalWrite(red,LOW);}

delay(2000);}
