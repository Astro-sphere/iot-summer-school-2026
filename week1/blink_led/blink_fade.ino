// C++ code
//
/* PROJECT  : led_blink
   AUTHOR   : SATYAM KUMAR
   DATE     : 2026-07-04
   Dis      : Fades an LED in and out smoothly using analogWrite (PWM)*/

  int pin = 3;
void setup()
{
pinMode (pin, OUTPUT);
}

void loop()
{
  analogWrite (pin, 10);
  delay(500);
}
  
