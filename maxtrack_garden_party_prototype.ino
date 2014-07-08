#define _DATA 5
#define _ENABLE 6
#define _CLCK 8
#define _LATCH 7

#define RESET         0
#define CURTAIN_UP    1
#define CURTAIN_DOWN  2
#define LIGHT         3

int shiftData[] = {
  B00000000,
  B10000000,
  B01000000,
  B00100000,
  B00010000,
  B00001000,
  B00000100,
  B00000010,
  B00000001
};
int d = shiftData[RESET];
unsigned long lastCurtainChange = 0;
void out(char* message){
   Serial.println(message); 
}
void iout(byte m){
  Serial.println(m); 
}

void setup(){
  pinMode(_ENABLE, OUTPUT);
  Serial.begin(9600);
  pinMode(_DATA, OUTPUT);
  pinMode(_CLCK, OUTPUT);
  pinMode(_LATCH, OUTPUT);
  digitalWrite(_ENABLE, LOW);
  
  latchDataOut();
  
  out("System Initiated");
  out("Data : ");
  iout((d));
  out(" ");
}

void loop(){
  
  if(Serial.available()){
    int choice = Serial.read()-48;
    iout(choice);
     switch(choice){
        case RESET:
          out("RESET");
          d = shiftData[RESET];
          latchDataOut();
          break;
         
        case 1:
          //curtain 1 up
          out("CURTAIN UP");
          lastCurtainChange = millis();
          d |= shiftData[CURTAIN_UP];
          latchDataOut();
          break;
        case 2:
          //curtain 1 down
          out("CURTAIN DOWN");
          lastCurtainChange = millis();
          d |= shiftData[CURTAIN_DOWN];
          latchDataOut();
          break;
        case 3:
        //curtain 1 stop
        out("CURTAIN STOP");
          lastCurtainChange = millis();
          d |= shiftData[CURTAIN_UP];
          d |= shiftData[CURTAIN_DOWN];
          latchDataOut();
          break;
        case 4:
        //Light 1 on
        out("LIGHTS ON");
          d |= shiftData[LIGHT];
          latchDataOut();
          break;
        case 5:
