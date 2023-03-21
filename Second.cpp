#include "Second.h"
#include <Arduino.h>

void second_funct(unsigned char tens, unsigned char unit)
{
//    unsigned char unit = second_data % 10;
//    unsigned char tens = second_data / 10;
  PORTB = B00010000;
  PORTC = B00000000;
  PORTD = B00000000;
  switch (tens) {
    case 0:
      PORTC = B00000000;
      PORTD = B11111100;
      break;
    case 1:
      PORTC = B00000000;
      PORTD = B11000000;
      break;
    case 2:
      PORTC = B00000100;
      PORTD = B01101100;
      break;
    case 3:
      PORTC = B00000100;
      PORTD = B11100100;
      break;
    case 4:
      PORTC = B00000100;
      PORTD = B11010000;
      break;
    case 5:
      PORTC = B00000100;
      PORTD = B10110100;
      break;
  }
  delay(3);
  PORTB = B00000000;
  PORTB = B00010100;
  switch (unit) {
    case 0:
      PORTC = B00000000;
      PORTD = B11111100;
      break;
    case 1:
      PORTC = B00000000;
      PORTD = B00011000;
      break;
    case 2:
      PORTC = B00000100;
      PORTD = B01101100;
      break;
    case 3:
      PORTC = B00000100;
      PORTD = B00111100;
      break;
    case 4:
      PORTC = B00000100;
      PORTD = B10011000;
      break;
    case 5:
      PORTC = B00000100;
      PORTD = B10110100;
      break;
    case 6:
      PORTC = B00000100;
      PORTD = B11110100;
      break;
    case 7:
      PORTC = B00000000;
      PORTD = B00011100;
      break;
    case 8:
      PORTC = B00000100;
      PORTD = B11111100;
      break;
    case 9:
      PORTC = B00000100;
      PORTD = B10111100;
      break;
  }
  delay(3);
  PORTB = B00000000;
  PORTC = B00000000;
  PORTD = B00000000;
}
