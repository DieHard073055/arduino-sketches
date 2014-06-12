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
    pinMode(13, OUTPUT);


    s1.attach(_SERVO_1);
    s2.attach(_SERVO_2);

    s1.write(0);
    s2.write(0);

}
void loop(){

    /*
        house stats
        Door 1 {Open : 1, Closed : 0},
        Door 2 {Open : 1, Closed : 0},
        Led 1 {Full Power: 2, Half Power : 1, Off : 0}
        Led 2 {Full Power: 2, Half Power : 1, Off : 0}
        Led 3 {Full Power: 2, Half Power : 1, Off : 0}
        Led 4 {Full Power: 2, Half Power : 1, Off : 0}

    */

    while(Serial.available() > 0){
        byte a = Serial.read();
        Serial.println(a);
        switch(a){
