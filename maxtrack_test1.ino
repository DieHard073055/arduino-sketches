#include <SPI.h> //Serial Peripheral Interface Library

#define _ENABLE PB2 //10
#define _DATA   PB3 //11
#define _LATCH  PB4 //12
#define _CLCK   PB5 //13

byte leds[] = {
  B10000000,
  B01000000,
  B00100000,
  B00010000,
  B00001000,
  B00000100,
  B00000010,
  B00000001,
  B00000000
};


byte output = B00000000;
