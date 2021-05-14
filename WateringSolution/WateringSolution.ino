/*


*/
const int analogInPinSensor1 = A0; 
const int outPinPump1 = 13; // Analog output pin that the LED is attached to
//
int sensor1Value = 0;        // value read from the pot
//
//
void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
//
  pinMode(outPinPump1, OUTPUT);
}

void loop() {
  // read the analog in value:
  sensor1Value = analogRead(analogInPinSensor1);
  // Sensor 1 ranges from 700 dry to 268 wet
  //debug
  Serial.print("S1: ");
  Serial.println(sensor1Value);
  // PUMP_1
  if (sensor1Value > 600) {
    digitalWrite(outPinPump1, LOW);
  }
  else if (sensor1Value < 400) {
    digitalWrite(outPinPump1, HIGH);
  }
  // set delay to wait for next reading
  delay(5000);
}
