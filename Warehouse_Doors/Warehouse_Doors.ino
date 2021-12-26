/*This code is a simple way to control 2 stepper motors to open and close 2 individual warehouse doors.
 *The doors are on a time delay and will start once the arduino has power to it. 
 *I use a toggle switch to turn the arduino on and off so i ensure it has both the doors closed before turning off.
 *I could add extra code to make sure that both doors are closed on startup but that would mean 2 micro switches would be needed.
 *It is based on an Arduino nano using a sheild to make it easy to setup
 *I would advise supplying a separate 5v power supply to the drivers for the stepper motors
 */


#include <Stepper.h>

const int stepsPerRevolution = 2048; // this needs to be set to suit your stepper motor

int speeda = 5;    //speed for the rotation of the stepper motor

int stepa = -1500;  //-1500 steps anti clockwise

int stepb = 1500;   // 1500 steps clockwise

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
Stepper myStepper1 = Stepper(stepsPerRevolution, 4, 6,5,7);

void setup() {

}

void DOOR1_OPEN() {
  myStepper.setSpeed(speeda);//max 15 
  myStepper.step(stepb);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(60000); 
}

void DOOR2_OPEN() {
  myStepper1.setSpeed(speeda);//max 15 
  myStepper1.step(stepb);
  digitalWrite(4, LOW); // these are used to turn off the stepper motor once it has reached its position as the motor can get hot other wise
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(60000); 
}

void DOOR1_CLOSED() {
  myStepper.setSpeed(speeda);//max 15 
  myStepper.step(stepa);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(20000);
}

void DOOR2_CLOSED() {
  myStepper1.setSpeed(speeda);//max 15 
  myStepper1.step(stepa);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(20000);
}

void loop() {
   DOOR1_OPEN();
   DOOR1_CLOSED();
   DOOR2_OPEN();   
   DOOR2_CLOSED();
   
 
}
