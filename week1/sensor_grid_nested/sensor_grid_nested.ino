/*
Project: Sensor Grid Nested Loops
Author: SATYAM KUMAR
Desc: prints a grid of sensor labels using nested loops
Date: 2026-07-04
*/

void setup(){
Serial.begin(9600);

for(int r=1;r<=4;r++){
for(int c=1;c<=3;c++){
Serial.print("Sensor(");
Serial.print(r);
Serial.print(",");
Serial.print(c);
Serial.print(")");
Serial.print("  ");}
Serial.println();}}

void loop(){}
