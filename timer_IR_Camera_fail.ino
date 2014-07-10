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




void loop(){
  if(digitalRead(SHOOTPIN) == HIGH){
     delayMicroseconds(5000000000);
      delayMicroseconds(5000000000);
      delayMicroseconds(5000000000);
     camera(PICTURE); 
  }
  else if(digitalRead(INCREMENT)){
      delayMicroseconds(5000000000);
      delayMicroseconds(5000000000);
      delayMicroseconds(5000000000);
      seconds++;
      
      if(seconds > 999) seconds = 999;
      segementDisplay(seconds);
   }
   else if(digitalRead(DECREMENT)){
      delayMicroseconds(5000000000);
      delayMicroseconds(5000000000);
      delayMicroseconds(5000000000);
      seconds--;
      
      if(seconds < 1) seconds = 1;
      segementDisplay(seconds);
      
   }
   else if(digitalRead(TIMELAPSE)){
      delayMicroseconds(500);
      while(1){
         for(int i = 0; i < seconds; i++){
           segementDisplay(i); 
           for(int j=0;j<35;j++)
             delayMicroseconds(5000000000);
           
         } 
         camera(PICTURE);
      }
   }
}


void setupOutputPins(){
 for(int i =0; i < 14; i++){
    pinMode(i, OUTPUT);
  }
   pinMode(IRPIN, OUTPUT); 
}

void updateDisplay(){
  if(!updating){
    updating = true;
    digitalWrite(DIGIT3, LOW);
    digitalWrite(DIGIT1, HIGH);
    number(d1);
    clearSegment();
    digitalWrite(DIGIT1, LOW);
    digitalWrite(DIGIT2, HIGH);
    number(d2);
