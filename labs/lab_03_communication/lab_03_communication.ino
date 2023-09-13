#include "xbee_pins.h"

#include "LED_pins.h"
#include "input.h"

// Network ID for XBee communication
// select a number between 0 and 9999
int PAN_ID = 2006; 
  
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600); // normal USB serial port to PC
  Serial1.begin(9600); // 2nd serial port to XBee radio

  // set XBee channel number
      // put the radio in command mode:
        delay(1100);
        Serial1.print("+++");  // Put the XBee 3 into 'Command Mode'
        delay(1100);

      // set channel
      Serial1.print("ATID ");
      Serial1.print(PAN_ID);
      Serial1.print("\r"); 

      Serial1.print("ATDH 0\r"); 
      Serial1.print("ATDL 0\r"); 
      Serial1.print("ATMY 1\r"); 

      // save and exit
      Serial1.print("ATWR\r");
      delay(250);
      Serial1.print("ATCN\r");
  // end of XBee channel configuration


  pinMode(LED_pin, OUTPUT); 
  digitalWrite(LED_pin, LOW); 


// clear terminal screen 
  Serial1.write(27);       // ESC command
  Serial1.print("[2J");    // clear screen command
  Serial1.write(27);
  Serial1.print("[H");     // cursor to home command


  
Serial1.println("FlatSAT online \npress 1 for options");
Serial.print("hello \n");
}

void loop() {
  get_command_from_pc();
}