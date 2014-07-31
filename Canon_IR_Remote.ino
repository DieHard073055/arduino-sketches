
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
   digitalWrite(DIGIT3, LOW);
   Serial.println("Interrupts Attached");
   attachInterrupt(INPUTPIN, buttonPressed, RISING);
}
void loop(){
  digitalWrite(DIGIT3, LOW);
    digitalWrite(DIGIT1, HIGH);
    number(d1);
    clearSegment();
    digitalWrite(DIGIT1, LOW);
    digitalWrite(DIGIT2, HIGH);
    number(d2);
    clearSegment();
    digitalWrite(DIGIT2, LOW);
    digitalWrite(DIGIT3, HIGH);
    number(d3);
    clearSegment();
}

void buttonPressed(){
  if(!hardware_interrupt){
     hardware_interrupt = true;
     Serial.println("Button pressed");
      
     if(digitalRead(SHOOTPIN)){
        camera(PICTURE);
        Serial.println(digitalRead(SHOOTPIN));
     }
     else if(digitalRead(INCREMENT)){
        displayNum++;
        Serial.println(digitalRead(INCREMENT));
     }
     else if(digitalRead(DECREMENT)){
        displayNum--;
        Serial.println(digitalRead(DECREMENT));
     }
     else if(digitalRead(TIMELAPSE)){
        //Start Timelapse
        Serial.println(digitalRead(TIMELAPSE));
     }
    segementDisplay(displayNum);
    Serial.println(displayNum);
    hardware_interrupt = false;
  }
}

void camera(unsigned int mode){
 
 for(int i=0; i<INTERvAL; i++){
    digitalWrite(IRPIN, HIGH);
    delayMicroseconds(MICROPULSE);
    digitalWrite(IRPIN, LOW);
    delayMicroseconds(MICROPULSE);  
 }
 
 
 delayMicroseconds(mode);
 
 
 for(int i=0; i<INTERvAL; i++){
    digitalWrite(IRPIN, HIGH);
    delayMicroseconds(MICROPULSE);
    digitalWrite(IRPIN, LOW);
    delayMicroseconds(MICROPULSE);
 }
}
void segementDisplay(int disNum){
   int num = disNum;
   d1=0;
   d2=0;
   d3=0;
   if(num < 10){
      d3 = num;
   }
