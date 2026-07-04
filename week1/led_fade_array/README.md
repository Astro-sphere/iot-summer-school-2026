# LED Fade (Array)

Practical Q1. An array of LEDs that fade in and out one by one.
LED 1 fades in, then out, then LED 2, and so on.

![Circuit](Circuit.png)

## Components
- Arduino UNO, LEDs, 220 ohm resistors, breadboard, jumper wires

## How it works
The LED pins are stored in an array. A loop goes through each LED and
fades it in (brightness 0 to 255) then out (255 to 0) using analogWrite.

## Output
Each LED smoothly fades in and out in turn, one after another, on repeat.

## Note
analogWrite only works on ~ pins (3, 5, 6, 9, 10, 11), so I used those.
