#include <Arduino.h>
#include "display.h"

// Constructor: asigna los pines a cada segmento (a, b, c, d, e, f, g)
SevenSegmentDisplay::SevenSegmentDisplay(int a, int b, int c, int d, int e, int f, int g) 
{
  _pins[0] = a;
  _pins[1] = b;
  _pins[2] = c;
  _pins[3] = d;
  _pins[4] = e;
  _pins[5] = f;
  _pins[6] = g;
}

// Inicializa los pines como salida
void SevenSegmentDisplay::begin() 
{
  for (int i = 0; i < 7; i++) 
  {
    pinMode(_pins[i], OUTPUT);
    digitalWrite(_pins[i], LOW); // Apagado al inicio (cátodo común)
  }
}

// Apaga todos los segmentos
void SevenSegmentDisplay::off() 
{
  for (int i = 0; i < 7; i++) {
    digitalWrite(_pins[i], LOW);
  }
}

// Muestra un número del 0 al 9
void SevenSegmentDisplay::write(int num) 
{
  static bool digits[10][7] = {
    // a, b, c, d, e, f, g
    {1,1,1,1,1,1,0}, // 0
    {0,1,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,1}, // 2
    {1,1,1,1,0,0,1}, // 3
    {0,1,1,0,0,1,1}, // 4
    {1,0,1,1,0,1,1}, // 5
    {1,0,1,1,1,1,1}, // 6
    {1,1,1,0,0,0,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}  // 9
  };

  if (num < 0 || num > 9) 
  {
    off();
    return;
  }

  setSegments(digits[num]);
}

// Función auxiliar para activar los pines de un número
void SevenSegmentDisplay::setSegments(bool segments[7]) 
{
  for (int i = 0; i < 7; i++) 
  {
    digitalWrite(_pins[i], segments[i] ? HIGH : LOW);
  }
}
