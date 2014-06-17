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
  int red = 0, green = 1, blue = 2;
  int length = 30;
  for (int i = 0; i < 255; ++i)
  {
    for (int j = 0; j < length; ++j)
    {
      
    ledShift(red);
    enable(255-i);
    }

    for (int j = 0; j < length; ++j)
    {
      
    
    ledShift(blue+3);
    enable(i);
    }

    for (int j = 0; j < length; ++j)
    {
    
    ledShift(blue);
    enable(i);
    }

    for (int j = 0; j < length; ++j)
    {
    ledShift(red+3);
    enable(255-i);
