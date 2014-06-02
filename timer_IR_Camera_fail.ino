#define seg1 12
#define seg2 13
#define seg3 3
#define seg4 4
#define seg5 5
#define seg6 6
#define seg7 7
#define seg8 8
#define DIGIT1 9
#define DIGIT2 10 
#define DIGIT3 11
#define INPUTPIN 0
#define SHOOTPIN A0
#define INCREMENT A1
#define DECREMENT A2
#define TIMELAPSE A3
#define IRPIN A4

unsigned int seconds = 1;
unsigned int MICROPULSE =  10;
unsigned int PICTURE    =  7330;
unsigned int VIDEO      =  5360;
unsigned int INTERvAL   =  16;
unsigned int d1 = 0, d2 = 0, d3 = 0;
volatile boolean updating = false;


void setup(){
  
  setupOutputPins();
  initialise7Segment();
  setupSoftwareInterrupt();
  segementDisplay(seconds);
}



