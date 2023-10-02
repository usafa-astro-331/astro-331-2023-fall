// TB9051FTGMotorCarrier motor controller connections

// high voltage side (4 pins)
// Vin = 12V supply (from battery via wago connector)
// Gnd = ground (from battery via wago connector)
// Out2 = to motor black
// Out1 = to motor red

// low voltage side (10 pins)
// VM = NC // (NC means not connected)
// Gnd = ground (rail from Arduino)
// Vcc = 5V (from top 5V rail via BEC)
// OCC = NC
// EN = 5V
// ENB = ground 
// PWM2
static constexpr uint8_t pwm2Pin{3}; // connect to Arduino pin 3
// PWM1
static constexpr uint8_t pwm1Pin{2}; // connect to Arduino pin 2
// OCM = NC
// DIAG = NC




// motor connections
// black = as described previously (motor controller)
// red = as described previously (motor controller)
// green = ground (ground for quadrature encoder--wheel speed sensor)
// blue = 3.3V (power for quadrature encoder--wheel speed sensor)
// white = 6 (signal from quadrature encoder--wheel speed sensor)--defined below
// yellow = A2 (signal from quadrature encoder--wheel speed sensor)--defined below

Encoders Encoder(6,A2);  // defined above--creates quadrature encoder object for wheel speed
