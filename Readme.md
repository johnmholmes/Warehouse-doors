# This code is for demonstartion purpose only as used on my layout
This code uses the stepper.h library to control the stepper motor and in this case the stepper motor has to move 2048 steps to complete 1 full revolution. We need to create 2 instances of the stepper motor and connect up the driver board to the arduino in this case a nano with a sensor shield

# Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11);

Pin 1 on the drive board goes to pin 8 on the arduino 

Pin 2 on the drive board goes to pin 10 on the arduino 

Pin 3 on the drive board goes to pin 9 on the arduino 

Pin 4 on the drive board goes to pin 11 on the arduino 

# Stepper myStepper1 = Stepper(stepsPerRevolution, 4, 6,5,7);

Pin 1 on the drive board goes to pin 4 on the arduino 

Pin 2 on the drive board goes to pin 6 on the arduino 

Pin 3 on the drive board goes to pin 5 on the arduino 

Pin 4 on the drive board goes to pin 17 on the arduino 

# We then need to set the amount of steps we want the motor to move done below

int stepa = -1500;  //-1500 steps anti clockwise

int stepb = 1500;   // 1500 steps clockwise

# And we need to set a speed for the motor to move as below

int speeda = 5;    //speed for the rotation of the stepper motor

# We then setup 4 door void functions see below

void DOOR1_OPEN() {
 
 myStepper.setSpeed(speeda);//max 15 
  
 myStepper.step(stepb);
 
 digitalWrite(8, LOW);
  
 digitalWrite(9, LOW);
  
 digitalWrite(10, LOW);
  
 digitalWrite(11, LOW);
  
 delay(60000); 
  


# These then called up in the viod loop() in a sequence 

   DOOR1_OPEN();

   DOOR1_CLOSED();

   DOOR2_OPEN();
   
   DOOR2_CLOSED();






