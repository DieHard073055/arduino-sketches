
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

unsigned int MICROPULSE =  10;
unsigned int PICTURE    =  7330;
unsigned int VIDEO      =  5360;
unsigned int INTERvAL   =  16;

int displayNum = 100;
int d1=0, d2=0, d3=0;
volatile int led = LOW;
volatile bool hardware_interrupt = false;
volatile bool software_interrupt = false;


void setup(){
  Serial.begin(9600);
  //Interrupts settings
//  noInterrupts();//Stop interrupts for the setup
//  TCCR1A = B00000000;
//  TCCR1B = B0000101
  
  
  for(int i =0; i < 14; i++){
    pinMode(i, OUTPUT);
  }
   pinMode(IRPIN, OUTPUT);
   
   digitalWrite(seg1, HIGH);
   digitalWrite(seg2, HIGH);
   digitalWrite(seg3, HIGH);
   digitalWrite(seg4, HIGH);
   digitalWrite(seg5, HIGH);
   digitalWrite(seg6, HIGH);
   digitalWrite(seg7, HIGH);
   digitalWrite(seg8, HIGH);
   digitalWrite(DIGIT1, LOW);
   digitalWrite(DIGIT2, LOW);
