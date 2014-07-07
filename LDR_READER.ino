
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



LiquidCrystal Display (12, 11, 5, 4, 3, 2);
void setup(){
  pinMode(BACKLIGHT_PIN, OUTPUT);
  pinMode(CHARLIGHT_PIN, OUTPUT);
  pinMode(STATUS, OUTPUT);
  analogWrite(BACKLIGHT_PIN, LCD_BACKLIGHT_BRIGHTNESS);
  analogWrite(CHARLIGHT_PIN, LCD_CHARACTER_BRIGHTNESS);
  
  Load_Intro();
  
}


void loop(){
  int ldr = analogRead(LIGHT_PIN);
  int statusPower = map(ldr, 0, 900, 0, 255);
  cls();
  cursor_0();
  printf("LDR Reading: ");
  printf(ldr);
  analogWrite(STATUS, statusPower);
  delay(500);
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
