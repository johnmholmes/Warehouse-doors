#include <Stepper.h>
#define DOOR_DELAY          5000
const int stepsPerRevolution = 2048;
unsigned long timerStart = 0; 
unsigned long nextDelay = 30000;
unsigned long nextCode = 0;
int speeda = 5;

int stepa = -1500;  //- = up + = down

int stepb = 1500;

Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);
Stepper myStepper1 = Stepper(stepsPerRevolution, 4, 6,5,7);

void setup() {

}

void DOOR1_OPEN() {
  timerStart = millis();
  myStepper.setSpeed(speeda);//max 15 
  myStepper.step(stepb);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(60000); 
  nextCode = (timerStart + nextDelay);
  
}

void DOOR2_OPEN() {
  myStepper1.setSpeed(speeda);//max 15 
  myStepper1.step(stepb);
  digitalWrite(4, LOW);
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
  unsigned long currentMillis = millis();
   DOOR1_OPEN();
   DOOR1_CLOSED();
   DOOR2_OPEN();   
   DOOR2_CLOSED();
   

    
  
}
