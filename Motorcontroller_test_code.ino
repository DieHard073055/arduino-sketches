#define _DATA 5
#define _ENABLE 6
#define _CLCK 8
#define _LATCH 7

#define STATUS 13

int shdata[] = {
    B10000000,
    B01000000,
    B00100000,
    B00010000,
    B00001000,
    B00000100,
    B00000010,
    B00000001
};

void setup(){
  pinMode(_DATA, OUTPUT);
  pinMode(_CLCK, OUTPUT);
