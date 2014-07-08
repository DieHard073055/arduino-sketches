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
  pinMode(TIMELAPSE_PIN, INPUT);
  pinMode(INPUT_1, INPUT);
  pinMode(INPUT_2, INPUT);
  pinMode(INPUT_3, INPUT);
  pinMode(INPUT_4, INPUT);
  
  pinMode(SHUTTER_PIN, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Desperate Remote Online");
}

void loop(){
    state = false;
    choice = 0;
    unsigned long start = 0;
    unsigned long elapsed = 0;
    unsigned long period_shutter = 0;
    unsigned long period_interval = 0;
    boolean shutter = false;
    boolean interval = false;
    
    digitalWrite(SHUTTER_PIN, LOW);
    
    while(digitalRead(TIMELAPSE_PIN) == HIGH){
      /******************************************/
      /*     BEFORE TIMELAPSING HAS BEGAN      */
      /*****************************************/
      if(!state){
        Serial.println("Timelapse Starting");
         state = true; 
         
         if(digitalRead(INPUT_1)){
             choice |= values[0];
          }
          if(digitalRead(INPUT_2)){
             choice |= values[1];
          }
          if(digitalRead(INPUT_3)){
             choice |= values[2];
          }
          if(digitalRead(INPUT_4)){
             choice |= values[3];
          }
         
         switch(choice){
             case 0:
