// C++ code
//
/*
 * Project: LED Fade Array
 * Author : SATYAM KUMAR
 * Date   : 2026-07-04
 * Desc   : Fades an array of LEDs in and out one by one, in sequence.
 */

int led [] ={11,10,9,6,5,3};
void setup()
{
  for (int i = 0; i < 6; i++){
  pinMode (led[i], OUTPUT);
  }
}

void loop()
{
  for (int i = 0; i < 6; i++) {
    for (int b =0; b <= 255; b++){
    analogWrite(led[i], b);
      delay (5);}
      for (int b = 255; b >=0 ; b--){
      analogWrite(led[i],b);
      delay(5);
      }}}
