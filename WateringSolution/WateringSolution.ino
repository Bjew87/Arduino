/*

  Analog input, analog output, serial output

  Reads an analog input pin, maps the result to a range from 0 to 255 and uses

  the result to set the pulse width modulation (PWM) of an output pin.

  Also prints the results to the Serial Monitor.

  The circuit:

  - potentiometer connected to analog pin 0.

    Center pin of the potentiometer goes to the analog pin.

    side pins of the potentiometer go to +5V and ground

  - LED connected from digital pin 9 to ground

  created 29 Dec. 2008

  modified 9 Apr 2012

  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/AnalogInOutSerial

*/
// include the library code:
#include <LiquidCrystal.h>
// These constants won't change. They're used to give names to the pins used:

const int analogInPinSensor1 = A0;
const int analogInPinSensor2 = A1;
const int outPinPump1 = 13; // Analog output pin that the LED is attached to
const int outPinPump2 = 12; // Analog output pin that the LED is attached to

int sensor1Value = 0;        // value read from the pot
int sensor2Value = 0;        // value read from the pot


//const int rs = 8, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
//
  pinMode(outPinPump1, OUTPUT);
  pinMode(outPinPump2, OUTPUT);
  //  // set up the LCD's number of columns and rows:
  //  lcd.begin(16, 2);
}

void loop() {
  // read the analog in value:
  sensor1Value = analogRead(analogInPinSensor1);
  // Sensor 1 ranges from 700 dry to 268 wet
  
  sensor2Value = analogRead(analogInPinSensor2);

  //debug
  Serial.print("S1: ");
  Serial.println(sensor1Value);
  Serial.print("S2: ");
  Serial.println(sensor2Value);
  Serial.println(" ");
  // PUMP_1
  if (sensor1Value > 600) {
    digitalWrite(outPinPump1, LOW);
  }
  else if (sensor1Value < 400) {
    digitalWrite(outPinPump1, HIGH);
  }
  // PUMP_2
  if (sensor2Value > 600) {
    digitalWrite(outPinPump2, LOW);
  }
  else if (sensor2Value < 400) {
    digitalWrite(outPinPump2, HIGH);
  }

  // map it to the range of the analog out:
  // print the results to the Serial Monitor:
  // Print a message to the LCD.
  //  lcd.clear();
  //  lcd.print("S1=");
  //  lcd.print(sensor1Value);
  //  // write pump1 status
  //  lcd.setCursor(7, 0);
  //  if (digitalRead(analogOutPin) == 1) {
  //    lcd.print("P1=OFF");
  //  } else {
  //    lcd.print("P1=ON");
  //  }
  delay(1000);
}