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

//Variable Selector
int currentVariable = 0;

//Variable to add values
String inputString = "";

void setup(){
    Serial.begin(9600);
    
    //Serial.println("Initiating System ...");
    
    pinMode(CURTAIN_1, OUTPUT);
    //Serial.println("Motor 1 attached ...");
    
    curtain_2.attach(CURTAIN_2);
    //Serial.println("Motor 2 attached ...");
    
    //Serial.println("Motors Initialised ...");
    curtain_2.write(0);
    
    //Serial.println("Led Initialised");
    pinMode(LED, OUTPUT);
    
}

void loop(){
    int input;
      if (Serial.available() > 0) {
        input = Serial.read();
      }
    
      if (isDigit(input)) {
        inputString += (char)input; 
      }
    
      if (input == '-') {
        switch (currentVariable) {
        case 0:    
          actuator = inputString.toInt();
          inputString = ""; 
          break;
        case 1:   
          act_num = inputString.toInt();
          inputString = ""; 
          break;
          
        case 2:
          value = inputString.toInt();
          inputString = ""; 
          break;
        }
        currentVariable++;
        if(currentVariable == 3){
           currentVariable = 0; 
           Serial.flush();

           actuatorController(actuator, act_num, value);
                     
           Serial.print("Actuator : ");
           switch(actuator){
             case MOTOR:
               //Serial.println("Motor");
               break;
             case LIGHT:
               //Serial.println("Light");
               break;
             case AIRCOND:
               //Serial.println("Aircond");
               break;         
        }
       //Serial.print("Number : ");
       //Serial.println(act_num);
       //Serial.print("Value : ");
       //Serial.println(value);
    }
  }

  if (analogRead(LDR) > 300){
    digitalWrite(CURTAIN_1, HIGH);
    //Serial.print("Light intensity");
    //Serial.println(analogRead(LDR));
  }
}

void actuatorController(int ac, int ac_num, int value){
    switch(ac){
      case MOTOR:
          if(value < 0) value = 0; if(value > 1 || value == 1) value = 255;
          if(ac_num < 0) ac_num = 0; if(ac_num > 1) ac_num = 1;

          if(ac_num == 0){
            if (value == 255)
            {
