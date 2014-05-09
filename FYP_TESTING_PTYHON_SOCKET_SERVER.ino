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
