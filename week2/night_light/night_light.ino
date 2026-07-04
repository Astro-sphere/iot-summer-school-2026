/*
Project: PWM Night Light
Author: SATYAM KUMAR
Desc: led breathing light with 3 modes (slow, fast, SOS) switched by a button
Date: 2026-07-04
*/

int led=9;
int button=2;
int mode=0;

void setup(){
pinMode(led,OUTPUT);
pinMode(button,INPUT_PULLUP);
Serial.begin(9600);
Serial.println("Mode 0: Slow breathing");}

void loop(){
if(digitalRead(button)==LOW){
mode=mode+1;
if(mode>2){mode=0;}
if(mode==0){Serial.println("Mode 0: Slow breathing");}
if(mode==1){Serial.println("Mode 1: Fast pulse");}
if(mode==2){Serial.println("Mode 2: SOS");}
delay(300);}

if(mode==0){breathe(15);}
if(mode==1){breathe(2);}
if(mode==2){sos();}}

void breathe(int spd){
for(int b=0;b<=255;b++){digitalWrite2(b);delay(spd);if(checkButton()){return;}}
for(int b=255;b>=0;b--){digitalWrite2(b);delay(spd);if(checkButton()){return;}}}

void digitalWrite2(int b){
analogWrite(led,b);}

void sos(){
for(int i=0;i<3;i++){blink(150);}
for(int i=0;i<3;i++){blink(450);}
for(int i=0;i<3;i++){blink(150);}
delay(600);}

void blink(int t){
analogWrite(led,255);
delay(t);
analogWrite(led,0);
delay(200);}

int checkButton(){
if(digitalRead(button)==LOW){return 1;}
return 0;}
