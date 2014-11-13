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
}

/*********************************************
         UPDATE SEVEN SEGMENT DISPLAY
**********************************************/

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
    clearSegment();
    digitalWrite(DIGIT2, LOW);
    digitalWrite(DIGIT3, HIGH);
    number(d3);
    clearSegment(); 
    updating = false;
  }
}

/*********************************************
         INTI SEVEN SEGMENT DISPLAY
**********************************************/
void initialise7Segment(){
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
}





/*********************************************
         SETUP SOFTWARE TIMER
               INTERRUPT
**********************************************/
void setupSoftwareInterrupt(){
  // initialize timer1 
  cli();          // disable all interrupts
   
  TCCR1A = 0;
  TCCR1B = 0;

  TCNT1 = 34268;            // preload timer 65536-16MHz/256/2Hz
  TCCR1B |= (1 << CS10) ;   //prescale at clck/8
  TIMSK1 |= (1 << TOIE1);   // enable timer overflow interrupt
  
              // enable all interrupts
  sei();
}

/*********************************************
         TIMER INTERRUPT FUNCTION
**********************************************/

ISR(TIMER1_OVF_vect)        
{
            
  updateDisplay();
  updateDisplay();
  updateDisplay();
  updateDisplay();
  updateDisplay();
  updateDisplay();
  updateDisplay();
  updateDisplay();
  updateDisplay();
  updateDisplay();
  
}

/*********************************************
         SEVEN SEGMENT CALCULATION
**********************************************/
void segementDisplay(int disNum){
   int num = disNum;
   d1=0;
   d2=0;
   d3=0;
   if(num < 10){
      d3 = num;
   }
   else if(num > 9 && num < 100){
      d2 = num / 10;
      d3 = num - (d2 * 10);
   }
   else if(num > 99){
      d1 = num / 100;
      d2 = ((num/10) - (d1 * 10));
      d3 = (num - (d1 * 100)) - (d2 * 10) ;
   } 
}

/*********************************************
       SEVEN SEGMENT REFERENCE TABLE
**********************************************/
void number(int digit){
   switch(digit){
      case 0:
        segment(seg1);
        segment(seg2);
        segment(seg3);
        segment(seg5);
        segment(seg6);
        segment(seg7);
       break;
       case 1:
        segment(seg3);
        segment(seg6);
       break;
      case 2:
        segment(seg2);
        segment(seg3);
        segment(seg4);
        segment(seg5);
        segment(seg7);
       break;
      case 3:
        segment(seg2);
        segment(seg3);
        segment(seg4);
        segment(seg6);
        segment(seg7);
       break;
      case 4:
        segment(seg1);
        segment(seg3);
        segment(seg4);
        segment(seg6);
       break;
      case 5:
        segment(seg1);
        segment(seg2);
        segment(seg4);
        segment(seg6);
        segment(seg7);
       break;
      case 6:
        segment(seg1);
        segment(seg2);
        segment(seg4);
        segment(seg5);
        segment(seg6);
        segment(seg7);
       break;
      case 7:
        segment(seg1);
        segment(seg2);
        segment(seg3);
        segment(seg6);
       break;
      case 8:
        segment(seg1);
        segment(seg2);
        segment(seg3);
        segment(seg4);
        segment(seg5);
        segment(seg6);
        segment(seg7);
       break;
      case 9:
        segment(seg1);
        segment(seg2);
        segment(seg3);
        segment(seg4);
        segment(seg6);
        segment(seg7);
       break;
       
   }
}

/*********************************************
         SEGMENT SELECTOR FUNCTION
**********************************************/
void segment(int num){
    digitalWrite(num, LOW);
}
