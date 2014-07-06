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


void setup(){
  
  noInterrupts(); //Interrupt Killer!
  
  //SetUp SPI Library
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE0);
  SPI.setClockDivider(SPI_CLOCK_DIV2);
  
  //Setup All Output pins
  DDRB |= (1<<_ENABLE) | (1<<_DATA) | (1<<_LATCH) | (1<<_CLCK);
  PORTB &= (0<<_ENABLE) | (0<<_DATA) | (0<<_LATCH) | (0<<_CLCK);
  
  PORTB |= (1<<_ENABLE);
  
  //Setup Timer 1 to Refresh Leds
  TCCR1A = B00000000;
  TCCR1B = B00001011;
  TIMSK1 = B00000010;
  OCR1A = 30;
  
  interrupts(); //Let get them multiplexing started
  PORTB &= (0<<_ENABLE);
}

void loop(){
  for(int i=0; i<8; i++){
     output = leds[i];
     delay(100);
  }
}

void latch(){
   //Latch High
  PORTB |= 1<<_LATCH;
  //Latch Low
  PORTB &= 0<<_LATCH; 
}

//------------------------------
//        TIMER FUNCTIONS
//-------------------------------
ISR(TIMER1_COMPA_vect){
  
   //
   SPI.transfer(output);
   latch();
    
}
