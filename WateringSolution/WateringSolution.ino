/*


*/
const int analogInPinSensor1 = A0; 
const int analogInPinSensor2 = A1; 
const int outPinPump1 = 13; // Analog output pin that the LED is attached to
const int outPinPump2 = 12; // Analog output pin that the LED is attached to
//
int sensor1Value = 0;        // value read from the pot
int sensor2Value = 0;        // value read from the pot
//
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
  // set delay to wait for next reading
  delay(1000);
}