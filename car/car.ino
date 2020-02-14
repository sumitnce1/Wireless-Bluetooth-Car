//Arduino Bluetooth Controlled Car//
//// Before uploading the code you have to install the necessary library//
//AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install //

#include <AFMotor.h>

//initial motors pin
AF_DCMotor motor1(1); 
AF_DCMotor motor2(4); 


char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop(){
  if(Serial.available() > 0)
  { 
    command = Serial.read(); 
    Stop(); //initialize with motors stoped
    //Change pin mode only if new command is different from previous.   
    //Serial.println(command);
    switch(command){
    case 'F':  
      forward();
      break;
    case 'B':  
       back();
      break;
    case 'L':  
      left();
      break;
    case 'R':
      right();
    case 'S':
      Stop();
      break;
    }
  }   
}

void forward()
{
  motor1.setSpeed(100); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(100); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise

}

void back()
{
  motor1.setSpeed(100); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(100); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
 
}

void left()
{
  motor1.setSpeed(100); //Define maximum velocity
  motor1.run(RELEASE); //rotate the motor anti-clockwise
  motor2.setSpeed(100); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor anti-clockwise

}

void right()
{
  motor1.setSpeed(100); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(100); //Define maximum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
 
} 

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise

}
