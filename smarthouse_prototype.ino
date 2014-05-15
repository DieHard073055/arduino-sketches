#include <Servo.h>

#define _SERVO_1 11
#define _SERVO_2 10
#define led1    5
#define led2    3
#define led3    6
#define led4    9

Servo s1, s2;
int houseStats[6] = {0, 0, 0, 0, 0, 0};

void setup(){
    
    Serial.begin(115200);

    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
