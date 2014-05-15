#include <Servo.h>


//Reference Constants
#define MOTOR 1
#define LIGHT 2
#define AIRCOND 3

#define CURTAIN_1 10
#define CURTAIN_2 11

#define DELAY 1000

#define LDR A5
#define LED 9

Servo curtain_2;


//Input values
int actuator = 0;
int act_num = 0;
int value = 0;

