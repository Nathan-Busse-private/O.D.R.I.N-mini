
/* Servo config
  Project: O.D.R.I.N mini
  Start date: 3 April 2023
  Info:

  Seetting all servos to 90 degrees before assembly.

  Made by Nathan-Busse.
*/

// The code

// Calling Libraries

#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

// Declaring pins

// Channel definitions


//pwm (Board 1)
/*
  -------
  Leg A
  -------
*/
#define coxa_A 12
#define femur_A 13
#define tibia_A 14

/*
  -------
  Leg B
  -------
*/
#define coxa_B 8
#define femur_B 9
#define tibia_B 10

/*
  -------
  Leg C
  -------
*/
#define coxa_C 4
#define femur_C 5
#define tibia_C 6


//pwm (Board 2)
/*
  -------
  Leg D
  -------
*/
#define coxa_D 0
#define femur_D 1
#define tibia_D 2

// servo config

#define config 90

//Min and Max pulse values

#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2500
#define DEFAULT_PULSE_WIDTH 2500
#define FREQUENCY 50

int degrees;

// Millis declarations
#define hold 500
#define pause 5000

// Address definitions for servo controllers
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);



void setup() {
  // put your setup code here, to run once:

  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);  // Analog servos run at ~60 Hz updates

  
}

void loop() {
  //--------------------------------------------------------------------
  // Config servos to 90 degrees for each leg.
  //--------------------------------------------------------------------

  pwm.setPWM(coxa_A, 0, pulseWidth(config));  // A
  pwm.setPWM(femur_A, 0, pulseWidth(config));  // A
  pwm.setPWM(tibia_A, 0, pulseWidth(config));  // A

  pwm.setPWM(coxa_B, 0, pulseWidth(config));  // B
  pwm.setPWM(femur_B, 0, pulseWidth(config));  // B
  pwm.setPWM(tibia_B, 0, pulseWidth(config));  // B

  pwm.setPWM(coxa_C, 0, pulseWidth(config));  // C
  pwm.setPWM(tibia_C, 0, pulseWidth(config));  // C
  pwm.setPWM(femur_C, 0, pulseWidth(config));  // C

  pwm.setPWM(coxa_D, 0, pulseWidth(config));  // D
  pwm.setPWM(femur_D, 0, pulseWidth(config));  // D
  pwm.setPWM(tibia_D, 0, pulseWidth(config));  // D
  delay(hold);

}

// Pulsewidth declaration

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  Serial.println(analog_value);
  return analog_value;
}
