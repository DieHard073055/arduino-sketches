#define ledPin A4
//http://www.instructables.com/id/Arduino-Timer-Interrupts/?ALLSTEPS
void setup()
{
  pinMode(ledPin, OUTPUT);

  // initialize timer1 
  noInterrupts();           // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = 34268;            // preload timer 65536-16MHz/256/2Hz
  TCCR1B |= (1 << CS01) | (1 << CS00); //| (1 << CS11);    // 256 prescaler 
