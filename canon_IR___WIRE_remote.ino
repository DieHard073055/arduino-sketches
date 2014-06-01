
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
