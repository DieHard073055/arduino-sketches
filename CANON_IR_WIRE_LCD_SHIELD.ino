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
#define SHUTTER_PIN 11
       *********************************/
/**********************
      delay(REFRESH_RATE);
    OTHER DEFINITIONS 
 } 
*/
}
/*    LCD  */
 
#define SBB setBacklightBrightness
/**********************************
#define prnt Display.print
        ASTROLAPSE - CONTROLLER
#define prntln Display.println
*/
#define REFRESH_RATE 100
/**********************************
/*    BUTTONS   */
        BACKLIGHT CONTROLLER
#define NONE   0
*/
#define UP     1
void Backlight_Controller(){
#define DOWN   2
    int input; 
#define LEFT   3
    
#define RIGHT  4
    while(1){
#define SELECT 5
        cls();

        c_0();
/**********************
        prnt("BACKLIGHT : ");
  CAMERA IR SENSOR VALUES
        prnt(backlight_value);
*/
        c_1();
unsigned int MICROPULSE =  10;
        for(int i=0; i<map(backlight_value, 0, 180, 0, 16); i++){
unsigned int PICTURE    =  7330;
           Display.write((uint8_t)0); 
unsigned int VIDEO      =  5360;
        }
unsigned int INTERvAL   =  16;
        

        input = get_input();
/************************
        
    LCD CHARACTER DEFINTIONS
        switch(input){
*/
          case UP:
byte lightBulb[8] = {
            if(backlight_value < 180) backlight_value++;
	0b01110,
            SBB();
	0b10001,
          break;
	0b10001,
          case DOWN:
	0b10101,
            if(backlight_value > 0) backlight_value--;
	0b10101,
            SBB();
	0b01110,
          break;
	0b01110,
          case LEFT:
	0b00000
            return;
};
          break;

          case RIGHT:
int backlight_value = 0;
          break;

          case SELECT:
void setup(){
          break;
  setupDisplay();
         }
}
        delay(REFRESH_RATE);

     } 
void loop(){
  
  menu();
}
}









/********************************
          MENU
*/
void menu(){
   int input = 0; 
  
   int selected = 0;
   String menu_items[] ={
      "Shutter",
      "Shutter IR",
      "Shutter IR Video",
      "Timelapse",
      "Astrolapse",
      "Backlight"
   };
   int array_size = sizeof(menu_items) / sizeof(String);
   
   while(1){
     cls();
     c_0();
     prnt(" > ");
     prnt(menu_items[selected]);
     c_1();
     if(selected == (array_size-1)){
      
     }else if(selected < (array_size-1)){ 
       prnt("   ");
       prnt(menu_items[selected+1]);
     }
     
     input = get_input();
     switch(input){
        case UP:
           if(selected > 0){
              selected--;
           } 
           break;
           
        case DOWN:
            if(selected < (array_size -1)){
               selected++; 
            }
            break;
            
        case SELECT:
            /* Goto that function */
            switch(selected){
               case 0:
                 /* Shutter Function */
                 shutter();
                 break;
                 
               case 1:
                 /* Shutter IR Function */
                 cls();
                 c_0();
                 prnt("  IR SHUTTER !  ");
                 ir(PICTURE);
                break;
               case 2:
                 /* Shutter IR2 Function */
                 cls();
                 c_0();
                 prnt("   IR VIDEO !   ");
                 ir(VIDEO);
                 break;
               case 3:
                 /* Timelapse Function */
                 Timelapse_Controller();
                 break;
                
               case 4:
                 /* Astrolapse Function*/
                 break; 
                 
               case 5:
                 /* Backlight Control Function */
                 Backlight_Controller();
                 break;
              
            }
            break;
     }
     
     delay(REFRESH_RATE);
   }
   
   
}


/*********************************
        GET INPUT FROM
          SHEILD
*/
int get_input(){
   int user_input = analogRead(0); 
   switch(user_input){
       case 2000 ... 1000:
         return NONE;
         
       case 0 ... 50:
         return RIGHT;
       
       case 51 ... 250:
         return UP;
         
       case 251 ... 450:
         return DOWN;
         
       case 451 ... 650:
          return LEFT;
          
       case 651 ... 850:
           return SELECT;
         
       default:
         return NONE;
     
   }
  
}

/**********************************
      Display Setup functions
*/
void setBacklightBrightness(){
   analogWrite(BACKLIGHT_PIN, backlight_value); 
}
void backlightSleep(){
   analogWrite(BACKLIGHT_PIN, 0);   
}
void cls(){
   Display.clear(); 
}
void c_0(){
  Display.setCursor(0,0);
}
void c_1(){
  Display.setCursor(0,1);
}
void setupDisplay(){
   pinMode(BACKLIGHT_PIN, OUTPUT);
   backlight_value = 50;
   SBB();
   
   
   /*******************
       CUSTOM CHARATERS
   */
   Display.createChar(0, lightBulb);
   /*****************************/
   Display.begin(16, 2);
   
   prnt("    WELCOME    ");
   c_1();
   prnt("      TO        ");
   
   delay(1000);
   
   cls();
   c_0();
   prnt("    DIEHARDS    ");
   c_1();
   prnt("   TIMINATOR    ");
   
   delay(1000);
}

/*********************************
  Camera Shutter Using Wire
*/
void shutter(){
   digitalWrite(SHUTTER_PIN, HIGH);
   cls();
   c_0();
   prnt("    SHUTTER !   ");
   delay(95);
   digitalWrite(SHUTTER_PIN, LOW); 
   delay(100);
}


/**********************************
      IR FUNCTIONS
*/
void ir(unsigned int mode){
 
 for(int i=0; i<INTERvAL; i++){
    digitalWrite(IRPIN, HIGH);
    delayMicroseconds(MICROPULSE);
    digitalWrite(IRPIN, LOW);
    delayMicroseconds(MICROPULSE);  
 }
 
 
 delayMicroseconds(mode);
 
 
 for(int i=0; i<INTERvAL; i++){
    digitalWrite(IRPIN, HIGH);
    delayMicroseconds(MICROPULSE);
    digitalWrite(IRPIN, LOW);
    delayMicroseconds(MICROPULSE);
 }
}


/*********************************
          APPLICATIONS
         -------------
   - ALL THE APPLICATIONS RUNNING ON
   THIS ARDUINO IS CODED BELOW
   - ALL THE APPLICATIONS WILL BE FOLLOWING
   THE TEMPLATE BELOW
   
   VOID (APPLICATION_NAME){
     
     int input; 
     while(1){
        *****************************
                  DISPLAY
        ******************************
        cls();
        c_0();
        prnt("                ");
        c_1();
        prnt("                ");
        *******************************
                GET USER INPUT
        *******************************
        input = get_input();
        *******************************
              PROCESS USER INPUT
        ********************************
        switch(input){
          case UP:
          break;
          case DOWN:
          break;
          case LEFT:
          break;
          case RIGHT:
          break;
          case SELECT:
          break;
         }
         *********************************
             REFRESH RATE DELAY
         *********************************
        delay(REFRESH_RATE);
     } 
   }
*/

/**********************************
         TIMELAPSE - CONTROLLER
*/
void Timelapse_Controller(){
   /*
       setting
       0 = EXPOSURE
       1 = INTERVAL
       2 = SHOTS
  */
   int mode = 0;
   int setting = 0;
   int input;
   int increment_value = 1;
   boolean paused = false;
   String display_settings[] = {
      "Exposure : ",
      "INTERVAL : ",
      "SHOTS : ",
      "START"
   };
   unsigned long settings_value[] = {
        0, //Exposure Value
        1000, //Interval Value
        0  //Shot count
   }; 
   /* 
       TIMELAPSE MODE VARIABLES
   */
   unsigned long start = 0;
   
unsigned long elapsed = 0, pause_t = 0;
   unsigned long shots=0;
   boolean interval = false;
   boolean shutter = false;
   
   /*
       SLEEP VARIABLES
   */
   unsigned long sleep_start = 0;
   unsigned long sleep_elapsed = 0;
   boolean sleeping = false;
   
   
   while(1){
      /*****************************
                DISPLAY
      ******************************/
      if(mode == 0){
        /* TIMELAPSE SETTING MODE */
        cls();
        c_0();
        prnt(display_settings[setting]);
        c_1();
        if(setting == 3){
          prnt("TIMELAPSE");
        }
        else{
          prnt(settings_value[setting]);
        }       
        if(setting == 1 || setting == 0)
        prnt(" milisec");
      }else{
        /* 
          TIMELAPSE MODE DISPLAY CODE
         */
        cls();
        c_0();
        if(paused){
          prnt("Paused ");
        }else{
          if(shutter)
            prnt("Shutter : ");
          else if(interval)
            prnt("Interval : ");
        }
        prnt(elapsed);
        
        c_1();
        prnt("Shots : ");
        prnt(shots);
        
      }
      
      /*******************************
              GET USER INPUT
      *******************************/
      input = get_input();
      if(input != NONE){
         sleep_start = millis(); 
      }else{SBB();sleeping=false;}
      /*******************************
