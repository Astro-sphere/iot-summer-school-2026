/*
Project: Vending Machine State Machine
Author: SATYAM KUMAR
Desc: 4 state vending machine (idle, coin, select, dispense) with 3 buttons and 3 leds
Date: 2026-07-04

State transitions:
IDLE -> (insert coin) -> COIN_INSERTED
COIN_INSERTED -> (select item) -> ITEM_SELECTED
ITEM_SELECTED -> (auto) -> DISPENSING -> IDLE
any state -> (cancel) -> IDLE
*/

int led1=8;
int led2=9;
int led3=10;
int coinBtn=2;
int selectBtn=3;
int cancelBtn=4;

int state=0;

void setup(){
pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(coinBtn,INPUT_PULLUP);
pinMode(selectBtn,INPUT_PULLUP);
pinMode(cancelBtn,INPUT_PULLUP);
Serial.begin(9600);
Serial.println("State: IDLE");}

void loop(){
showState();

if(digitalRead(cancelBtn)==LOW){
state=0;
Serial.println("Cancelled -> IDLE");
delay(400);
return;}

if(state==0){
if(digitalRead(coinBtn)==LOW){
state=1;
Serial.println("Coin inserted -> COIN_INSERTED");
delay(400);}}

else if(state==1){
if(digitalRead(selectBtn)==LOW){
state=2;
Serial.println("Item selected -> ITEM_SELECTED");
delay(400);}}

else if(state==2){
Serial.println("Dispensing -> DISPENSING");
state=3;
delay(1000);}

else if(state==3){
Serial.println("Done -> IDLE");
state=0;
delay(500);}}

void showState(){
digitalWrite(led1,LOW);
digitalWrite(led2,LOW);
digitalWrite(led3,LOW);
if(state==0){digitalWrite(led1,HIGH);}
if(state==1){digitalWrite(led2,HIGH);}
if(state==2){digitalWrite(led2,HIGH);}
if(state==3){digitalWrite(led3,HIGH);}}
