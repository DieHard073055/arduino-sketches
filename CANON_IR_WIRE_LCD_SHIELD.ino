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
