*This code is a simple way to control 2 stepper motors to open and close 2 individual warehouse doors.
 *The doors are on a time delay and will start once the arduino has power to it. 
 *I use a toggle switch to turn the arduino on and off so i ensure it has both the doors closed before turning off.
 *I could add extra code to make sure that both doors are closed on startup but that would mean 2 micro switches would be needed.
 *It is based on an Arduino nano using a sheild to make it easy to setup
 *I would advise supplying a separate 5v power supply to the drivers for the stepper motors
 */


#include <Stepper.h>                                              //Import the stepper motor library

const int stepsPerRevolution = 2048;                              // this needs to be set to suit your stepper motor

int speeda = 5;                                                   //speed for the rotation of the stepper motor

int stepa = -1500;                                                //-1500 steps anti clockwise

int stepb = 1500;                                                 // 1500 steps clockwise

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);    // steps = 2048 and the pins for this stepper motor are 8 10 9 11
Stepper myStepper1 = Stepper(stepsPerRevolution, 4, 6,5,7);       // steps = 2048 and the pins for this stepper motor are 4 6 5 7

// We now move into the void setup as you see we do not set anything up here.
void setup() {

}

/* I use 4 function in the code 2 for opening the doors and 2 for closing the doors 
*  these are all very simular so I will only explain one of them
*/

void DOOR1_OPEN() {
  myStepper.setSpeed(speeda);                  // We now set the speed for the stepper in this case 5 rpm max rpm 15
  myStepper.step(stepb);                       // We now tell the stepper to move 1500 steps clockwise
  digitalWrite(8, LOW);                        // The next four lines of code turns off the output pin 
  digitalWrite(9, LOW);                        // This stops the stepper motor over heating while it waits for 
  digitalWrite(10, LOW);                       // Its next move request
  digitalWrite(11, LOW);
  delay(60000);                                // The Arduino will now sleep for 60 seconds before going back to the viod loop()
}

void DOOR2_OPEN() {
  myStepper1.setSpeed(speeda);
  myStepper1.step(stepb);
  digitalWrite(4, LOW); 
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(60000); 
}

void DOOR1_CLOSED() {
  myStepper.setSpeed(speeda);
  myStepper.step(stepa);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(20000);
}

void DOOR2_CLOSED() {
  myStepper1.setSpeed(speeda);
  myStepper1.step(stepa);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  delay(20000);
}

void loop() {
   DOOR1_OPEN();                       //Goes to the function and runs the code within the function it waits until function completes
   DOOR1_CLOSED();                     //Goes to the function and runs the code within the function it waits until function completes
   DOOR2_OPEN();                       //Goes to the function and runs the code within the function it waits until function completes 
   DOOR2_CLOSED();                     //Goes to the function and runs the code within the function it waits until function completes
   
 
}
