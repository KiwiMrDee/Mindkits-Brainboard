// Gauntlet v1.1
// by MindKits Education

const int ButtonLeft    = 3;
const int LeftMotorFwd   = 4;
const int LeftMotorRev   = 5 ;
const int RightMotorFwd  = 6 ;
const int RightMotorRev  = 7 ;
const int RightIndicator = 8 ;
const int LeftIndicator  = 13 ;
const int SoundPin       = 9 ;
const int Headlights     = 12 ;
const int MotorEnable    = 0 ;
int motorSpeed = 10; // link to potentiometer?

void setup()
{
  pinMode(LeftMotorFwd  ,OUTPUT);
  pinMode(LeftMotorRev  ,OUTPUT);
  pinMode(RightMotorFwd ,OUTPUT);
  pinMode(RightMotorRev ,OUTPUT);
  pinMode(RightIndicator,OUTPUT);
  pinMode(SoundPin      ,OUTPUT);
  pinMode(Headlights    ,OUTPUT);
  pinMode(LeftIndicator ,OUTPUT);
  
  while(!digitalRead(ButtonLeft));

}

void loop()
{
 //put your instructions for the tank in here
    forward(1000);
    turnRight(1000);
    backward(1000);
    turnLeft(1000);

    forward(1000);
    twistRight(1000);
    backward(1000);
    twistLeft(1000);  
    
    wiggle(4);
    
    //All tank instructions above this line.
    while(1); 
}



void allStop() { 
  rightMotor(0);
  leftMotor(0); 
}

void forward(unsigned int time) {
  rightMotor(1);
  leftMotor(1);
  delay(time); 
  allStop();
}

void backward(unsigned int time) {
  rightMotor(-1);
  leftMotor(-1);
  delay(time); 
  allStop();
}

void turnRight(unsigned int time) {
  turn(false,time);
}

void turnLeft(unsigned int time) {
  turn(true,time);
}

void twistRight(unsigned int time) {
  twist(false,time);
}

void twistLeft(unsigned int time) {
  twist(true,time);
}

void wiggle(unsigned int numWiggles) {
  for (int i=0; i <= numWiggles; i++){
    twistRight(300);
    twistLeft(300);
    allStop();
  }
}

void turn(bool clockwise, unsigned int time) {
  if(!clockwise) {
    rightMotor(1);
    leftMotor(0);
  } else {
    rightMotor(0);
    leftMotor(1);
  }
  delay(time);
  allStop();
}

void twist(bool clockwise, unsigned int time) {
  if(!clockwise) {
    rightMotor(1);
    leftMotor(-1);
  } else {
    rightMotor(-1);
    leftMotor(1);
  }
  delay(time);
  allStop();
}

void rightMotor(signed char dir) {
  digitalWrite(RightIndicator,0);
  if(dir>0) {
    digitalWrite(RightMotorRev,dir);
    analogWrite(RightMotorFwd,motorSpeed);
    digitalWrite(RightIndicator,1);
  } else if(dir<0) {
    digitalWrite(RightMotorRev,LOW);
    analogWrite(RightMotorFwd,255-motorSpeed); 

  } else {
    digitalWrite(RightMotorRev,0);
    analogWrite(RightMotorFwd,0);
  }
}

void leftMotor(signed char dir) {
  digitalWrite(LeftIndicator,0);
  if(dir>0) {
    digitalWrite(LeftMotorRev,dir);
    analogWrite(LeftMotorFwd,motorSpeed);
    digitalWrite(LeftIndicator,1);
  } else if(dir<0) {
    digitalWrite(LeftMotorRev,LOW);
    analogWrite(LeftMotorFwd,255-motorSpeed); 

  } else {
    digitalWrite(LeftMotorRev,0);
    analogWrite(LeftMotorFwd,0);
  }
}

