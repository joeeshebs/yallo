#include <AFMotor.h>
#include <Servo.h>
Servo servo1;//ultrasonic sensor
Servo upservo;//shooting servo
Servo downservo;//shooting servo
//initial motors pin
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2); 
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
int const fire_motor1=A4;
int const fire_motor2=A5;
int pos = 0; 
char command; 

void setup() 
{       
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
  servo1.attach(A2);
  upservo.attach(10);
  downservo.attach(9);
  pinMode(fire_motor1,OUTPUT);
  pinMode(fire_motor2,OUTPUT);
}

void loop(){
  digitalWrite(fire_motor1,LOW);
  digitalWrite(fire_motor2,LOW); 
  servo1.write(90);
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop();
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
      break;
   /* case 'p':
      servoR();
      break;
    case 'O':
      servoL();
      break;*/ 
    case 'f':
      fire();
      break;
    case 'X':
    fireL();
    break;
    case 'Y':
    fireR();
    case'q':
    void stopfire();
    break;
    }
  } 
}
void fireL(){
  
  }
  void fireR(){
    
    }
void stopfire(){
     digitalWrite(fire_motor1,LOW);
     digitalWrite(fire_motor2,LOW);
      }
void fire(){
  digitalWrite(fire_motor1,HIGH);
  digitalWrite(fire_motor2,LOW); 
  delay(1000);
  upservo.write(90);
  delay(1000);
  upservo.write(175);
  delay(1000);
  downservo.write(90);
  delay(1000);
  downservo.write(175);
  delay(1000);
  
  }
/*void servoL(){
  for (pos =120; pos >=90 ; pos -= 1) { 
    servo1.write(pos);             
    delay(15);  
    //Serial.println(pos);                    
  }
  }
void servoR(){
  for (pos = 0; pos <= 30; pos += 1) {
    servo1.write(pos);             
    delay(15);        
    //Serial.println(pos);               
  }
  }*/

void forward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255);//Define maximum velocity
  motor3.run(FORWARD); //rotate the motor clockwise
  motor4.setSpeed(255);//Define maximum velocity
  motor4.run(FORWARD); //rotate the motor clockwise
  digitalWrite(8,HIGH);
}

void back()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
}

void left()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
}

void right()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD); //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD); //rotate the motor clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
} 

void Stop()
{
  motor1.setSpeed(0); //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0); //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0); //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0); //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}
