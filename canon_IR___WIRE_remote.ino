
/*
LCD DISPLAY MODULE FILE

#BACKLIGHT CONNECTED TO PIN 9
#CHARACTERLIGHT CONNECTED TO PIN 10

#PIN 2 CONNECTED TO D7
#PIN 3 CONNECTED TO D6
#PIN 4 CONNECTED TO D5
#PIN 5 CONNECTED TO D4

#PIN 12 CONNECTED TO RS
#PIN 11 CONNECTED TO ENABLE

#

*/
#include <LiquidCrystal.h>

#define LCD_BACKLIGHT_BRIGHTNESS 50
#define LCD_CHARACTER_BRIGHTNESS 130
#define BACKLIGHT_PIN 9
#define CHARLIGHT_PIN 10
#define LIGHT_PIN A0
#define STATUS 6
#define printf Display.print
#define SHOOT_PIN 8
#define IRPIN 7

unsigned int MICROPULSE =  10;
unsigned int PICTURE    =  7330;
unsigned int VIDEO      =  5360;
unsigned int INTERvAL   =  16;

LiquidCrystal Display (12, 11, 5, 4, 3, 2);

void setup(){
  pinMode(BACKLIGHT_PIN, OUTPUT);
  pinMode(CHARLIGHT_PIN, OUTPUT);
  pinMode(STATUS, OUTPUT);
  pinMode(SHOOT_PIN, OUTPUT);
  analogWrite(BACKLIGHT_PIN, LCD_BACKLIGHT_BRIGHTNESS);
  analogWrite(CHARLIGHT_PIN, LCD_CHARACTER_BRIGHTNESS);
  
  Load_Intro();
  
  /*SERAIL CODES*/
  Serial.begin(9600);
  Serial.println(" ---- TIMINATOR STARTED ---- ");
}


void loop(){
    if(Serial.available()){
      char d = Serial.read();
      Serial.println(d);
      if(d == 100){ 
        shutter();
        Serial.println("SHOOT! ");
      }
    }
}
/**********************************
      CAMERA FUNCTIONS

***********************************
*/
void shutter(){
   digitalWrite(SHOOT_PIN, HIGH);
   digitalWrite(STATUS, HIGH);
   delay(100);
   digitalWrite(SHOOT_PIN, LOW);
   digitalWrite(STATUS, LOW); 
   delay(300);
}

void camera(unsigned int mode){
 
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




void cls(){
   Display.clear(); 
}
void cursor_0(){
  Display.setCursor(0,0);
}
void cursor_1(){
  Display.setCursor(0,1);
}

void Load_Intro(){
  
  Display.begin(16, 2);  
  printf("    WELCOME    ");
  cursor_1();
  printf("      TO        ");
  delay(1000);
  
  cls();
  cursor_0();
  printf("    DIEHARDS    ");
  cursor_1();
  printf("   TIMINATOR    ");
  delay(1000);
}
