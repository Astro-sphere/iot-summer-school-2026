/*
Project: Seven Segment Display
Author: SATYAM KUMAR
Desc: shows digits 0 to 9 on a common cathode 7 segment display
Date: 2026-07-04
*/

int seg[7]={4,5,7,8,9,3,2};

int nums[10][7]={
{1,1,1,1,1,1,0},
{0,1,1,0,0,0,0},
{1,1,0,1,1,0,1},
{1,1,1,1,0,0,1},
{0,1,1,0,0,1,1},
{1,0,1,1,0,1,1},
{1,0,1,1,1,1,1},
{1,1,1,0,0,0,0},
{1,1,1,1,1,1,1},
{1,1,1,1,0,1,1}};

void setup(){
for(int i=0;i<7;i++){pinMode(seg[i],OUTPUT);}}

void loop(){
for(int d=0;d<10;d++){
for(int i=0;i<7;i++){digitalWrite(seg[i],nums[d][i]);}
delay(1000);}}
