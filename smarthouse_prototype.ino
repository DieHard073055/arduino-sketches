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

            //------ Door 1 ----------
            case 1:
                houseStats[0] = 0;
            break;

            case 2:
                houseStats[0] = 1;
            break;


            //------ Door 2 ----------
            case 3:
                houseStats[1] = 0;
            break;

            case 4:
                houseStats[1] = 1;
            break;

            //------ Led 1 ----------
            case 5:
                houseStats[2] = 0;
            break;

            case 6:
                houseStats[2] = 1;
            break;

            case 7:
                houseStats[2] = 2;
            break;

            //------ Led 2 ----------
            case 8:
                houseStats[3] = 0;
            break;

            case 9:
                houseStats[3] = 1;
            break;

            case 10:
                houseStats[3] = 2;
            break;

            //------ Led 3 ----------
            case 11:
                houseStats[4] = 0;
            break;

            case 12:
                houseStats[4] = 1;
            break;

            case 13:
                houseStats[4] = 2;
            break;

            //------ Led 4 ----------
            case 14:
                houseStats[5] = 0;
            break;

            case 15:
                houseStats[5] = 1;
            break;

            case 16:
                houseStats[5] = 2;
            break;
        }
        updateHouse();
    }
    


    
    // int delayTime = 1500;
    
    // s1.write(180);
    // s2.write(180);
    // digitalWrite(led1, HIGH);
    // digitalWrite(led2, HIGH);
    // digitalWrite(led3, HIGH);
    // digitalWrite(led4, HIGH);

    // delay(delayTime);

    // s1.write(0);
    // s2.write(0);
    // digitalWrite(led1, LOW);
    // digitalWrite(led2, LOW);
    // digitalWrite(led3, LOW);
    // digitalWrite(led4, LOW);

    // delay(delayTime);

}



void updateHouse(){
    for(int i = 0; i < 6; i++){

        switch(i){
            case 0:
                if(houseStats[i] == 0){
                    s1.write(0);
                }else{
                    s1.write(180);
                }
            break;
    
            case 1:
                if(houseStats[i] == 0){
                    s2.write(0);
                }else{
                    s2.write(180);
                }
            break;
    
            case 2:
                if(houseStats[i] == 0){
                    digitalWrite(led1, HIGH);
                }else if(houseStats[i] == 1){
                    analogWrite(led1, 127);
                }else{
                    digitalWrite(led1, LOW);
                }
            break;
    
            case 3:
                if(houseStats[i] == 0){
                    digitalWrite(led2, HIGH);
                }else if(houseStats[i] == 1){
                    analogWrite(led2, 127);
                }else{
                    digitalWrite(led2, LOW);
                }
            break;
    
