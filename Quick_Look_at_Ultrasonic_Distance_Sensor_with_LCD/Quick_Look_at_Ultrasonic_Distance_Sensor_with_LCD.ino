/*
Personal Annotations and Citations
All materials were purchased from Amazon.com from various vendors.
*/


/* Ultrasocic Sensor code source

chickenparmi. "Arduino Tutorial #6 - HC-SR04 Ultrasonic sensor."
   Online video. YouTube. YouTube, 15 Feb. 2013. Web. 8 May 2013.
   <https://www.youtube.com/watch?v=PG2VhpkPqoA>.
*/


/* LCD code source
ianbren. "[SOLVED] I2C LCD - Setup instructions for 16x2." Arduino
   Forum. SMF 1.1.18. Simple Machines. 23 Oct. 2012. Web.
   8 May 2013. <http://arduino.cc/forum/index.php?topic=128635.0>.
*/


//Codes were borrowed from online sources and modified. No infringement intended.


//Distance sensor
#define trigPin 12
#define echoPin 8

//Flashing LED on Arduino board
#define LEDPin 13

//LCD
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR  0x3F  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN   3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C     lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);


void setup ()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);  //The transmit pin of the ultrasonic sensor
  pinMode(echoPin, INPUT);   //The receive pin of the ultrasonic sensor
  pinMode(LEDPin, OUTPUT);   //The LED of the Arduino

  lcd.begin (20,4);  //Size of LCD
 
// Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();                // go home

}

void loop()
{
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance =(duration/2) / 29.1;

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance from object");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print("cm");
  if (distance >=15)
  {
    lcd.setCursor(0,4);
    lcd.print("Safe Zone :)");
    digitalWrite(LEDPin,HIGH);
      delay(500);
      digitalWrite(LEDPin,LOW);
      delay(500);
   
  }
    else
  {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(" STEP AWAY!!!");
      lcd.setCursor(0,1);
      lcd.print(" STEP AWAY!!!");
      lcd.setCursor(0,2);
      lcd.print(" STEP AWAY!!!");
      lcd.setCursor(0,3);
      lcd.print(" STEP AWAY!!!");
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      delay(50);
      digitalWrite(LEDPin,HIGH);
      delay(50);
      digitalWrite(LEDPin,LOW);
      //That really long repeat is to allow the LED pin on the Arduino
      //to blink. I didn't know how to do this easier. If you do,
      //feel free to change and let me know. Still prototyping personally.

  }

}

