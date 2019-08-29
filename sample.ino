#include <SoftwareSerial.h>  
SoftwareSerial mySerial(7,6); // Arudino Uno port RX, TX  
  
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
#define FAN 8
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
  
void setup(){  
  Serial.begin(115200);  
  Serial.println("PMS7003 Ready ");  
  mySerial.begin(9600);  
  pinMode(8,OUTPUT);
  pinMode(2,OUTPUT);
}  
  
void loop(){  
  digitalWrite(2,HIGH);
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
            if (PM25>22){
              digitalWrite(FAN, HIGH);
              Serial.println("HIHIHIH");
            }else{
              digitalWrite(FAN, LOW);
              Serial.println("LOLOLOLOL");
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
 delay(1000);  
}  
