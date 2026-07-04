/*
Project: Serial Command Interface
Author: SATYAM KUMAR
Desc: reads typed commands over serial and controls the led (LED_ON, LED_OFF, BLINK_X, STATUS, RESET)
Date: 2026-07-04
*/

int led=13;
int ledState=0;
int blinkCount=0;

void setup(){
pinMode(led,OUTPUT);
Serial.begin(9600);
Serial.println("Enter command:");}

void loop(){
if(Serial.available()>0){
String cmd=Serial.readStringUntil('\n');
cmd.trim();

if(cmd=="LED_ON"){
digitalWrite(led,HIGH);
ledState=1;
Serial.println("LED turned ON");}

else if(cmd=="LED_OFF"){
digitalWrite(led,LOW);
ledState=0;
Serial.println("LED turned OFF");}

else if(cmd.startsWith("BLINK_")){
int n=cmd.substring(6).toInt();
if(n>=1 && n<=9){
for(int i=0;i<n;i++){
digitalWrite(led,HIGH);
delay(300);
digitalWrite(led,LOW);
delay(300);}
blinkCount=blinkCount+n;
Serial.print("Blinked ");
Serial.print(n);
Serial.println(" times");}
else{Serial.println("ERROR: Blink number must be 1 to 9");}}

else if(cmd=="STATUS"){
Serial.print("LED state: ");
if(ledState==1){Serial.println("ON");}
else{Serial.println("OFF");}
Serial.print("Total blinks: ");
Serial.println(blinkCount);}

else if(cmd=="RESET"){
blinkCount=0;
Serial.println("Blink counter reset");}

else{Serial.println("ERROR: Unknown command");}}}
