/* Simple Smart Home 2022
 * Program: https://github.com/bywahjoe/SmartHomeIndra
 * 
 */

#include <SoftwareSerial.h>
#include "pinku.h"

//Relay
#define roomAON digitalWrite(relayA,LOW);
#define roomBON digitalWrite(relayB,LOW);
#define roomCON digitalWrite(relayC,LOW);
#define roomDON digitalWrite(relayD,LOW);
#define roomEON digitalWrite(relayE,LOW);
#define roomFON digitalWrite(relayF,LOW);

#define roomAOFF digitalWrite(relayA,HIGH);
#define roomBOFF digitalWrite(relayB,HIGH);
#define roomCOFF digitalWrite(relayC,HIGH);
#define roomDOFF digitalWrite(relayD,HIGH);
#define roomEOFF digitalWrite(relayE,HIGH);
#define roomFOFF digitalWrite(relayF,HIGH);

//Sensor
#define mysensorA digitalRead(sensorA)
#define mysensorB digitalRead(sensorB)
#define mysensorC digitalRead(sensorC)
#define mysensorD digitalRead(sensorD)
#define mysensorE digitalRead(sensorE)
#define mysensorF digitalRead(sensorF)

SoftwareSerial ser(myRX, myTX);
bool isAuto = true;
bool optionReady = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  ser.begin(9600);

  pinMode(sensorA, INPUT);
  pinMode(sensorB, INPUT);
  pinMode(sensorC, INPUT);
  pinMode(sensorD, INPUT);
  pinMode(sensorE, INPUT);
  pinMode(sensorF, INPUT);

  //Relay
  pinMode(relayA, OUTPUT);
  pinMode(relayB, OUTPUT);
  pinMode(relayC, OUTPUT);
  pinMode(relayD, OUTPUT);
  pinMode(relayE, OUTPUT);
  pinMode(relayF, OUTPUT);

  //Relay Reset
  roomAOFF;
  roomBOFF;
  roomCOFF;
  roomDOFF;
  roomEOFF;
  roomFOFF;
  //  roomDON;
  Serial.println("ARDUINO START");
}

void loop() {
  //Serial
  char data = '-';
  if (ser.available() > 0) {
    data = char(ser.read());
    Serial.print("RECV:");
    Serial.println(data);
    if (data == 'Y') {
      isAuto = true;
      optionReady = false;
    }
    else if (data == 'N') {
      isAuto = false;
    }
    else if (data != 'Y' && data != 'N') {
      optionReady = true;
    }
  }

  //Mode
  if (isAuto)modeAuto();
  else {
    if (optionReady) {
      modeManual(data);
    }
  }
}
void modeAuto() {
  Serial.print("ROOM A");Serial.println(mysensorA);
  Serial.print("ROOM B");Serial.println(mysensorB);
  Serial.print("ROOM C");Serial.println(mysensorC);
  Serial.print("ROOM D");Serial.println(mysensorD);
  Serial.print("ROOM E");Serial.println(mysensorE);
  Serial.print("ROOM F");Serial.println(mysensorF);

  
  //A
  if (mysensorA) {
    roomAON;
  }
  else {
    roomAOFF;
  }

  //B
  if (mysensorB) {
    roomBON;
  }
  else {
    roomBOFF;
  }

  //C
  if (mysensorC) {
    roomCON;
  }
  else {
    roomCOFF;
  }

  //D
  if (mysensorD) {
    roomDON;
  }
  else {
    roomDOFF;
  }

  //E
  if (mysensorE) {
    roomEON;
  }
  else {
    roomEOFF;
  }

  //F
  if (mysensorF) {
    roomFON;
  }
  else {
    roomFOFF;
  }
}

void modeManual(char option) {
  if (option == 'A') {
    roomAON;
  }
  else if (option == 'B') {
    roomBON;
  }
  else if (option == 'C') {
    roomCON;
  }
  else if (option == 'D') {
    roomDON;
  }
  else if (option == 'E') {
    roomEON;
  }
  else if (option == 'F') {
    roomFON;
  }
  else if (option == '1') {
    roomAOFF;
  }
  else if (option == '2') {
    roomBOFF;
  }
  else if (option == '3') {
    roomCOFF;
  }
  else if (option == '4') {
    roomDOFF;
  }
  else if (option == '5') {
    roomEOFF;
  }
  else if (option == '6') {
    roomFOFF;
  }
  else {}

  Serial.print("OPTION:"); Serial.println(option);

}
