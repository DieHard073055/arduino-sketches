#define red     9
#define green   10
#define blue    11

#define _DATA   4
#define _LATCH  7
#define _CLCK   8


int brightnessLevel[] = {
    B10000000,
    B11000000,
    B11100000,
    B11110000,
    B11111000,
    B11111100,
    B11111110,
    B11111111
};
int count = 0;
void setup(){
    //PWM LED PINS
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);

    //SHIFT REGISTER PINS
    pinMode(_DATA, OUTPUT);
    pinMode(_LATCH, OUTPUT);
    pinMode(_CLCK, OUTPUT);

    setBrightness(7);
    ledRed(0);
    ledGreen(0);
    ledBlue(0);
}
void loop(){
    int delayTime = 100;
   

   for (int i = 0; i < 255; i+=10){
        ledRed(0);
        ledGreen(i);
        ledBlue(255);
        delay(delayTime);
   }
   for (int i = 0; i < 255; i+=10){
        ledRed(0);
        ledGreen(255);
        ledBlue(255-i);
        delay(delayTime);
   }
   //2 - Red Goes up and Green Goes down
   for (int i = 0; i < 255; i+=10){
        ledRed(i);
        ledGreen(255);
        ledBlue(0);
        delay(delayTime);
   }
   for (int i = 0; i < 255; i+=10){
        ledRed(255);
        ledGreen(255-i);
        ledBlue(0);
        delay(delayTime);
   }
   //3 - Blue Goes up red is HIGH
   for (int i = 0; i < 255; i+=10){
        ledRed(255);
        ledGreen(0);
        ledBlue(i);
        delay(delayTime);
   }
   //4 - Green Goes up
   for (int i = 0; i < 255; i+=10){
        ledRed(255);
        ledGreen(i);
        ledBlue(255);
        delay(delayTime);
   }
   //5 - red goes down
   for (int i = 0; i < 255; i+=10){
        ledRed(255-i);
        ledGreen(255);
        ledBlue(255);
        delay(delayTime);
   }
   //6 - Blue Goes down
   for (int i = 0; i < 255; i+=10){
        ledRed(0);
        ledGreen(255);
        ledBlue(255-i);
        delay(delayTime);
   }

