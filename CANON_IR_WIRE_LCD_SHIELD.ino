#include <LiquidCrystal.h>
               if(elapsed >= settings_value[0]){

                  elapsed = 0;
/*
                  start = millis();
---------------------------------------
                  shutter = false;
PINS AVAILABLE FROM THE LCD SHIELD
                  digitalWrite(SHUTTER_PIN, LOW);
pin 0(RX)
                  interval = true;
pin 1(TX)
                  shots++;
pin 2
               } 
pin 3(PWM)
            }else if(interval){
pin 11(PWM)
              if(elapsed >= settings_value[1]){
pin 12
                  elapsed = 0;
pin 13
                  start = millis();

                  shutter = true;
pin A1
                  digitalWrite(SHUTTER_PIN, HIGH);
pin A2
                  interval = false;
pin A3
               }
pin A4
            }
pin A5
            
----------------------------------------
          }

          
pin 10 backlight control
          /*

                SLEEP CONTROLLER
pin 11 connected to the relay
                SET SLEEP TIME TO 5 SECONDS
pin 3 connected to ir led
          */

          
*/
          if(!sleeping){

            sleep_elapsed = millis() - sleep_start;
LiquidCrystal Display(8, 9, 4, 5, 6, 7);
            if(sleep_elapsed >= 5000){
/*************************
                  digitalWrite(BACKLIGHT_PIN, LOW);
  LCD PIN DEFINITIONS
                  sleeping = true;
*/
            }
#define RS_PIN 8
          }
#define ENABLE_PIN 9
          
#define D4_PIN 4
          /*
#define D5_PIN 5
                SHOT COUNT DONE
#define D6_PIN 6
          */
#define D7_PIN 7
          if(shots == settings_value[2]){

              SBB();
/**********************
              return;              
    OTHER PIN DEFINITIONS 
          }
*/
       }
#define BACKLIGHT_PIN 10
       /*********************************
#define IRPIN 3
           REFRESH RATE DELAY
