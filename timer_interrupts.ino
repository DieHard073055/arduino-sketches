#define ledPin A4
//http://www.instructables.com/id/Arduino-Timer-Interrupts/?ALLSTEPS
void setup()
{
  pinMode(ledPin, OUTPUT);

  // initialize timer1 
  noInterrupts();           // disable all interrupts
