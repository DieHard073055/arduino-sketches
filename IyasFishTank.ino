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
