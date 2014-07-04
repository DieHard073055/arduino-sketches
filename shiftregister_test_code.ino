#define _DATA 5
#define _ENABLE 6
#define _CLCK 8
#define _LATCH 7

int shiftData[] = {
  B00000000,
  B10000000,
  B01000000,
  B00100000,
  B00010000,
  B00001000,
  B00000100,
  B00000010,
  B00000001
};
int d = 0;

void out(char* message){
   Serial.println(message); 
}

void setup(){
  Serial.begin(9600);
  out("System Initiated");
  pinMode(_DATA, OUTPUT);
  pinMode(_CLCK, OUTPUT);
  pinMode(_ENABLE, OUTPUT);
  pinMode(_LATCH, OUTPUT);
  digitalWrite(_ENABLE, LOW);
  
}

void loop(){
  
  if(Serial.available() > 0){
     switch(char(Serial.read())){
        case 'd':
          d =!d;
          digitalWrite(_DATA, d);
          Serial.print("Data : ");
          Serial.println(d);
          break;
         
        case 'c':
          clock();
          break;
        case 'l':
          latch();
          break;
     }
  }
  
}
void clock(){
  digitalWrite(_CLCK, HIGH);
  digitalWrite(_CLCK, LOW);
}
void latch(){
  digitalWrite(_LATCH, LOW);
  digitalWrite(_LATCH, HIGH); 
}
void test(){
   for(int i =0; i < 9; i++){
    digitalWrite(_LATCH, LOW);
    shiftOut(_DATA, _CLCK, LSBFIRST, shiftData[i]);
    digitalWrite(_LATCH, HIGH);
    delay(500); 
    Serial.print("Num : ");
    Serial.println(i);
  }
