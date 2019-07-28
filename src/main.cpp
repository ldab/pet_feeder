/******************************************************************************
ESP8266 based Pet Feeder
Leonardo Bispo
July - 2019
https://github.com/ldab/Pet-Feeder
Distributed as-is; no warranty is given.
******************************************************************************/
#include "Arduino.h"

/* Comment this out to disable prints and save space */
//#define BLYNK_DEBUG
#define BLYNK_PRINT Serial
#define BLYNK_NO_BUILTIN
#define BLYNK_NO_FLOAT

// Enable Debug interface and serial prints over UART1
#define DEGUB_ESP

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TimeLib.h>
#include <WidgetRTC.h>
#include <Servo.h>

//OTA stuff
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

#ifdef DEGUB_ESP
  #define DBG(x) Serial.println(x)
#else 
  #define DBG(...)
#endif

//Servo attached to GPIO2 -> D4
//#define SERVO_PIN   2
#define SERVO_PIN   5     // D1 -> GPIO5
#define SERVO_CLOSE 90
#define SERVO_OPEN  18

int SERVO_SPEED = 50;

// WiFi and Blynk App credentials;
char ssid[] = "";
char pass[] = "";
char auth[] = "";

time_t  foodtime = -1;
bool    s_feed   = false;

uint8_t servoTimer;
uint8_t myPos = SERVO_CLOSE;

WidgetRTC  rtc;
Servo      myservo;                        // create servo object to control a servo
BlynkTimer timer;

void openServo();
void closeServo();


void feed_now()
{
  DBG( "Done feeding, closing" );

  myservo.write( SERVO_CLOSE );

  Blynk.notify("Done feeding");
}

BLYNK_CONNECTED()
{
  // Syncronize RTC when connects
  rtc.begin();
  Blynk.syncVirtual(V1);
}

BLYNK_WRITE(V1)
{
  // Simple time input, returns the time for a day in sec -> max 86400
  foodtime = param[0].asLong();

  DBG("time from app:" + String(foodtime));

  // When no input App returns 0, and -1 reset time input;
  s_feed = (foodtime > 0) ? true : false;
}

void setup()
{
  #ifdef DEGUB_ESP
    Serial.begin(19200);
  #endif

  myservo.attach( SERVO_PIN );
  //myservo.write( SERVO_CLOSE );

  Blynk.begin(auth, ssid, pass);
  rtc.begin();

  Serial.print ("SDK:");
  DBG (ESP.getSdkVersion());
  Serial.print ("Flash Chip size:");
  DBG (ESP.getFlashChipSize());
  Serial.print ("Sketch size:");
  DBG (ESP.getSketchSize());
  Serial.print ("Free sketch space:");
  DBG (ESP.getFreeSketchSpace());
  Serial.print ("Free Heap:");
  DBG (ESP.getFreeHeap());
  Serial.print ("Reset Reason:");
  DBG (ESP.getResetReason());

  ArduinoOTA.setHostname("myesp8266");
  ArduinoOTA.begin();
}

void loop()
{
  ArduinoOTA.handle();
  timer.run();
  Blynk.run();

  // Make sure time is sync before comparing
  time_t now_s = ( timeStatus() != 2 ) ? -1 : hour() * 3600 + minute() * 60 + second();

  if( now_s > foodtime && s_feed )
  {
    // Reset time input on the App
    char tz[] = "Europe/Copenhagen";
    Blynk.virtualWrite(V1, -1, -1, tz);

    // Reset flags
    foodtime = -1;
    s_feed = false;

    DBG("Feeding, open servo");

    servoTimer = timer.setInterval(SERVO_SPEED, openServo);
  }
}   //end loop

void openServo()
{
  myservo.write( myPos );

  myPos--;

  if( myPos <= SERVO_OPEN )
  {
    timer.deleteTimer(servoTimer);

    delay( 500 );

    servoTimer = timer.setInterval(SERVO_SPEED, closeServo);
  }
}

void closeServo()
{
  myservo.write( myPos );

  myPos++;

  // delete timer when reach position
  if( myPos >= SERVO_CLOSE )  timer.deleteTimer(servoTimer);
}
