/*
Project: 4x4 LED Matrix
Author: SATYAM KUMAR
Desc: lights each led one by one, then shows a letter, on a scanned 4x4 matrix
Date: 2026-07-04
*/

int rows[4]={2,3,4,5};
int cols[4]={6,7,8,9};

int letter[4][4]={
{1,1,1,1},
{1,1,0,0},
{0,0,1,1},
{1,1,1,1}};

void setup(){
for(int i=0;i<4;i++){
pinMode(rows[i],OUTPUT);
pinMode(cols[i],OUTPUT);
digitalWrite(rows[i],LOW);
digitalWrite(cols[i],HIGH);}

sweepAll();}

void sweepAll(){
for(int r=0;r<4;r++){
for(int c=0;c<4;c++){
digitalWrite(cols[c],LOW);
digitalWrite(rows[r],HIGH);
delay(150);
digitalWrite(rows[r],LOW);
digitalWrite(cols[c],HIGH);}}
delay(300);}

void loop(){
for(int r=0;r<4;r++){
for(int c=0;c<4;c++){
if(letter[r][c]==1){digitalWrite(cols[c],LOW);}
else{digitalWrite(cols[c],HIGH);}}
digitalWrite(rows[r],HIGH);
delay(2);
digitalWrite(rows[r],LOW);}}
