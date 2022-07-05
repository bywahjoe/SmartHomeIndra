/* Simple Smart Home 2022
 * Program: https://github.com/bywahjoe/SmartHomeIndra
 * 
 */

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SoftwareSerial.h>

//Blynk
//#define BLYNK_TEMPLATE_ID "TMPL_F9xpXCF"
//#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "iFcF7yGQtvmbdQz9cMuxo00-zskbfTny"
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "robotku";
char pass[] = "robot1234";

//Timer
unsigned long nows = 0, before = 0;

//Pin
#define ESPRX D2
#define ESPTX D3
#define led   D7
#define ledON digitalWrite(led,HIGH);
#define ledOFF digitalWrite(led,LOW);

SoftwareSerial ser(ESPRX, ESPTX);
bool isAuto = true;

//ABCDEF - ON
//123456 - OFF
//YN - MANUAL

BLYNK_WRITE(V10) {
  int btn = param.asInt(); //Cek Data Button
  Serial.print("BUTTONV10:"); Serial.println(btn);

  if (btn == 1) {
    isAuto = true;
    ser.write('Y');
  }
  if (btn == 2) {
    isAuto = false;
    ser.write('N');
  }
}
BLYNK_WRITE(V1) {
  int btn = param.asInt(); //Cek Data Button
  Serial.print("BUTTONV1:"); Serial.println(btn);

  if (!isAuto) {
    if (btn == 1)ser.write('A'); //1-ON , 0-OFF
    if (btn == 0)ser.write('1');
  }
}
BLYNK_WRITE(V2) {
  int btn = param.asInt(); //Cek Data Button
  Serial.print("BUTTONV2:"); Serial.println(btn);

  if (!isAuto) {
    if (btn == 1)ser.write('B'); //1-ON , 0-OFF
    if (btn == 0)ser.write('2');
  }
}
BLYNK_WRITE(V3) {
  int btn = param.asInt(); //Cek Data Button
  Serial.print("BUTTONV3:"); Serial.println(btn);

  if (!isAuto) {
    if (btn == 1)ser.write('C'); //1-ON , 0-OFF
    if (btn == 0)ser.write('3');
  }
}
BLYNK_WRITE(V4) {
  int btn = param.asInt(); //Cek Data Button
  Serial.print("BUTTONV4:"); Serial.println(btn);

  if (!isAuto) {
    if (btn == 1)ser.write('D'); //1-ON , 0-OFF
    if (btn == 0)ser.write('4');
  }
}
BLYNK_WRITE(V5) {
  int btn = param.asInt(); //Cek Data Button
  Serial.print("BUTTONV5:"); Serial.println(btn);

  if (!isAuto) {
    if (btn == 1)ser.write('E'); //1-ON , 0-OFF
    if (btn == 0)ser.write('5');
  }
}
BLYNK_WRITE(V6) {
  int btn = param.asInt(); //Cek Data Button
  Serial.print("BUTTONV6:"); Serial.println(btn);

  if (!isAuto) {
    if (btn == 1)ser.write('F'); //1-ON , 0-OFF
    if (btn == 0)ser.write('6');
  }
}
void setup()
{
  // Debug console
  Serial.begin(9600);
  ser.begin(9600);

  //Led Indicator
  pinMode(led, OUTPUT);

  // You can also specify server:
  Blynk.begin(auth, ssid, pass, "prakitblog.com", 8181);
  Serial.println("ESP STARTED");

  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}
void loop()
{
  nows = millis();
  if (nows - before >= 7000UL) {
    if (Blynk.connected()) {
      ledON;
    }
    else {
      ledOFF;
      Blynk.connect();
    }
    before = nows;
  }
  Blynk.run();
}
