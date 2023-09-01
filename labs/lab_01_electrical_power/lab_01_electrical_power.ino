#include <LiquidCrystal.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

#include "LCD_pins.h"

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


#include <Adafruit_INA219.h>
Adafruit_INA219 ina219;

#include <SPI.h>
#include <SD.h>

const int chipSelect = SDCARD_SS_PIN;


void setup() {
  delay(500);
    
  Serial.begin(9600);
  // while(!Serial);
  Serial.println("test");

  lcd.begin(16,2); // size of parallel lcd is 16x2 characters
  


  // Initialize the INA219.
  // By default the initialization will use the largest range (32V, 2A).  However
  // you can call a setCalibration function to change this range (see comments).
  if (! ina219.begin()) {
    Serial.println("Failed to find INA219 chip");
    while (1) { delay(10); }
  }
  // To use a slightly lower 32V, 1A range (higher precision on amps):
  ina219.setCalibration_32V_1A();
  // Or to use a lower 16V, 400mA range (higher precision on volts and amps):
  //ina219.setCalibration_16V_400mA();

  Serial.println("           INA219:  ");
  Serial.println("time (ms), curr (mA)");


    Serial.print("Initializing SD card...");
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    while (1);
  }
  Serial.println("card initialized.");
     
                File dataFile = SD.open("iv_curve.csv", FILE_WRITE);
              // if the file is available, write to it:
              if (dataFile) {
                dataFile.println("time (ms), current (mA), voltage (V)");
                dataFile.close();
              }
              // if the file isn't open, pop up an error:
              else { Serial.println("error opening datalog.txt");  }

} // end function setup()


struct electrical_measurement
{
  float current_mA, voltage_V, power_mW;  
};

// prototype function for INA219 reading
electrical_measurement INA219reading() ;

  int interval = 500; // writes measurements every XX ms
  int present = millis(); 
  int due = present += interval; 

  int averaging_index = 0; // average over the last X samples
  int const num_samples = 10; // number of samples to average over

  float ina219curr_samples[num_samples];
  float ina219volt_samples[num_samples];


void loop() {
  electrical_measurement ina219data; 
  ina219data = INA219reading(); 
  
  ina219curr_samples[averaging_index] = ina219data.current_mA; 
  ina219volt_samples[averaging_index++] = ina219data.voltage_V; 
   
if (averaging_index >= num_samples){
    averaging_index = 0; 
  }


  present = millis(); 
  if (present >= due){
    String write_line = "";
    write_line += present; 
    
    // INA219
    float current = 0; 
    float voltage = 0; 
    for (int ii = 0; ii < num_samples; ii++){ // sum last X current samples
      current += ina219curr_samples[ii];
      voltage += ina219volt_samples[ii];
    } // end INA219 current sample sum
    
    current = current / float(num_samples); 
    voltage = voltage / float(num_samples);
    write_line += ", ";
    write_line += current; 
    write_line += ", ";
    write_line += voltage;
    
    lcd.setCursor(0,0);
    lcd.print(current,1); 
    lcd.setCursor(5,0);
    lcd.print("mA");
    lcd.setCursor(0,1);
    lcd.print(voltage); 
    lcd.setCursor(6,1);
    lcd.print("V");

    File dataFile = SD.open("iv_curve.csv", FILE_WRITE);
              // if the file is available, write to it:
              if (dataFile) {
                dataFile.println(write_line);
                dataFile.close();
                // print to the serial port too:
                
              }
              // if the file isn't open, pop up an error:
              else {
                Serial.println("error opening datalog.txt");
              } // end if dataFile

Serial.println(write_line);

    due += interval; 
    
  } // end if (present >= due)
  
} // end function loop()


// Adafruit_INA219 ina219 ;

electrical_measurement INA219reading(){
  electrical_measurement data; //creates empty object 'data' of type electrical_measurement

  float shuntvoltage;
  float busvoltage ;
  float solar_panel_voltage ;

  shuntvoltage = ina219.getShuntVoltage_mV();
  busvoltage = ina219.getBusVoltage_V();
  //power_mW = ina219.getPower_mW();
  data.voltage_V = busvoltage + (shuntvoltage / 1000);
  data.current_mA = ina219.getCurrent_mA();
  
  return data;
  
} // end function INA219reading()



