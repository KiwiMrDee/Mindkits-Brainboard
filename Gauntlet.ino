#include <BrainBoard.h>
BrainBoard brainBoard; // Create BrainBoard object. this automatically sets up the pin modes (input/output).

// Gauntlet v1.6
// by MindKits Education
// Works up to 1.6.0

const int ButtonLeft     =  3;
const int LeftMotorFwd   =  4;
const int LeftMotorRev   =  5 ;
const int RightMotorFwd  =  6 ;
const int RightMotorRev  =  7 ;
const int RightIndicator =  8 ;
const int LeftIndicator  = 13 ;
const int SoundPin       =  9 ;
const int Headlights     = 12 ;
const int MotorEnable    =  0 ;
int motorSpeed = 10; // link to potentiometer?

void setup() {
  pinMode(LeftMotorFwd  ,OUTPUT);
  pinMode(LeftMotorRev  ,OUTPUT);
  pinMode(RightMotorFwd ,OUTPUT);
  pinMode(RightMotorRev ,OUTPUT);
  pinMode(RightIndicator,OUTPUT);
  pinMode(SoundPin      ,OUTPUT);
  pinMode(Headlights    ,OUTPUT);
  pinMode(LeftIndicator ,OUTPUT);

  brainBoard.beep(2500, 400);
  while(!digitalRead(ButtonLeft));
}

void loop() {
// Enter all your tank instructions below this line:
// ----------------------------------------------------------

    goForward(1000);
    goBackward(1000);

// ----------------------------------------------------------
// Enter all your tank instructions above this line.
//
// Here are some example commands for you to copy.
//    goForward(1000);
//    goBackward(1000);
//    turnLeft(1000);
//    twistLeft(1000);
//    backLeft(1000);
//    turnRight(1000);
//    twistRight(1000);
//    backRight(1000);
//    doWiggle(4);
//    playSiren();
//    playTaDa();

    while(!digitalRead(ButtonLeft));
}

/*
// Niuean by @KaraSmithNZ
void tu()                                    { allStop();            }
void fanoKiMua(unsigned int time)            { goForward(time);      }  // fanoKiMua(1000);
void fanoKiTua(unsigned int time)            { goBackward(time);     }  // fanoKiTua(1000);
void fanoFaahiMatau(unsigned int time)       { turnRight(time);      }  // fanoFaahiMatau(1000);
void fanoFaahiHema(unsigned int time)        { turnLeft(time);       }  // fanoFaahiHema(1000);
void liuKiTuaFaahiMatau(unsigned int time)   { backRight(time);      }  // liuKiTuaFaahiMatau(1000);
void liuKiTuaFaahiHema(unsigned int time)    { backLeft(time);       }  // liuKiTuaFaahiHema(1000);
void viviloKeHeFaahiMatau(unsigned int time) { twistRight(time);     }  // viviloKeHeFaahiMatau(1000);
void viviloKeHeFaahiHema(unsigned int time)  { twistLeft(time);      }  // viviloKeHeFaahiHema(1000);
void fakaMavilovilo(unsigned int numWiggles) { doWiggle(numWiggles); }  // fakaMavilovilo(4);
void peleTada()                              { playTaDa();           }  // peleTada();
void peleUiuiUiui()                          { playSiren();          }  // peleUiuiUiui();
*/

/*
// Samoan by Janet Tautaiolefua 
void taofi()                                { allStop();            }  // taofi();
void aluILuma(unsigned int time)            { goForward(time);      }  // aluILuma(1000);
void aluITua(unsigned int time)             { goBackward(time);     }  // aluITua(1000);
void liliuTaumatau(unsigned int time)       { turnRight(time);      }  // liliuTaumatau(1000);
void liliuAgavale(unsigned int time)        { turnLeft(time);       }  // liliuAgavale(1000);
void solomuliTaumatau(unsigned int time)    { backRight(time);      }  // solomuliTaumatau(1000);
void solomuliAgavale(unsigned int time)     { backLeft(time);       }  // solomuliAgavale(1000);
void mimiloTaumatau(unsigned int time)      { twistRight(time);     }  // mimiloTaumatau(1000);
void mimiloAgavale(unsigned int time)       { twistLeft(time);      }  // mimiloAgavale(1000);
void siva(unsigned int numWiggles)          { doWiggle(numWiggles); }  // siva(4);
void malo()                                 { playTaDa();           }  // malo();
void lapataiga()                            { playSiren();          }  // lapataiga();
*/

void allStop() {
  rightMotor(0);
  leftMotor(0);
}

void goForward(unsigned int time) {
  rightMotor(1);
  leftMotor(1);
  delay(time);
  allStop();
}
void goBackward(unsigned int time) {
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

void backRight(unsigned int time) {
  back(false,time);
}
void backLeft(unsigned int time) {
  back(true,time);
}

void twistRight(unsigned int time) {
  twist(false,time);
}
void twistLeft(unsigned int time) {
  twist(true,time);
}

void doWiggle(unsigned int numWiggles) {
  for (int i=0; i <= numWiggles; i++){
    twistRight(200);
    twistLeft(200);
  }
  allStop();
}

void turn(bool clockwise, unsigned int time) {
  if(!clockwise) {
    rightMotor(0);
    leftMotor(1);
  } else {
    rightMotor(1);
    leftMotor(0);
  }
  delay(time);
  allStop();
}

void back(bool clockwise, unsigned int time) {
  if(clockwise) {
    rightMotor(0);
    leftMotor(-1);
  } else {
    rightMotor(-1);
    leftMotor(0);
  }
  delay(time);
  allStop();
}

void twist(bool clockwise, unsigned int time) {
  if(!clockwise) {
    rightMotor(-1);
    leftMotor(1);
  } else {
    rightMotor(1);
    leftMotor(-1);
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

void playTaDa(){
    brainBoard.beep(2500, 200);   // 2.5 kHz for 40 millisec
    delay(40);
    brainBoard.beep(2500, 1000); // 2.5 kHz for 500 millisec
    delay(40);
}

void playSiren(){
  for (int i=0; i <= 2; i++){
    for (int j=50; j <= 300; j++){
      brainBoard.beep(j*10, 2);   // Siren Up
    }
    for (int j=300; j >= 50; j--){
      brainBoard.beep(j*10, 2);   // Siren Down
    }
  }
  delay(40);
}
