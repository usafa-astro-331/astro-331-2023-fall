#include "input.h"
#include "LED_pins.h"

void get_command_from_pc() {
  int space, do_it = 0;         // For reading in a space from the PC
  // unsigned long int value = 0;  // Secondary value for items that have a 'set' functionality

  String what_to_do = Serial1.readString();  // Find out what the user wants the MKR1000 to do.
  if (what_to_do.length() != 0) {            // As long as the string contains "something"
    Serial.print("Received: ");
    Serial.println(what_to_do);

    what_to_do.trim();                                   // Remove all leading and trailing spaces
    space = what_to_do.indexOf(' ');                     // See if there is a space somewhere after removing leading and trailing spaces
    // if (space > -1) {                                    // If there is a space, then we have a value to 'set'
      // value = (what_to_do.substring(space)).toInt();     // Get the 'set' value as an integer
      // do_it = (what_to_do.substring(0, space)).toInt();  // Get the 'command' value as an integer
    // } else {
      do_it = (what_to_do.substring(0, space)).toInt();
    // }
    // Serial.print(do_it);
    // Serial.print(" ");
    // Serial.println(value);
    switch (do_it) {  // Determine what we are supposed to do
      case 1:
        Serial1.print(" help \n");
        Serial1.print("2 get RSSI \n");
        Serial1.print("3 toggle LED \n\n");
        break;

      case 2:
        get_sat_rssi();
        break;

        case 3: 

        digitalWrite(LED_pin, !(digitalRead(LED_pin)));
        
        if (digitalRead(LED_pin)){Serial1.println(" LED on");}
        else {Serial1.println(" LED off");}

    }
  }
  delay(25);
}