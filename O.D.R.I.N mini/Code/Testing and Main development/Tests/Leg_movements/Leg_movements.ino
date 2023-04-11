

/* Leg_movements
  Project: O.D.R.I.N mini
  Start date: 3 April 2023
  Last edited: 11 April 2023
  Info:

  The imdividual leg test script will make O.D.R.I.N mini perform a set of six inches for each leg.
  One leg will raize for each set.
  

  Made by Nathan-Busse.
*/

// The code

// Calling Libraries

#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>

// Declaring pins

// Channel definitions

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

/*
  -------
  Leg D
  -------
*/
#define coxa_D 0
#define femur_D 1
#define tibia_D 2

// Declaring position values for servo joints.

#define coxa_left 135  // Degree for left direction for Coxa
#define coxa_right 45  // Degree for right direction for Coxa

#define femur_down 90  // Degree for Lower Femur
#define femur_up 45    // Degree for Upper Femur

#define tibia_down 175  // Degree for Lower Tibia
#define tibia_up 135    // Degree for Upper Tibia

//Min and Max pulse values

#define MIN_PULSE_WIDTH 500
#define MAX_PULSE_WIDTH 2400
#define DEFAULT_PULSE_WIDTH 1500
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
  // RISE leg A
  //--------------------------------------------------------------------

  pwm.setPWM(coxa_A, 0, pulseWidth(coxa_left));  // A
  delay(hold);
  pwm.setPWM(femur_A, 0, pulseWidth(femur_up));  // A
  delay(hold);
  pwm.setPWM(tibia_A, 0, pulseWidth(tibia_up));  // A
  delay(hold);

  //--------------------------------------------------------------------
  // LOWER leg A
  //--------------------------------------------------------------------

  pwm.setPWM(coxa_A, 0, pulseWidth(coxa_right));
  delay(hold);
  pwm.setPWM(femur_A, 0, pulseWidth(femur_down));
  delay(hold);
  pwm.setPWM(tibia_A, 0, pulseWidth(tibia_down));
  delay(hold);

  //--------------------------------------------------------------------
  // RISE leg B
  //--------------------------------------------------------------------

  pwm.setPWM(coxa_B, 0, pulseWidth(coxa_left));
  delay(hold);
  pwm.setPWM(femur_B, 0, pulseWidth(femur_up));
  delay(hold);
  pwm.setPWM(tibia_B, 0, pulseWidth(tibia_up));
  delay(hold);

  //--------------------------------------------------------------------
  // LOWER leg B
  //--------------------------------------------------------------------

  pwm.setPWM(coxa_B, 0, pulseWidth(coxa_right));
  delay(hold);
  pwm.setPWM(femur_B, 0, pulseWidth(femur_down));
  delay(hold);
  pwm.setPWM(tibia_B, 0, pulseWidth(tibia_down));
  delay(hold);

  //--------------------------------------------------------------------
  // RISE leg C
  //--------------------------------------------------------------------

  pwm.setPWM(coxa_C, 0, pulseWidth(coxa_left));
  delay(hold);
  pwm.setPWM(femur_C, 0, pulseWidth(femur_up));
  delay(hold);
  pwm.setPWM(tibia_C, 0, pulseWidth(tibia_up));
  delay(hold);

  //--------------------------------------------------------------------
  // LOWER leg C
  //--------------------------------------------------------------------

  pwm.setPWM(coxa_C, 0, pulseWidth(coxa_right));
  delay(hold);
  pwm.setPWM(femur_C, 0, pulseWidth(femur_down));
  delay(hold);
  pwm.setPWM(tibia_C, 0, pulseWidth(tibia_down));
  delay(hold);

  //--------------------------------------------------------------------
  // RISE leg D
  //--------------------------------------------------------------------

  pwm.setPWM(coxa_D, 0, pulseWidth(coxa_left));
  delay(hold);
  pwm.setPWM(femur_D, 0, pulseWidth(femur_up));
  delay(hold);
  pwm.setPWM(tibia_D, 0, pulseWidth(tibia_up));
  delay(hold);

  //--------------------------------------------------------------------
  // LOWER leg D
  //--------------------------------------------------------------------

  pwm.setPWM(coxa_D, 0, pulseWidth(coxa_right));
  delay(hold);
  pwm.setPWM(tibia_D, 0, pulseWidth(tibia_down));
  delay(hold);
  pwm.setPWM(femur_D, 0, pulseWidth(femur_down));
  delay(hold);
}

//--------------------------------------------------------------------
// Pulsewidth declaration
//--------------------------------------------------------------------

int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  Serial.println(analog_value);
  return analog_value;
}
