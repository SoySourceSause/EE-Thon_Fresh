#include <SoftwareSerial.h>  
SoftwareSerial mySerial(51,52); // Arudino Uno port RX, TX  

#define START_1 0x42  
#define START_2 0x4d  
#define DATA_LENGTH_H        0  
#define DATA_LENGTH_L        1  
#define PM1_0_ATMOSPHERE_H   8  
#define PM1_0_ATMOSPHERE_L   9  
#define PM2_5_ATMOSPHERE_H   10  
#define PM2_5_ATMOSPHERE_L   11  
#define PM10_ATMOSPHERE_H    12  
#define PM10_ATMOSPHERE_L    13  
#define PM2_5_PARTICLE_H   16  
#define PM2_5_PARTICLE_L   17  
#define VERSION              26  
#define ERROR_CODE           27  
#define CHECKSUM             29  
#define FAN 49
byte bytCount1 = 0;  
byte bytCount2 = 0;  
unsigned char chrRecv;  
unsigned char chrData[30];  
int PM01;  
int PM25;  
int PM10;  
  
unsigned int GetPM_Data(unsigned char chrSrc[], byte bytHigh, byte bytLow)  
{  
   return (chrSrc[bytHigh] << 8) + chrSrc[bytLow];  
}  

extern volatile unsigned long timer0_millis; //타이머변수

unsigned long timeVal=0;  //현재시간값 저장변수
unsigned long previousT=0; //이전시간값 저장변수
void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);  
  Serial.println("PMS7003 Ready ");  
  mySerial.begin(9600);  
  pinMode(FAN, OUTPUT);
  pinMode(A0, OUTPUT);

  pinMode(A1, OUTPUT);

  pinMode(A2, OUTPUT);

  pinMode(A3, OUTPUT);

  pinMode(A4, OUTPUT);

  pinMode(A5, OUTPUT);

  pinMode(A6, OUTPUT);

  pinMode(A7, OUTPUT);

  pinMode(A8, OUTPUT);

  pinMode(A9, OUTPUT);

  pinMode(A10, OUTPUT);

  pinMode(A11, OUTPUT);

  pinMode(A12, OUTPUT);

  pinMode(A13, OUTPUT);

  pinMode(A14, OUTPUT);

  pinMode(A15, OUTPUT);



  pinMode(2, OUTPUT);

  pinMode(3, OUTPUT);

  pinMode(4, OUTPUT);

  pinMode(5, OUTPUT);

  pinMode(6, OUTPUT);

  pinMode(7, OUTPUT);

  pinMode(8, OUTPUT);

  pinMode(9, OUTPUT);

  pinMode(10, OUTPUT);

  pinMode(11, OUTPUT);

  pinMode(12, OUTPUT);

  pinMode(13, OUTPUT);

  pinMode(14, OUTPUT);

  pinMode(15, OUTPUT);

  pinMode(16, OUTPUT);

  pinMode(17, OUTPUT);

  pinMode(18, OUTPUT);

  pinMode(19, OUTPUT);

  pinMode(20, OUTPUT);

  pinMode(21, OUTPUT);

  pinMode(22, OUTPUT);

  pinMode(23, OUTPUT);

  pinMode(24, OUTPUT);

  pinMode(25, OUTPUT);

  pinMode(26, OUTPUT);

  pinMode(27, OUTPUT);

  pinMode(28, OUTPUT);

  pinMode(29, OUTPUT);

  pinMode(30, OUTPUT);

  pinMode(31, OUTPUT);

  pinMode(32, OUTPUT);

  pinMode(33, OUTPUT);

  pinMode(34, OUTPUT);

  pinMode(35, OUTPUT);

  pinMode(36, OUTPUT);

  pinMode(37, OUTPUT);

  pinMode(38, OUTPUT);

  pinMode(39, OUTPUT);

  pinMode(40, OUTPUT);

  pinMode(41, OUTPUT);

  pinMode(42, OUTPUT);

  pinMode(43, OUTPUT);

  pinMode(44, OUTPUT);

  pinMode(45, OUTPUT);

  pinMode(46, OUTPUT);

  pinMode(47, OUTPUT);

  pinMode(48, OUTPUT);

  pinMode(49, OUTPUT);

  pinMode(50, OUTPUT);

  pm_and_fan();
  real_random(5000,10);

}

#define R11 A0

#define R12 A1

#define R13 A2

#define R14 A3

#define R21 A4

#define R22 A5

#define R23 A6

#define R24 A7

#define R31 A8

#define R32 A9

#define R33 A10

#define R34 A11

#define R41 A12

#define R42 A13

#define R43 A14

#define R44 A15

#define G11 2

#define G12 3

#define G13 4

#define G14 5

#define G21 6

#define G22 7

#define G23 8

#define G24 9

#define G31 10

#define G32 11

#define G33 12

#define G34 13

#define G41 24

#define G42 25

#define G43 26

#define G44 27

#define B11 28

#define B12 29

#define B13 30

#define B14 31

#define B21 32

#define B22 33

#define B23 34

#define B24 35

#define B31 36

#define B32 37

#define B33 38

#define B34 39

#define B41 40

#define B42 41

#define B43 42

#define B44 43

#define layer1 44

#define layer2 45

#define layer3 46

#define layer4 47


void rolling_yellow(){
  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 255);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, HIGH);digitalWrite(G23, HIGH);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, HIGH);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(500);
}
void all_off(){
  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 255);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, HIGH);digitalWrite(G23, HIGH);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, HIGH);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(layer1, LOW);
  digitalWrite(layer2, LOW);
  digitalWrite(layer3, LOW);
  digitalWrite(layer4, LOW);
}
void switch_red(int N){
  switch (N) {
case 0:
    
    analogWrite(R11, 50);
    digitalWrite(layer1, HIGH);
    break;
  case 1:
    
    analogWrite(R12, 50);
    digitalWrite(layer1, HIGH);
    break;
  case 2:
    
    analogWrite(R13, 50);
    digitalWrite(layer1, HIGH);
    break;
  case 3:
    
    analogWrite(R14, 50);
    digitalWrite(layer1, HIGH);
    break;
  case 4:
    
    analogWrite(R21 , 50);
    digitalWrite(layer1, HIGH);
    break;
  case 5:
    
    analogWrite(R22 , 50);
    digitalWrite(layer1, HIGH);
    break;
  case 6:
    
    analogWrite(R23 , 50);
    digitalWrite(layer1, HIGH);
    break;
  case 7:
    
    analogWrite(R24 , 50);
    digitalWrite(layer1, HIGH);
    break;
  case 8:
    
    analogWrite(R31 , 50);
    digitalWrite(layer1, HIGH);
    break;
  case 9:
    
    analogWrite(R32 , 50);
    digitalWrite(layer1, HIGH);
    break;
  case 10:
    
    analogWrite(R33 , 50);
    digitalWrite(layer1, HIGH);
    break;
  case 11:
    
    analogWrite(R34 , 50);
    digitalWrite(layer1, HIGH);
    break;
  case 12:
    
    analogWrite(R41 , 50);
    digitalWrite(layer1, HIGH);
    break;
  case 13:
    
    analogWrite(R42 , 50);
    digitalWrite(layer1, HIGH);
    break;
  case 14:
    
    analogWrite(R43 , 50);
    digitalWrite(layer1, HIGH);
    break;
  case 15:
    
    analogWrite(R44 , 50);
    digitalWrite(layer1, HIGH);
    break;
  case 16:
    
    analogWrite(R11 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 17:
    
    analogWrite(R12 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 18:
    
    analogWrite(R13 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 19:
    
    analogWrite(R14 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 20:
    
    analogWrite(R21 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 21:
    
    analogWrite(R22 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 22:
    
    analogWrite(R23 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 23:
    
    analogWrite(R24 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 24:
    
    analogWrite(R31 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 25:
    
    analogWrite(R32 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 26:
    
    analogWrite(R33 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 27:
    
    analogWrite(R34 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 28:
    
    analogWrite(R41 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 29:
    
    analogWrite(R42 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 30:
    
    analogWrite(R43 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 31:
    
    analogWrite(R44 , 50);
    digitalWrite(layer2, HIGH);
    break;
  case 32:
    
    analogWrite(R11, 50);
    digitalWrite(layer3, HIGH);
    break;
  case 33:
    
    analogWrite(R12 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 34:
    
    analogWrite(R13 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 35:
    
    analogWrite(R14 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 36:
    
    analogWrite(R21 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 37:
    
    analogWrite(R22 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 38:
    
    analogWrite(R23 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 39:
    
    analogWrite(R24 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 40:
    
    analogWrite(R31 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 41:
    
    analogWrite(R32 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 42:
    
    analogWrite(R33 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 43:
    
    analogWrite(R34 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 44:
    
    analogWrite(R41 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 45:
    
    analogWrite(R42 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 46:
    
    analogWrite(R43 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 47:
    
    analogWrite(R44 , 50);
    digitalWrite(layer3, HIGH);
    break;
  case 48:
    
    analogWrite(R11 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 49:
    
    analogWrite(R12 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 50:
    
    analogWrite(R13 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 51:
    
    analogWrite(R14 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 52:
    
    analogWrite(R21 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 53:
    
    analogWrite(R22 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 54:
    
    analogWrite(R23 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 55:
    
    analogWrite(R24 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 56:
    
    analogWrite(R31 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 57:
    
    analogWrite(R32 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 58:
    
    analogWrite(R33 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 59:
    
    analogWrite(R34 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 60:
    
    analogWrite(R41 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 61:
    
    analogWrite(R42 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 62:
    
    analogWrite(R43 , 50);
    digitalWrite(layer4, HIGH);
    break;
  case 63:
    
    analogWrite(R44 , 50);
    digitalWrite(layer4, HIGH);
    break;

  }
  
}
void random_light_red(int howlong, int howmany){
  int i, j;
  unsigned long previousT= millis();
  while(millis()-previousT<howlong){
  for(i = 0; i<howmany; i++){
    j = random(64);
    switch_red(j);
  }
  delay(250);
  all_off();
  }
}
void random_light_green(int howlong, int howmany){
  int i, j;
  unsigned long previousT= millis();
  while(millis()-previousT<howlong){
  for(i = 0; i<howmany; i++){
    j = random(64);
    switch_green(j);
  }
  delay(250);
  all_off();
  }
}
void random_light_blue(int howlong, int howmany){
  int i, j;
  unsigned long previousT= millis();
  while(millis()-previousT<howlong){
  for(i = 0; i<howmany; i++){
    j = random(64);
    switch_blue(j);
  }
  delay(250);
  all_off();
  }
}

void switch_green(int N){
  switch (N) {
  case 0:
    
    digitalWrite(G11, LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 1:
    
    digitalWrite(G12, LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 2:
    
    digitalWrite(G13, LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 3:
    
    digitalWrite(G14, LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 4:
    
    digitalWrite(G21 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 5:
    
    digitalWrite(G22 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 6:
    
    digitalWrite(G23 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 7:
    
    digitalWrite(G24 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 8:
    
    digitalWrite(G31 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 9:
    
    digitalWrite(G32 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 10:
    
    digitalWrite(G33 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 11:
    
    digitalWrite(G34 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 12:
    
    digitalWrite(G41 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 13:
    
    digitalWrite(G42 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 14:
    
    digitalWrite(G43 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 15:
    
    digitalWrite(G44 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 16:
    
    digitalWrite(G11 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 17:
    
    digitalWrite(G12 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 18:
    
    digitalWrite(G13 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 19:
    
    digitalWrite(G14 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 20:
    
    digitalWrite(G21 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 21:
    
    digitalWrite(G22 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 22:
    
    digitalWrite(G23 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 23:
    
    digitalWrite(G24 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 24:
    
    digitalWrite(G31 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 25:
    
    digitalWrite(G32 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 26:
    
    digitalWrite(G33 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 27:
    
    digitalWrite(G34 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 28:
    
    digitalWrite(G41 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 29:
    
    digitalWrite(G42 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 30:
    
    digitalWrite(G43 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 31:
    
    digitalWrite(G44 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 32:
    
    digitalWrite(G11, LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 33:
    
    digitalWrite(G12 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 34:
    
    digitalWrite(G13 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 35:
    
    digitalWrite(G14 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 36:
    
    digitalWrite(G21 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 37:
    
    digitalWrite(G22 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 38:
    
    digitalWrite(G23 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 39:
    
    digitalWrite(G24 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 40:
    
    digitalWrite(G31 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 41:
    
    digitalWrite(G32 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 42:
    
    digitalWrite(G33 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 43:
    
    digitalWrite(G34 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 44:
    
    digitalWrite(G41 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 45:
    
    digitalWrite(G42 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 46:
    
    digitalWrite(G43 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 47:
    
    digitalWrite(G44 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 48:
    
    digitalWrite(G11 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 49:
    
    digitalWrite(G12 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 50:
    
    digitalWrite(G13 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 51:
    
    digitalWrite(G14 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 52:
    
    digitalWrite(G21 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 53:
    
    digitalWrite(G22 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 54:
    
    digitalWrite(G23 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 55:
    
    digitalWrite(G24 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 56:
    
    digitalWrite(G31 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 57:
    
    digitalWrite(G32 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 58:
    
    digitalWrite(G33 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 59:
    
    digitalWrite(G34 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 60:
    
    digitalWrite(G41 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 61:
    
    digitalWrite(G42 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 62:
    
    digitalWrite(G43 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 63:
    
    digitalWrite(G44 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  }
  
}

void switch_blue(int N){
  switch (N) {
  case 0:
    
    digitalWrite(G11, LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 1:
    
    digitalWrite(G12, LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 2:
    
    digitalWrite(G13, LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 3:
    
    digitalWrite(G14, LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 4:
    
    digitalWrite(G21 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 5:
    
    digitalWrite(G22 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 6:
    
    digitalWrite(G23 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 7:
    
    digitalWrite(G24 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 8:
    
    digitalWrite(G31 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 9:
    
    digitalWrite(G32 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 10:
    
    digitalWrite(G33 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 11:
    
    digitalWrite(G34 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 12:
    
    digitalWrite(G41 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 13:
    
    digitalWrite(G42 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 14:
    
    digitalWrite(G43 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 15:
    
    digitalWrite(G44 , LOW);
    digitalWrite(layer1, HIGH);
    break;
  case 16:
    
    digitalWrite(G11 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 17:
    
    digitalWrite(G12 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 18:
    
    digitalWrite(G13 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 19:
    
    digitalWrite(G14 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 20:
    
    digitalWrite(G21 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 21:
    
    digitalWrite(G22 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 22:
    
    digitalWrite(G23 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 23:
    
    digitalWrite(G24 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 24:
    
    digitalWrite(G31 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 25:
    
    digitalWrite(G32 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 26:
    
    digitalWrite(G33 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 27:
    
    digitalWrite(G34 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 28:
    
    digitalWrite(G41 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 29:
    
    digitalWrite(G42 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 30:
    
    digitalWrite(G43 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 31:
    
    digitalWrite(G44 , LOW);
    digitalWrite(layer2, HIGH);
    break;
  case 32:
    
    digitalWrite(G11, LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 33:
    
    digitalWrite(G12 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 34:
    
    digitalWrite(G13 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 35:
    
    digitalWrite(G14 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 36:
    
    digitalWrite(G21 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 37:
    
    digitalWrite(G22 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 38:
    
    digitalWrite(G23 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 39:
    
    digitalWrite(G24 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 40:
    
    digitalWrite(G31 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 41:
    
    digitalWrite(G32 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 42:
    
    digitalWrite(G33 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 43:
    
    digitalWrite(G34 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 44:
    
    digitalWrite(G41 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 45:
    
    digitalWrite(G42 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 46:
    
    digitalWrite(G43 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 47:
    
    digitalWrite(G44 , LOW);
    digitalWrite(layer3, HIGH);
    break;
  case 48:
    
    digitalWrite(G11 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 49:
    
    digitalWrite(G12 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 50:
    
    digitalWrite(G13 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 51:
    
    digitalWrite(G14 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 52:
    
    digitalWrite(G21 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 53:
    
    digitalWrite(G22 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 54:
    
    digitalWrite(G23 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 55:
    
    digitalWrite(G24 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 56:
    
    digitalWrite(G31 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 57:
    
    digitalWrite(G32 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 58:
    
    digitalWrite(G33 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 59:
    
    digitalWrite(G34 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 60:
    
    digitalWrite(G41 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 61:
    
    digitalWrite(G42 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 62:
    
    digitalWrite(G43 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  case 63:
    
    digitalWrite(G44 , LOW);
    digitalWrite(layer4, HIGH);
    break;
  }
}
void switch_all(int N){
  switch(N){
case 0:
    analogWrite(R11, 50);
    break;
  case 1:
    analogWrite(R12, 50);
    break;
  case 2:
    analogWrite(R13, 50);
    break;
  case 3:
    analogWrite(R14, 50);
    break;
  case 4:
    analogWrite(R21, 50);
    break;
  case 5:
    analogWrite(R22, 50);
    break;
  case 6:
    analogWrite(R23, 50);
    break;
  case 7:
    analogWrite(R24, 50);
    break;
  case 8:
    analogWrite(R31, 50);
    break;
  case 9:
    analogWrite(R32, 50);
    break;
  case 10:
    analogWrite(R33, 50);
    break;
  case 11:
    analogWrite(R34, 50);
    break;
  case 12:
    analogWrite(R41, 50);
    break;
  case 13:
    analogWrite(R42, 50);
    break;
  case 14:
    analogWrite(R43, 50);
    break;
  case 15:
    analogWrite(R44, 50);
    break;

  case 16:
    digitalWrite(G11, LOW);
    break;
  case 17:
    digitalWrite(G12, LOW);
    break;
  case 18:
    digitalWrite(G13, LOW);
    break;
  case 19:
    digitalWrite(G14, LOW);
    break;
  case 20:
    digitalWrite(G21, LOW);
    break;
  case 21:
    digitalWrite(G22, LOW);
    break;
  case 22:
    digitalWrite(G23, LOW);
    break;
  case 23:
    digitalWrite(G24, LOW);
    break;
  case 24:
    digitalWrite(G31, LOW);
    break;
  case 25:
    digitalWrite(G32, LOW);
    break;
  case 26:
    digitalWrite(G33, LOW);
    break;
  case 27:
    digitalWrite(G34, LOW);
    break;
  case 28:
    digitalWrite(G41, LOW);
    break;
  case 29:
    digitalWrite(G42, LOW);
    break;
  case 30:
    digitalWrite(G43, LOW);
    break;
  case 31:
    digitalWrite(G44, LOW);
    break;
  case 32:
    digitalWrite(B11, LOW);
    break;
  case 33:
    digitalWrite(B12, LOW);
    break;
  case 34:
    digitalWrite(B13, LOW);
    break;
  case 35:
    digitalWrite(B14, LOW);
    break;
  case 36:
    digitalWrite(B21, LOW);
    break;
  case 37:
    digitalWrite(B22, LOW);
    break;
  case 38:
    digitalWrite(B23, LOW);
    break;
  case 39:
    digitalWrite(B24, LOW);
    break;
  case 40:
    digitalWrite(B31, LOW);
    break;
  case 41:
    digitalWrite(B32, LOW);
    break;
  case 42:
    digitalWrite(B33, LOW);
    break;
  case 43:
    digitalWrite(B34, LOW);
    break;
  case 44:
    digitalWrite(B41, LOW);
    break;
  case 45:
    digitalWrite(B42, LOW);
    break;
  case 46:
    digitalWrite(B43, LOW);
    break;
  case 47:
    digitalWrite(B44, LOW);
    break;

  }

}
void switch_layer(int N){
  switch(N){
  case 0:
    digitalWrite(layer1, HIGH);
    break;
  case 1:
    digitalWrite(layer2, HIGH);
    break;
  case 2:
    digitalWrite(layer3, HIGH);
    break;
  case 3:
    digitalWrite(layer4, HIGH);
    break;    
  }

}
void switch_layer_cal(int N){
  switch(N){
  case 0:
    digitalWrite(layer1, HIGH);
    break;
  case 1:
    digitalWrite(layer1, HIGH);
    digitalWrite(layer2, HIGH);
    break;
  case 2:
    digitalWrite(layer1, HIGH);
    digitalWrite(layer2, HIGH);
    digitalWrite(layer3, HIGH);
    break;
  case 3:
    digitalWrite(layer1, HIGH);
    digitalWrite(layer2, HIGH);
    digitalWrite(layer3, HIGH);
    digitalWrite(layer4, HIGH);
    break;    
  }

}
void real_random(int howlong, int howmany){
  int i, j, k, m, up, upn;
  unsigned long previousT= millis();
  while(millis()-previousT<howlong){
  for(i = 0; i<howmany; i++){
    j = random(48);
    switch_all(j);
  }
  //int how = random(2, 4);
  //for(k = 0; k<how; k++){
 //   m = random(4);
  //  switch_layer(m);
  //}
  delay(250);
  all_off();
  switch_layer_cal(up/2%4);
  up++;
  }
}
int color;
int pm_and_fan(){
  if (mySerial.available())   {  
       for(int i = 0; i < 32; i++)     {  
           chrRecv = mySerial.read();  
           if (chrRecv == START_2 ) {   
              bytCount1 = 2;  
              break;  
            }  
       }   
      if (bytCount1 == 2)  
      {  
         bytCount1 = 0;  
         for(int i = 0; i < 30; i++){  
            chrData[i] = mySerial.read();  
         }   
  
         if ( (unsigned int) chrData[ERROR_CODE] == 0 ) {  
            PM01  = GetPM_Data(chrData, PM1_0_ATMOSPHERE_H, PM1_0_ATMOSPHERE_L);  
            PM25  = GetPM_Data(chrData, PM2_5_ATMOSPHERE_H, PM2_5_ATMOSPHERE_L);  
            PM10  = GetPM_Data(chrData, PM10_ATMOSPHERE_H, PM10_ATMOSPHERE_L);  
            Serial.print("PM1.0=");  
            Serial.print(PM01);  
            Serial.print(",PM2.5=");  
            Serial.print(PM25);  
            Serial.print(",PM10=");  
            Serial.println(PM10);
            if (PM25<=35){
              digitalWrite(FAN, LOW);
              Serial.println("blue");
              color = 1;
            }else if(PM25<=75){
              digitalWrite(FAN, HIGH);
              Serial.println("yellow");
              color = 2;
            }else if(PM25>75&&PM25<3000){
              digitalWrite(FAN, HIGH);
              Serial.println("red");
              color = 3;
            }else if(PM25>3000){
              Serial.println("err");
            }
            }  
         else{  
            Serial.println("PMS7003  ERROR");  
         }  
      }   
   }  
   else{  
      Serial.println("PMS7003 NOT available");  
   }  
 return color;
}
void updown_blue(){
  
  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, LOW);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34, LOW);
  digitalWrite(B41, LOW);digitalWrite(B42, LOW);digitalWrite(B43, LOW);digitalWrite(B44, LOW);

  digitalWrite(44, HIGH);
  delay(60);

  digitalWrite(45, HIGH);
  delay(20);

  digitalWrite(46, HIGH);
  delay(60);

  digitalWrite(47, HIGH);
  delay(100);

  digitalWrite(47, LOW);
  delay(100);
  
    digitalWrite(46, LOW);
  delay(60);
  
  digitalWrite(45, LOW);
  delay(20);

  digitalWrite(44, LOW);
  delay(60);
  
  }

void updown_red(){
  
  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 50);
  analogWrite(R41, 50);analogWrite(R42, 50);analogWrite(R43, 50);analogWrite(R44, 50);


  digitalWrite(44, HIGH);
  delay(60);

  digitalWrite(45, HIGH);
  delay(20);

  digitalWrite(46, HIGH);
  delay(60);

  digitalWrite(47, HIGH);
  delay(100);

  digitalWrite(47, LOW);
  delay(100);
  
  digitalWrite(46, LOW);
  delay(60);
  
  digitalWrite(45, LOW);
  delay(20);

  digitalWrite(44, LOW);
  delay(60);
  
  }

 void updown_yellow(){//TRASHHHHHHHH
  
  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 50);
  analogWrite(R41, 50);analogWrite(R42, 50);analogWrite(R43, 50);analogWrite(R44, 50);

  digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, LOW);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, LOW);
  digitalWrite(G41, LOW);digitalWrite(G42, LOW);digitalWrite(G43, LOW);digitalWrite(G44, LOW);



  digitalWrite(44, HIGH);
  delay(60);

  digitalWrite(45, HIGH);
  delay(20);

  digitalWrite(46, HIGH);
  delay(60);

  digitalWrite(47, HIGH);
  delay(100);

  digitalWrite(47, LOW);
  delay(100);
  
    digitalWrite(46, LOW);
  delay(60);
  
  digitalWrite(45, LOW);
  delay(20);

  digitalWrite(44, LOW);
  delay(60);
  
  }

///SWIRL RYB

void swirl_red() {
  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, HIGH);digitalWrite(G23, HIGH);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, HIGH);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  
  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  
  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(75);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(75);

  analogWrite(R11, 50);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


 
  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(75);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);



  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(75);

  
  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


 
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  
  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  
  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


 
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 50);


  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 50);analogWrite(R44, 50);


  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 50);analogWrite(R43, 50);analogWrite(R44, 50);



  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 50);analogWrite(R43, 50);analogWrite(R44, 50);


 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 50);analogWrite(R42, 50);analogWrite(R43, 50);analogWrite(R44, 50);


  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(500);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 50);analogWrite(R43, 50);analogWrite(R44, 50);


 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 50);analogWrite(R44, 50);



 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 50);


  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);


  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);



  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);



 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);



  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  analogWrite(R11, 50);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);



 
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);


  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);



  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);


  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

 
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


 
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 255);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);
  
}
///////////////////////////////////////////
void swirl_blue(){


  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, LOW);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, LOW);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);

  
  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  
  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);

  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(75);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(75);

  digitalWrite(B11, LOW);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


 
  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(75);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);



  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(75);

  
  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, HIGH);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


 
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  
  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, LOW);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  
  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, LOW);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,LOW);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


 
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, LOW);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,LOW);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, LOW);


  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, LOW);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,LOW);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, LOW);digitalWrite(B44, LOW);


  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, LOW);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,LOW);
  digitalWrite(B41, HIGH);digitalWrite(B42, LOW);digitalWrite(B43, LOW);digitalWrite(B44, LOW);



  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);

  delay(200);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, LOW);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,LOW);
  digitalWrite(B41, LOW);digitalWrite(B42, LOW);digitalWrite(B43, LOW);digitalWrite(B44, LOW);


  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(500);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, LOW);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,LOW);
  digitalWrite(B41, HIGH);digitalWrite(B42, LOW);digitalWrite(B43, LOW);digitalWrite(B44, LOW);


 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, LOW);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,LOW);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, LOW);digitalWrite(B44, LOW);



 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, LOW);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,LOW);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, LOW);


  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, LOW);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,LOW);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);


  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, LOW);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);

 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, LOW);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);



  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, LOW);digitalWrite(B14, HIGH);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);



 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  digitalWrite(B11, LOW);digitalWrite(B12, LOW);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);



  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  digitalWrite(B11, LOW);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);



 
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);


  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, LOW);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);



  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);


  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, LOW);digitalWrite(B33, LOW);digitalWrite(B34,HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);

 
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, LOW);digitalWrite(B34,HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, LOW);digitalWrite(B23, LOW);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34,HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


 
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, LOW);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34,HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);


  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, HIGH);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34,HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);

  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(50);
  
}


//////////////////////////////////////////
void swirl_yellow() {




  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, LOW );digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  
  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  
  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  
  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(75);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(75);

  analogWrite(R11, 50);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, LOW);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

 
  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(75);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(75);

  
  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


  digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, HIGH);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

 
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  
  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, LOW);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33,LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);


 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  
  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, LOW);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33,LOW);digitalWrite(G34, LOW);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

 
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 50);

   digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, LOW);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, LOW);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, LOW);

  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 50);analogWrite(R44, 50);

   digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, LOW);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, LOW);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, LOW);digitalWrite(G44, LOW);


  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 50);analogWrite(R43, 50);analogWrite(R44, 50);

   digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, LOW);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, LOW);
  digitalWrite(G41, HIGH);digitalWrite(G42, LOW);digitalWrite(G43, LOW);digitalWrite(G44, LOW);

  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(150);

 

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 50);analogWrite(R42, 50);analogWrite(R43, 50);analogWrite(R44, 50);

   digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, LOW);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, LOW);
  digitalWrite(G41, LOW);digitalWrite(G42, LOW);digitalWrite(G43, LOW);digitalWrite(G44, LOW);
  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(500);
/////
  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 50);analogWrite(R43, 50);analogWrite(R44, 50);

   digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, LOW);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, LOW);
  digitalWrite(G41, HIGH);digitalWrite(G42, LOW);digitalWrite(G43, LOW);digitalWrite(G44, LOW);


 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 50);analogWrite(R44, 50);

   digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, LOW);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, LOW);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, LOW);digitalWrite(G44, LOW);

 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 50);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 50);

   digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, LOW);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, LOW);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, LOW);

  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,50);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, LOW);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33,LOW);digitalWrite(G34, LOW);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);


  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);


  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 50);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

   digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, LOW);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33,LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

 
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(100);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 50);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


  digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, LOW);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 50);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

    digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, LOW);digitalWrite(G14, HIGH);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  analogWrite(R11, 50);analogWrite(R12, 50);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, LOW);digitalWrite(G12, LOW);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  analogWrite(R11, 50);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, LOW);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);
  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 50);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);
  
  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, LOW);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

 
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);


  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 50);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);
  
  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, LOW);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(75);


  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 50);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, LOW);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

 
  digitalWrite(44, HIGH);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, HIGH);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 50);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, LOW);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);



  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 50);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, LOW);digitalWrite(G23, LOW);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);
 
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 50);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, LOW);digitalWrite(G23, HIGH);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

   digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, HIGH);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);

  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 255);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34,255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, HIGH);digitalWrite(G23, HIGH);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);
  
  digitalWrite(44, LOW);
  digitalWrite(45, HIGH);
  digitalWrite(46, HIGH);
  digitalWrite(47, LOW);
  delay(50);
  
}

void wind_blue(){
  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 255);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, HIGH);digitalWrite(G23, HIGH);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, HIGH);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(44, LOW);
  digitalWrite(45, LOW);
  digitalWrite(46, LOW);
  digitalWrite(47, LOW);
  delay(100);

 
  digitalWrite(layer1, HIGH);
  digitalWrite(layer2, HIGH);                           
  digitalWrite(layer3, HIGH); 
  digitalWrite(layer4, HIGH); 
  digitalWrite(B11, LOW);digitalWrite(B22, LOW);digitalWrite(B33, LOW);digitalWrite(B44, LOW); delay(100);
  digitalWrite(B11,HIGH);digitalWrite(B44, HIGH);
  digitalWrite(B12, LOW);digitalWrite(B22, LOW);digitalWrite(B33, LOW);digitalWrite(B43, LOW); delay(100);
  digitalWrite(B12, HIGH);digitalWrite(B22, HIGH);digitalWrite(B33, HIGH);digitalWrite(B43, HIGH);
  digitalWrite(B13, LOW);digitalWrite(B23, LOW);digitalWrite(B32, LOW);digitalWrite(B42, LOW); delay(100);
  digitalWrite(B13, HIGH);digitalWrite(B42, HIGH);
  digitalWrite(B14, LOW);digitalWrite(B23, LOW);digitalWrite(B32, LOW);digitalWrite(B41, LOW); delay(100);
  digitalWrite(B14, HIGH);digitalWrite(B41, HIGH);
  digitalWrite(B24, LOW);digitalWrite(B23, LOW);digitalWrite(B32, LOW);digitalWrite(B31, LOW); delay(100);
  digitalWrite(B24, HIGH);digitalWrite(B23, HIGH);digitalWrite(B32, HIGH);digitalWrite(B31, HIGH);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B33, LOW);digitalWrite(B34, LOW); delay(100);
  digitalWrite(B21, HIGH);digitalWrite(B34,HIGH);
  
  
  digitalWrite(B11, LOW);digitalWrite(B22, LOW);digitalWrite(B33, LOW);digitalWrite(B44, LOW); delay(100);
  digitalWrite(B11,HIGH);digitalWrite(B44, HIGH);
  digitalWrite(B12, LOW);digitalWrite(B22, LOW);digitalWrite(B33, LOW);digitalWrite(B43, LOW); delay(100);
  digitalWrite(B12, HIGH);digitalWrite(B22, HIGH);digitalWrite(B33, HIGH);digitalWrite(B43, HIGH);
  digitalWrite(B13, LOW);digitalWrite(B23, LOW);digitalWrite(B32, LOW);digitalWrite(B42, LOW); delay(100);
  digitalWrite(B13, HIGH);digitalWrite(B42, HIGH);
  digitalWrite(B14, LOW);digitalWrite(B23, LOW);digitalWrite(B32, LOW);digitalWrite(B41, LOW); delay(100);
  digitalWrite(B14, HIGH);digitalWrite(B41, HIGH);
  digitalWrite(B24, LOW);digitalWrite(B23, LOW);digitalWrite(B32, LOW);digitalWrite(B31, LOW); delay(100);
  digitalWrite(B24, HIGH);digitalWrite(B23, HIGH);digitalWrite(B32, HIGH);digitalWrite(B31, HIGH);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B33, LOW);digitalWrite(B34, LOW); delay(100);
  digitalWrite(B21, HIGH);digitalWrite(B34,HIGH);

  digitalWrite(B11, LOW);digitalWrite(B22, LOW);digitalWrite(B33, LOW);digitalWrite(B44, LOW); delay(100);
  digitalWrite(B11,HIGH);digitalWrite(B44, HIGH);
  digitalWrite(B12, LOW);digitalWrite(B22, LOW);digitalWrite(B33, LOW);digitalWrite(B43, LOW); delay(100);
  digitalWrite(B12, HIGH);digitalWrite(B22, HIGH);digitalWrite(B33, HIGH);digitalWrite(B43, HIGH);
  digitalWrite(B13, LOW);digitalWrite(B23, LOW);digitalWrite(B32, LOW);digitalWrite(B42, LOW); delay(100);
  digitalWrite(B13, HIGH);digitalWrite(B42, HIGH);
  digitalWrite(B14, LOW);digitalWrite(B23, LOW);digitalWrite(B32, LOW);digitalWrite(B41, LOW); delay(100);
  digitalWrite(B14, HIGH);digitalWrite(B41, HIGH);
  digitalWrite(B24, LOW);digitalWrite(B23, LOW);digitalWrite(B32, LOW);digitalWrite(B31, LOW); delay(100);
  digitalWrite(B24, HIGH);digitalWrite(B23, HIGH);digitalWrite(B32, HIGH);digitalWrite(B31, HIGH);
  digitalWrite(B21, LOW);digitalWrite(B22, LOW);digitalWrite(B33, LOW);digitalWrite(B34, LOW); delay(100);
  

} 

////LATTIC RYB

void lattice_red(){
  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 255);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, HIGH);digitalWrite(G23, HIGH);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, HIGH);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(44, LOW);
  digitalWrite(45, LOW);
  digitalWrite(46, LOW);
  digitalWrite(47, LOW);
  delay(500);

 
  digitalWrite(layer1, HIGH);
                              analogWrite(R41, 50); 
  digitalWrite(layer2, HIGH); 
                              analogWrite(R31, 50); analogWrite(R32, 50); analogWrite(R42, 50); delay(500);
  digitalWrite(layer1, LOW); 
                             analogWrite(R41, 255);   
  digitalWrite(layer2, LOW); 
                             analogWrite(R31, 255); analogWrite(R32, 255); analogWrite(R42, 255);                       
  digitalWrite(layer3, HIGH); 
                              analogWrite(R23, 50);
  digitalWrite(layer4, HIGH); 
                              analogWrite(R13, 50);analogWrite(R14, 50); analogWrite(R24, 50); delay(500);
                              
  digitalWrite(layer3, LOW); 
                              analogWrite(R23, 255);
  digitalWrite(layer4, LOW);
                              analogWrite(R13, 255);analogWrite(R14, 255); analogWrite(R24, 255);
  digitalWrite(layer1, HIGH);
                              analogWrite(R11, 50); 
  digitalWrite(layer2, HIGH);
                              analogWrite(R12, 50); analogWrite(R21, 50); analogWrite(R22, 50); delay(500);
  digitalWrite(layer1, LOW);
                              analogWrite(R11, 255); 
  digitalWrite(layer2, LOW);
                              analogWrite(R12, 255); analogWrite(R21,255); analogWrite(R22, 255);
  digitalWrite(layer1, HIGH);
                              analogWrite(R33, 50); 
  digitalWrite(layer2, HIGH);
                              analogWrite(R34, 50); analogWrite(R43, 50); analogWrite(R44, 50); delay(500);
  digitalWrite(layer1, LOW);
                              analogWrite(R33, 255);                                                                                       
  digitalWrite(layer2, LOW);
                              analogWrite(R34, 255); analogWrite(R43, 255); analogWrite(R44, 255);
  digitalWrite(layer3, HIGH);
                              analogWrite(R41, 50); 
  digitalWrite(layer4, HIGH); 
                              analogWrite(R31, 50); analogWrite(R32, 50); analogWrite(R42, 50); delay(500);
  digitalWrite(layer3, LOW); 
                              analogWrite(R41, 255); 
  digitalWrite(layer4, LOW);
                              analogWrite(R31, 255); analogWrite(R32, 255); analogWrite(R42, 255);
  digitalWrite(layer1, HIGH);  
                              analogWrite(R23, 50);
  digitalWrite(layer2, HIGH);
                              analogWrite(R13, 50);analogWrite(R14, 50); analogWrite(R24, 50); delay(500);
  digitalWrite(layer1, LOW);
                              analogWrite(R23, 255);
  digitalWrite(layer2, LOW); 
                              analogWrite(R13, 255);analogWrite(R14, 255); analogWrite(R24, 255);    
  digitalWrite(layer3, HIGH);
                              analogWrite(R11, 50); 
  digitalWrite(layer4, HIGH);
                              analogWrite(R12, 50); analogWrite(R21, 50); analogWrite(R22, 50); delay(500);       
  digitalWrite(layer3, LOW); 
                              analogWrite(R11, 255); 
  digitalWrite(layer4, LOW); 
                              analogWrite(R12, 255); analogWrite(R21, 255); analogWrite(R22, 255);    
  digitalWrite(layer3, HIGH);
                              analogWrite(R33, 50); 
  digitalWrite(layer4, HIGH); 
                              analogWrite(R34, 50); analogWrite(R43, 50); analogWrite(R44, 50);                                                                      
} 

void lattice_yellow(){
  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 255);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, HIGH);digitalWrite(G23, HIGH);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, HIGH);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(44, LOW);
  digitalWrite(45, LOW);
  digitalWrite(46, LOW);
  digitalWrite(47, LOW);
  delay(500);

 
  digitalWrite(layer1, HIGH); digitalWrite(G41, LOW); 
                              analogWrite(R41, 50); 
  digitalWrite(layer2, HIGH); digitalWrite(G31, LOW); digitalWrite(G32, LOW); digitalWrite(G42, LOW); 
                              analogWrite(R31, 50); analogWrite(R32, 50); analogWrite(R42, 50); delay(500);
  digitalWrite(layer1, LOW); digitalWrite(G41, HIGH); 
                             analogWrite(R41, 255);   
  digitalWrite(layer2, LOW); digitalWrite(G31, HIGH); digitalWrite(G32, HIGH);digitalWrite(G42, HIGH); 
                             analogWrite(R31, 255); analogWrite(R32, 255); analogWrite(R42, 255);                       
  digitalWrite(layer3, HIGH);  digitalWrite(G23, LOW);
                              analogWrite(R23, 50);
  digitalWrite(layer4, HIGH); digitalWrite(G13, LOW); digitalWrite(G14, LOW); digitalWrite(G24, LOW); 
                              analogWrite(R13, 50);analogWrite(R14, 50); analogWrite(R24, 50); delay(500);
                              
  digitalWrite(layer3, LOW);  digitalWrite(G23, HIGH);
                              analogWrite(R23, 255);
  digitalWrite(layer4, LOW); digitalWrite(G13, HIGH); digitalWrite(G14, HIGH); digitalWrite(G24, HIGH); 
                              analogWrite(R13, 255);analogWrite(R14, 255); analogWrite(R24, 255);
  digitalWrite(layer1, HIGH); digitalWrite(G11, LOW); 
                              analogWrite(R11, 50); 
  digitalWrite(layer2, HIGH); digitalWrite(G12, LOW); digitalWrite(G21, LOW);digitalWrite(G22, LOW); 
                              analogWrite(R12, 50); analogWrite(R21, 50); analogWrite(R22, 50); delay(500);
  digitalWrite(layer1, LOW); digitalWrite(G11, HIGH); 
                              analogWrite(R11, 255); 
  digitalWrite(layer2, LOW); digitalWrite(G12, HIGH); digitalWrite(G21,  HIGH);digitalWrite(G22, HIGH); 
                              analogWrite(R12, 255); analogWrite(R21,255); analogWrite(R22, 255);
  digitalWrite(layer1, HIGH); digitalWrite(G33, LOW); 
                              analogWrite(R33, 50); 
  digitalWrite(layer2, HIGH); digitalWrite(G34, LOW); digitalWrite(G43, LOW);digitalWrite(G44, LOW); 
                              analogWrite(R34, 50); analogWrite(R43, 50); analogWrite(R44, 50); delay(500);
  digitalWrite(layer1, LOW); digitalWrite(G33, HIGH); 
                              analogWrite(R33, 255);                                                                                       
  digitalWrite(layer2, LOW); digitalWrite(G34, HIGH); digitalWrite(G43, HIGH);digitalWrite(G44, HIGH); 
                              analogWrite(R34, 255); analogWrite(R43, 255); analogWrite(R44, 255);
  digitalWrite(layer3, HIGH); digitalWrite(G41, LOW); 
                              analogWrite(R41, 50); 
  digitalWrite(layer4, HIGH); digitalWrite(G31, LOW); digitalWrite(G32, LOW); digitalWrite(G42, LOW); 
                              analogWrite(R31, 50); analogWrite(R32, 50); analogWrite(R42, 50); delay(500);
  digitalWrite(layer3, LOW); digitalWrite(G41, HIGH); 
                              analogWrite(R41, 255); 
  digitalWrite(layer4, LOW); digitalWrite(G31, HIGH); digitalWrite(G32, HIGH); digitalWrite(G42, HIGH); 
                              analogWrite(R31, 255); analogWrite(R32, 255); analogWrite(R42, 255);
  digitalWrite(layer1, HIGH);  digitalWrite(G23, LOW);
                              analogWrite(R23, 50);
  digitalWrite(layer2, HIGH); digitalWrite(G13, LOW); digitalWrite(G14, LOW); digitalWrite(G24, LOW); 
                              analogWrite(R13, 50);analogWrite(R14, 50); analogWrite(R24, 50); delay(500);
  digitalWrite(layer1, LOW);  digitalWrite(G23, HIGH);
                              analogWrite(R23, 255);
  digitalWrite(layer2, LOW); digitalWrite(G13, HIGH); digitalWrite(G14, HIGH); digitalWrite(G24, HIGH); 
                              analogWrite(R13, 255);analogWrite(R14, 255); analogWrite(R24, 255);    
  digitalWrite(layer3, HIGH); digitalWrite(G11, LOW); 
                              analogWrite(R11, 50); 
  digitalWrite(layer4, HIGH); digitalWrite(G12, LOW); digitalWrite(G21, LOW);digitalWrite(G22, LOW); 
                              analogWrite(R12, 50); analogWrite(R21, 50); analogWrite(R22, 50); delay(500);       
  digitalWrite(layer3, LOW); digitalWrite(G11, HIGH); 
                              analogWrite(R11, 255); 
  digitalWrite(layer4, LOW); digitalWrite(G12, HIGH); digitalWrite(G21, HIGH);digitalWrite(G22, HIGH); 
                              analogWrite(R12, 255); analogWrite(R21, 255); analogWrite(R22, 255);    
  digitalWrite(layer3, HIGH); digitalWrite(G33, LOW); 
                              analogWrite(R33, 50); 
  digitalWrite(layer4, HIGH); digitalWrite(G34, LOW); digitalWrite(G43, LOW);digitalWrite(G44, LOW); 
                              analogWrite(R34, 50); analogWrite(R43, 50); analogWrite(R44, 50);                                                                      
} 

void lattice_blue(){
  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 255);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, HIGH);digitalWrite(G23, HIGH);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, HIGH);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(44, LOW);
  digitalWrite(45, LOW);
  digitalWrite(46, LOW);
  digitalWrite(47, LOW);
  delay(500);

 
  digitalWrite(layer1, HIGH); digitalWrite(B41, LOW); 
                              
  digitalWrite(layer2, HIGH); digitalWrite(B31, LOW); digitalWrite(B32, LOW); digitalWrite(B42, LOW); 
                              delay(500);
  digitalWrite(layer1, LOW); digitalWrite(B41, HIGH); 
                            
  digitalWrite(layer2, LOW); digitalWrite(B31, HIGH); digitalWrite(B32, HIGH);digitalWrite(B42, HIGH); 
                                                
  digitalWrite(layer3, HIGH);  digitalWrite(B23, LOW);
                         
  digitalWrite(layer4, HIGH); digitalWrite(B13, LOW); digitalWrite(B14, LOW); digitalWrite(B24, LOW); 
                           delay(500);
                              
  digitalWrite(layer3, LOW);  digitalWrite(B23, HIGH);
                             
  digitalWrite(layer4, LOW); digitalWrite(B13, HIGH); digitalWrite(B14, HIGH); digitalWrite(B24, HIGH); 
                            
  digitalWrite(layer1, HIGH); digitalWrite(B11, LOW); 
                            
  digitalWrite(layer2, HIGH); digitalWrite(B12, LOW); digitalWrite(B21, LOW);digitalWrite(B22, LOW); 
                            delay(500);
  digitalWrite(layer1, LOW); digitalWrite(B11, HIGH); 
                             
  digitalWrite(layer2, LOW); digitalWrite(B12, HIGH); digitalWrite(B21,  HIGH);digitalWrite(B22, HIGH); 
                            
  digitalWrite(layer1, HIGH); digitalWrite(B33, LOW); 
                             
  digitalWrite(layer2, HIGH); digitalWrite(B34, LOW); digitalWrite(B43, LOW);digitalWrite(B44, LOW); 
                             delay(500);
  digitalWrite(layer1, LOW); digitalWrite(B33, HIGH); 
                                                                                                          
  digitalWrite(layer2, LOW); digitalWrite(B34, HIGH); digitalWrite(B43, HIGH);digitalWrite(B44, HIGH); 
                           
  digitalWrite(layer3, HIGH); digitalWrite(B41, LOW); 
                         
  digitalWrite(layer4, HIGH); digitalWrite(B31, LOW); digitalWrite(B32, LOW); digitalWrite(B42, LOW); 
                             delay(500);
  digitalWrite(layer3, LOW); digitalWrite(B41, HIGH); 
                            
  digitalWrite(layer4, LOW); digitalWrite(B31, HIGH); digitalWrite(B32, HIGH); digitalWrite(B42, HIGH); 
                          
  digitalWrite(layer1, HIGH);  digitalWrite(B23, LOW);
                           
  digitalWrite(layer2, HIGH); digitalWrite(B13, LOW); digitalWrite(B14, LOW); digitalWrite(B24, LOW); 
                              delay(500);
  digitalWrite(layer1, LOW);  digitalWrite(B23, HIGH);
                            
  digitalWrite(layer2, LOW); digitalWrite(B13, HIGH); digitalWrite(B14, HIGH); digitalWrite(B24, HIGH); 
                             
  digitalWrite(layer3, HIGH); digitalWrite(B11, LOW); 
                             
  digitalWrite(layer4, HIGH); digitalWrite(B12, LOW); digitalWrite(B21, LOW);digitalWrite(B22, LOW); 
                             delay(500);       
  digitalWrite(layer3, LOW); digitalWrite(B11, HIGH); 
                             
  digitalWrite(layer4, LOW); digitalWrite(B12, HIGH); digitalWrite(B21, HIGH);digitalWrite(B22, HIGH); 
                               
  digitalWrite(layer3, HIGH); digitalWrite(B33, LOW); 
                           
  digitalWrite(layer4, HIGH); digitalWrite(B34, LOW); digitalWrite(B43, LOW);digitalWrite(B44, LOW); 
                                                                                                 
} 
////WAVE RYB
void wave_red(){
  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 255);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);


  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, HIGH);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(44, LOW);
  digitalWrite(45, LOW);
  digitalWrite(46, LOW);
  digitalWrite(47, LOW);
  delay(500);

 
  digitalWrite(layer1, HIGH); 
                              analogWrite(R41, 50); delay(200);
  digitalWrite(layer2, HIGH); 
                              analogWrite(R31, 50); analogWrite(R32, 50); analogWrite(R42, 50); delay(200);
  digitalWrite(layer3, HIGH); 
                              analogWrite(R21, 50); analogWrite(R22, 50); analogWrite(R23, 50);analogWrite(R33, 50); analogWrite(R43, 50); delay(200);
  digitalWrite(layer4, HIGH); 
                              analogWrite(R11, 50); analogWrite(R12, 50); analogWrite(R13, 50);analogWrite(R14, 50); analogWrite(R24, 50);analogWrite(R34, 50); analogWrite(R44, 50); delay(200);
   
  
} 

void wave_yellow(){
  analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 255);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, HIGH);digitalWrite(G23, HIGH);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, HIGH);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(44, LOW);
  digitalWrite(45, LOW);
  digitalWrite(46, LOW);
  digitalWrite(47, LOW);
  delay(500);

 
  digitalWrite(layer1, HIGH); digitalWrite(G41, LOW); 
                              analogWrite(R41, 50); delay(200);
  digitalWrite(layer2, HIGH); digitalWrite(G31, LOW); digitalWrite(G32, LOW);digitalWrite(G42, LOW); 
                              analogWrite(R31, 50); analogWrite(R32, 50); analogWrite(R42, 50); delay(200);
  digitalWrite(layer3, HIGH); digitalWrite(G21, LOW); digitalWrite(G22, LOW); digitalWrite(G23, LOW); digitalWrite(G33, LOW); digitalWrite(G43, LOW); 
                              analogWrite(R21, 50); analogWrite(R22, 50); analogWrite(R23, 50);analogWrite(R33, 50); analogWrite(R43, 50); delay(200);
  digitalWrite(layer4, HIGH); digitalWrite(G11, LOW); digitalWrite(G12, LOW); digitalWrite(G13, LOW); digitalWrite(G14, LOW); digitalWrite(G24, LOW); digitalWrite(G34, LOW); digitalWrite(G44, LOW); 
                              analogWrite(R11, 50); analogWrite(R12, 50); analogWrite(R13, 50);analogWrite(R14, 50); analogWrite(R24, 50);analogWrite(R34, 50); analogWrite(R44, 50); delay(200);
   
  
} 


void wave_blue(){
   analogWrite(R11, 255);analogWrite(R12, 255);analogWrite(R13, 255);analogWrite(R14, 255);
  analogWrite(R21, 255);analogWrite(R22, 255);analogWrite(R23, 255);analogWrite(R24, 255);
  analogWrite(R31, 255);analogWrite(R32, 255);analogWrite(R33, 255);analogWrite(R34, 255);
  analogWrite(R41, 255);analogWrite(R42, 255);analogWrite(R43, 255);analogWrite(R44, 255);

  digitalWrite(G11, HIGH);digitalWrite(G12, HIGH);digitalWrite(G13, HIGH);digitalWrite(G14, HIGH);
  digitalWrite(G21, HIGH);digitalWrite(G22, HIGH);digitalWrite(G23, HIGH);digitalWrite(G24, HIGH);
  digitalWrite(G31, HIGH);digitalWrite(G32, HIGH);digitalWrite(G33, HIGH);digitalWrite(G34, HIGH);
  digitalWrite(G41, HIGH);digitalWrite(G42, HIGH);digitalWrite(G43, HIGH);digitalWrite(G44, HIGH);

  digitalWrite(B11, HIGH);digitalWrite(B12, HIGH);digitalWrite(B13, HIGH);digitalWrite(B14, HIGH);
  digitalWrite(B21, HIGH);digitalWrite(B22, HIGH);digitalWrite(B23, HIGH);digitalWrite(B24, HIGH);
  digitalWrite(B31, HIGH);digitalWrite(B32, HIGH);digitalWrite(B33, HIGH);digitalWrite(B34, HIGH);
  digitalWrite(B41, HIGH);digitalWrite(B42, HIGH);digitalWrite(B43, HIGH);digitalWrite(B44, HIGH);
  
  digitalWrite(44, LOW);
  digitalWrite(45, LOW);
  digitalWrite(46, LOW);
  digitalWrite(47, LOW);
  delay(500);

 
  digitalWrite(layer1, HIGH); digitalWrite(B41, LOW); delay(200);
  digitalWrite(layer2, HIGH); digitalWrite(B31, LOW); digitalWrite(B41, LOW); digitalWrite(B32, LOW);digitalWrite(B42, LOW); delay(200);
  digitalWrite(layer3, HIGH); digitalWrite(B21, LOW); digitalWrite(B22, LOW); digitalWrite(B23, LOW); digitalWrite(B33, LOW); digitalWrite(B43, LOW); delay(200);
  digitalWrite(layer4, HIGH); digitalWrite(B11, LOW); digitalWrite(B12, LOW); digitalWrite(B13, LOW); digitalWrite(B14, LOW); digitalWrite(B24, LOW); digitalWrite(B34, LOW); digitalWrite(B44, LOW); delay(200);
   
  
}

void random_blue(){
  int shape = random(0, 5);
switch(shape){
  case 0:
    wind_blue();
    break;
  case 1:
    updown_blue();
    break;
  case 2:
    swirl_blue();
    break;
  case 3:
    lattice_blue();
    break;    
  case 4:
    wave_blue();
    break;
  }
}
void random_red(){
 int  shape = random(0, 4);
switch(shape){
  case 0:
    updown_red();
    break;
  case 1:
    swirl_red();
    break;
  case 2:
    lattice_red();
    break;    
  case 3:
    wave_red();
    break;
  }
}
void random_yellow(){
  int shape = random(0, 4);
switch(shape){
  case 0:
    updown_yellow();
    break;
  case 1:
    swirl_yellow();
    break;
  case 2:
    lattice_yellow();
    break;    
  case 3:
    wave_yellow();
    break;
  }
}
void loop(){
  //real_random(1000, 10);
  pm_and_fan();
  
  Serial.println(color);
  if(color == 1){
    random_blue();
  }else if(color == 2){
    random_yellow();
  }else if(color == 3){
    random_red();
  }else{
  delay(500);
  }

}


