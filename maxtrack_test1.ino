#include <SPI.h> //Serial Peripheral Interface Library

#define _ENABLE PB2 //10
#define _DATA   PB3 //11
#define _LATCH  PB4 //12
#define _CLCK   PB5 //13

byte leds[] = {
  B10000000,
  B01000000,
  B00100000,
