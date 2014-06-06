/*
0000
0001
0010
0011
0100
0101
0110
0111
1000
1001
1010
1011
1100
1101
1110
1111
*/

#define TIMELAPSE_PIN A5
#define INPUT_1       A4
#define INPUT_2       A3
#define INPUT_3       A2
#define INPUT_4       A1

#define SHUTTER_PIN 13

int values[] = {
    B00000001,
    B00000010,
    B00000100,
    B00001000
};

boolean state = false;
int choice = 0;


void setup(){
  //Setup input output pins
