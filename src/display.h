#pragma once

#include <Arduino.h>

class SevenSegmentDisplay 
{
  public:
    SevenSegmentDisplay(int a, int b, int c, int d, int e, int f, int g);

    void begin();
    void write(int num);
    void off();

  private:
    int _pins[7];
    void setSegments(bool segments[7]);
};
