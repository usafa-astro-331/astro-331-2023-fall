  // #define SERIAL_PORT Serial
 

// ----- TB9051FTG Motor Carrier
  #include <TB9051FTGMotorCarrier.h>
  #include <QuadratureEncoder.h>
  // QuadratureEncoder requires <EnableInterrupt.h>

  // TB9051FTGMotorCarrier pin definitions
  static constexpr uint8_t pwm1Pin{2};
  static constexpr uint8_t pwm2Pin{3};

  // Instantiate TB9051FTGMotorCarrier
  static TB9051FTGMotorCarrier driver{pwm1Pin, pwm2Pin};

  // set up variable for pulse width modulation of motor
  static float throttlePWM{0.0f};

  // Create an Encoder object name Encoder, using digital pins 0 & 1 (interrupt pins on MKR Zero)
  Encoders Encoder(0,1);  

  unsigned long lastMilli = 0;
  long currentEncoderCount = 0;
  long lastEncoderCount = 0;
  float speed_rpm = 0.0;
  long timeElapsed = 0;

  float speed_pwm;



  // ----- time variables -----
  int print_time = 0 ; 
  int print_delay = 500; 
  int current_time = 0; 
  int elapsed = 0; 

  int motor_current_pin = A1;   // select the input pin for the potentiometer
  int motor_current_count;  // variable to store the value coming from the sensor
  float motor_current_voltage; //
  float motor_current; 

void setup() {
  Serial.begin(9600);
  while (!Serial)
  {
  };

Serial.println("time (ms), command speed (0-1), meas speed (RPM), motor current (mA)");

analogReadResolution(12);

// ----- TB9051FTG Motor Carrier
  driver.enable();


  
}

float speed_command;

int t; 
int t0 = millis(); // set start time right before loop


void loop() {

t = millis();

Serial.print(t); 
Serial.print(",");


if(t-t0<1500){

}
else if(t-t0<10000){
    Serial.print(1);
    driver.setOutput(1); 
  }
  else{ 
    driver.setOutput(0); 
    while(1){} }


Serial.print(",");



// Read current encoder count
    currentEncoderCount = Encoder.getEncoderCount();
    // Determine how much time has elapsed since last measurement
    timeElapsed = millis()-lastMilli;
    // Calculate speed in rpm
    // encoder is 64 counts per rev
    // motor is 10:1 geared
    // counts/ms * 1 rev/64 counts * 1000 ms/1 sec * 60 s/1 min * 1 rot/10 gears = rev/min
    speed_rpm = float(currentEncoderCount - lastEncoderCount)/timeElapsed/64*1000*60/10;
    // reset variables to most recent value
    lastMilli = millis();
    lastEncoderCount = currentEncoderCount;
    // Print to serial monitor
    // Serial.print("Time (ms) = ");
    // Serial.print(lastMilli);
    // Serial.print(", Speed (RPM) = ");
    // Serial.println(speed_rpm);
    


motor_current_count = analogRead(motor_current_pin); 
motor_current_voltage = motor_current_count * 3.3/4095; 
motor_current = motor_current_voltage *2000; 


Serial.print(speed_rpm);
Serial.print(",");
Serial.println(motor_current);


}


