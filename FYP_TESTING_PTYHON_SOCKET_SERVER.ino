//Variable Definitions
#define COMMAND_VARIABLES 4
#define SPRINT            Serial.print
#define SPRINTLN          Serial.println

//Communication Protocol Definitions
#define ACTUATOR  "10"
#define SENSOR    "20"
#define NONE      "0"


//Pin out definition
#define LDR A0

//Communication Protocol Variables
String command_header[COMMAND_VARIABLES]; // Job_id, Actuator_id, Actuator_value, Task_start
String command = "";
int current_variable =0;



void setup(){
  
  Serial.begin(9600);
  SPRINTLN("connection");
}

void loop(){
  process_serial_commands();
  //SPRINTLN(get_sensor_reading(0));
  //delay(500);
}

void process_serial_commands(){
 int input;
  
  if(Serial.available() > 0){
     input = Serial.read(); 
  }
  if(isDigit(input)){
    command += (char) input;
  }
  
  if(input == '-'){
        command_header[current_variable] = command;
        command = "";
  
        current_variable++;
        
        if(current_variable == COMMAND_VARIABLES){
           current_variable = 0;
           Serial.flush();
            
           //Debug Messages
           Debug(" ----- Command Header ------");
           Debug("REQUEST TYPE : " + command_header[0]);
           Debug("JOB ID : " + command_header[1]);
           Debug("ACTUATOR/SENSOR ID : " + command_header[2]);
           Debug("ACTUATOR/SENSOR VALUE: " + command_header[3]);
           
           if(command_header[0] == ACTUATOR){
             //If Actuator selected
             //Return job id when the job is done.
             SPRINTLN(command_header[1]);
           }else if(command_header[0] == SENSOR){
             //If sensor reading requested
             //Return the sensor reading
