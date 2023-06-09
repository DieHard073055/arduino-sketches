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
   //3 - Blue Goes up red is HIGH
   for (int i = 0; i < 255; i+=10){
        ledRed(255);
        ledGreen(0);
        ledBlue(i);
        delay(delayTime);
   }
   blink();
   //4 - Green Goes up
   for (int i = 0; i < 255; i+=10){
        ledRed(255);
        ledGreen(i);
        ledBlue(255);
        delay(delayTime);
   }
   blink();
   //5 - red goes down
   for (int i = 0; i < 255; i+=10){
        ledRed(255-i);
        ledGreen(255);
        ledBlue(255);
        delay(delayTime);
   }
   blink();
   //6 - Blue Goes down
   for (int i = 0; i < 255; i+=10){
        ledRed(0);
        ledGreen(255);
        ledBlue(255-i);
        delay(delayTime);
   }
   blink();

   //7 - red goes up green goes down 
   for (int i = 0; i < 255; i+=10){
        ledRed(i);
        ledGreen(255-i);
        ledBlue(0);
        delay(delayTime);
   }
   blink();
   //7 - blue goes up red goes down 
   for (int i = 0; i < 255; i+=10){
        ledRed(255-i);
        ledGreen(0);
        ledBlue(i);
        delay(delayTime);
   }

}


void setBrightness(int level){
    if(level < 8 && level > 0){
        digitalWrite(_LATCH, LOW);
        shiftOut(_DATA, _CLCK, LSBFIRST, brightnessLevel[level]);
        digitalWrite(_LATCH, HIGH);
    }
}

void setLed(int val){
    if(val < 8 && val > 0){
        digitalWrite(_LATCH, LOW);
        shiftOut(_DATA, _CLCK, LSBFIRST, led[val]);
        digitalWrite(_LATCH, HIGH);
    }
}
void ledRed(int val){
    val = map(val, 0, 255, 0, 210);
    val = 255-val;
    analogWrite(red, val);
}

void ledGreen(int val){
    val = map(val, 0, 255, 0, 230);
    val = 255-val;
    analogWrite(green, val);
}

void ledBlue(int val){
    val = 255-val;
    analogWrite(blue, val);
}

void blink(){
    digitalWrite(_BLINK_LED, HIGH);
    delay(100);
    digitalWrite(_BLINK_LED, LOW);
}


