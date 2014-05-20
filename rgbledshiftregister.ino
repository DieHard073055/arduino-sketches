#define _DATA 5
#define _ENABLE 6
#define _CLCK 8 
#define _LATCH 7


int shiftData[] = {
  B01111111,
  B10111111,
  B11011111,
  B11101111,
  B11110111,
  B11111011,
  B11111101,
  B11111110
};


void setup(){
  pinMode(_DATA, OUTPUT);
  pinMode(_ENABLE, OUTPUT);
  pinMode(_CLCK, OUTPUT);
  pinMode(_LATCH, OUTPUT);

  
}

void loop(){
