#include "get_rssi.h";

void get_sat_rssi() {
  Serial1.println(" standby for RSSI");
  
  // put the radio in command mode:
  bool not_done = true;
  String ok_response = "OK\r";   //The﻿response we expect.
  String response = String("");  //Create an empty string
  Serial.println("Starting get_sat_rssi()");
  
  // Read the text of the response into the response variable
  while (not_done) {  // As long as we did not get a response from the XBee
    response = String("");
    delay(1100);
    Serial1.print("+++");  // Put the XBee 3 into 'Command Mode'
    // Serial.print("+++");   // Put the XBee 3 into 'Command Mode'

    // delay(1100);  // Wait for the XBee to finish
    while (response.length() < ok_response.length()) {
      if (Serial1.available() > 0) {

        response += (char)Serial1.read();  // Read a single character at a time
      }
    }
    not_done = !response.equals(ok_response);  // Set the not_done flag to the opposite of the result of equality check
  }
// Serial.println(response);
      

  // If we got the right response, configure the radio and return true.   
  Serial1.print("ATDB\r");  // destination high and destination low addresses set to 0 means all messages will only go
  delay(100);               // Wait for the XBee
  response = String("");
  while (Serial1.available() > 0) {
    response += (char)Serial1.read();  //Read a single character at a time
    
  }
  Serial.println(response);
  Serial1.print("ATCN\r");  // Switch back to data mode

  String response2 = response; 
  uint32_t dec_response = strtoul(response2.c_str(), NULL, 16);

  Serial1.print("RSSI: -");
  Serial1.print(dec_response);
  Serial1.println(" dBm");
  Serial.println("sat rssi sent");
}