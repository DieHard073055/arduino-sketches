#define _DATA 5
#define _ENABLE 6
#define _CLCK 8
#define _LATCH 7

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
int d = 0;

void out(char* message){
   Serial.println(message); 
}

void setup(){
  Serial.begin(9600);
  out("System Initiated");
  pinMode(_DATA, OUTPUT);
  pinMode(_CLCK, OUTPUT);
