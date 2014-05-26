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

