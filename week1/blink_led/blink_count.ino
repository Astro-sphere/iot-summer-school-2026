// C++ code

/* PROJECT : LED_BLINK
   AUTHOR  : SATYAM KUMAR
   DATE    : 2026-07-04
   DESC    :   LED brightness up with a counting for-loop (0 to 255)*/

//
int pin = 9;
void setup()
{
  pinMode (pin, OUTPUT);
}

void loop()
{
  for (int b = 0; b <= 255; b++){
  analogWrite(pin, b);
    delay(5); }
}
