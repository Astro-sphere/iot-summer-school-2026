/*
Project: Keypad LCD Password System
Author: SATYAM KUMAR
Desc: enter a 4 digit pin on keypad, lcd shows access granted or denied, locks after 3 wrong tries
Date: 2026-07-04
*/

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int green=2;
int red=4;
int buzzer=15;

String password="1234";
String input="";
int wrong=0;

byte rows=4;
byte cols=4;
char keys[4][4]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}};
byte rowPins[4]={13,12,14,27};
byte colPins[4]={26,25,33,32};

Keypad keypad=Keypad(makeKeymap(keys),rowPins,colPins,rows,cols);

void setup(){
lcd.init();
lcd.backlight();
pinMode(green,OUTPUT);
pinMode(red,OUTPUT);
pinMode(buzzer,OUTPUT);
lcd.setCursor(0,0);
lcd.print("ENTER PIN:");}

void loop(){
char key=keypad.getKey();

if(key){
if(key=='#'){
if(input==password){
lcd.clear();
lcd.print("ACCESS GRANTED");
digitalWrite(green,HIGH);
delay(2000);
digitalWrite(green,LOW);
wrong=0;}
else{
lcd.clear();
lcd.print("ACCESS DENIED");
digitalWrite(red,HIGH);
tone(buzzer,1000);
delay(1000);
noTone(buzzer);
digitalWrite(red,LOW);
wrong=wrong+1;

if(wrong>=3){
lcd.clear();
lcd.print("LOCKED 10s");
delay(10000);
wrong=0;}}

input="";
lcd.clear();
lcd.print("ENTER PIN:");}

else{
input=input+key;
lcd.setCursor(0,1);
lcd.print(input);}}}
