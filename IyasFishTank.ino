#define red     11
#define green   10
#define blue    9

#define _DATA   4
#define _ENABLE 3
#define _LATCH  5
#define _CLCK   6

#define _BLINK_LED 13

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

int led[] = {
    B10000000,
    B01000000,
    B00100000,
    B00010000,
    B00001000,
    B00000100,
    B00000010,
    B00000001
};


int count = 0;
void setup(){
    //BLINK LED
    pinMode(_BLINK_LED, OUTPUT);

    //PWM LED PINS
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(blue, OUTPUT);

    //SHIFT REGISTER PINS
    pinMode(_DATA, OUTPUT);
    pinMode(_ENABLE, OUTPUT);
    pinMode(_LATCH, OUTPUT);
    pinMode(_CLCK, OUTPUT);

    digitalWrite(_ENABLE, LOW);

    setBrightness(7);
    ledRed(0);
    ledGreen(0);
    ledBlue(0);
}
// void loop(){
//     int delayTime = 0;

//     ledRed(255);
//     ledBlue(255);
//     ledGreen(0);
//     for(int i = 0; i < 8; i++){
//         setLed(i);
//         delay(delayTime);
//     }
// }
void loop(){
    int delayTime = 100;
   
    blink();
   for (int i = 0; i < 255; i+=10){
        ledRed(0);
        ledGreen(i);
        ledBlue(255);
        delay(delayTime);
   }
   blink();
   for (int i = 0; i < 255; i+=10){
        ledRed(0);
        ledGreen(255);
        ledBlue(255-i);
        delay(delayTime);
   }
   blink();
   //2 - Red Goes up and Green Goes down
   for (int i = 0; i < 255; i+=10){
        ledRed(i);
        ledGreen(255);
        ledBlue(0);
        delay(delayTime);
   }
   blink();
   for (int i = 0; i < 255; i+=10){
        ledRed(255);
        ledGreen(255-i);
        ledBlue(0);
        delay(delayTime);
   }
   blink();
