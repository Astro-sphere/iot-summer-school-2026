// C++ code
// 
/* PROJECT  : led_blink
   AUTHOR   : SATYAM KUMAR
   DATE     : 2026-07-04
   Dis      : Blinks an LED on pin 13 on and off once per second using digitalWrite */


int pin = 13; //i defined a variable int for integer value named ledPin for = pin 13
void setup()
{
  pinMode (pin,OUTPUT); //pinMode tell the role of pin output or input, either push the 5v current or take some
}

void loop()
{
  digitalWrite (pin, HIGH);
  delay(500);
  //digitalWrite here digital means two state high or loww , high give 5v other gves 0v nothing in between
   //delay to give time for the next line of code to execte
  digitalWrite (pin, LOW);
  delay(500);
   // with delay on off will be visible otherwise it will be continuos 
}
  
