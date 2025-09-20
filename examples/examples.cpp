#include <Arduino.h>
#include "display.h"

// Pines conectados al display: a, b, c, d, e, f, g
SevenSegmentDisplay display(2, 3, 4, 5, 6, 7, 8);

void setup() 
{
  display.begin();
}

void loop() 
{
  for (int i = 0; i <= 9; i++) 
  {
    display.write(i);
    delay(1000);
  }
  display.off();
  delay(2000);
}