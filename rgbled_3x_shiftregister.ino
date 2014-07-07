#define _DATA PB3 //11
#define _ENABLE PB2 //10
#define _CLCK PB5 //13
#define _LATCH PB4 //12


void setup(){
    
    DDRB |= (1<<_ENABLE) | (1<<_DATA) | (1<<_LATCH) | (1<<_CLCK);
    PORTB &=  (0<<_DATA) | (0<<_LATCH) | (0<<_CLCK);
    PORTB |= 1<<_ENABLE;

}

void loop(){
    
    
    for(int delayTime = 100; delayTime > 5; delayTime= delayTime-(delayTime/5)){
        byte animation = B01111111;
        byte empty = B11111111;

        PORTB &= 0<<_LATCH;
        shift(empty);
        shift(empty);
        shift(empty);
        shift(animation);
        //set enable high
        PORTB |= 1<<_ENABLE;
        //latch everything out
        PORTB |= 1<<_LATCH;
        //enable all the pins
        PORTB &= 0<<_ENABLE;
        for (int i = 0; i < 24; ++i)
        {
            
            delay(delayTime);
            //set data high
            PORTB |= 1<<_DATA; 
            clock();
            latch();
        }
    }
    
    
}

void shift(byte data){


    for(int i=0; i<8; i++){
        //get the output bit from the data
        byte out = data & B00000001;
        //Clock the data out from the arduino
        if(out == B00000001){
            //data high
            PORTB |= 1<<_DATA;
            clock();
        }else{
            PORTB &= 0<<_DATA;
            clock();
        }

        //shift to the next bit
        data = data>>1;
    }
}
void clock(){
    //clock high
    PORTB |= 1<<_CLCK;
    //clock low
    PORTB &= 0 << _CLCK;
}
void latch(){
    //clock high
    PORTB |= 1<<_LATCH;
    //clock low
    PORTB &= 0 << _LATCH;
}
