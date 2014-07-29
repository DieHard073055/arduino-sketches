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
#define IRSIGNALPIN A4
#define IRSIGNALPIN2 A5
#define INPUTPIN 0
#define SHOOTPIN A0
#define INCREMENT A1
#define DECREMENT A2
#define TIMELAPSE A3

unsigned int seconds = 1;
unsigned int d1 = 0, d2 = 0, d3 = 0;
volatile boolean updating = false;


/*********************************************
         INIT FUNCTION 
         -------------
     -setup all the output pins
     -Initialise the seven segment display
     -Setup software interrupt
     -Display current seconds        
**********************************************/

void setup(){
  setupOutputPins();
  initialise7Segment();
  setupSoftwareInterrupt();
  segementDisplay(seconds);
}


/*********************************************
         MAIN FUNCTION 
         -------------
         - Handle User input
         - Handle switch debounce         
**********************************************/

void loop(){
  if(digitalRead(SHOOTPIN) == HIGH){
     delayMicroseconds(5000000000);
      delayMicroseconds(5000000000);
      delayMicroseconds(5000000000);
     toggleIr(); 
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
        toggleIr();
             
         for(int i = 0; i < seconds; i++){
           segementDisplay(i); 
           for(int j=0;j<35;j++)
             delayMicroseconds(5000000000);
           
         } 
         
      }
   }
}


/*********************************************
              Ir Signal
**********************************************/
void toggleIr(){
  digitalWrite(IRSIGNALPIN, HIGH);
  delay(100);
  digitalWrite(IRSIGNALPIN, LOW);
}
/*********************************************
              Ir Signal2
**********************************************/
void toggleIr2(){
  digitalWrite(IRSIGNALPIN2, HIGH);
  delay(100);
  digitalWrite(IRSIGNALPIN2, LOW);
}

/*********************************************
              SETUP PIN OUTS
**********************************************/
void setupOutputPins(){
 for(int i =0; i < 14; i++){
    pinMode(i, OUTPUT);
  }
   pinMode(IRSIGNALPIN, OUTPUT); 
