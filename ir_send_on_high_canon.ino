#define IRPIN 9
#define INPUTPIN 8
#define INPUTPIN2 7

unsigned int MICROPULSE =  10;
unsigned int PICTURE    =  7330;
unsigned int VIDEO      =  5360;
unsigned int INTERvAL   =  16;


void setup(){
  pinMode(IRPIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("System started");
}
void loop(){
  if(digitalRead(INPUTPIN) == HIGH){
     Serial.println("Shoot!");
     camera(PICTURE);
     delay(100); 
  }
}



