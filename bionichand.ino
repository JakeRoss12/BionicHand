// Give-A-Hand: Bionichand
// 11/29/2023
// Moves servo clockwise/counterclockwise in response to open/close hand

#include <Servo.h>
Servo myservo;
bool handPos = 0; // 0 = open, 1 = closed

void setup() {

myservo.attach(9);  // attaches the servo on pin 9 to the servo object
myservo.writeMicroseconds(0); // set servo rotation to 0

Serial.begin(9600);
//while (!Serial); // optionally wait for serial terminal to open

}
void loop() {

int sensorValue = analogRead(A1); // read the input from sensor

  Serial.print("Sensor reading: ");
  Serial.println(sensorValue); // print out the sensor value

  delay(50); // to avoid overloading the serial terminal

  if (sensorValue > 70) {
    handPos = !handPos;
    /* Serial.print("HandPos: ");
    Serial.println(handPos); 
    Demo was not done with this bit, but it should be ok*/
    if (handPos) {
      // open the hand
      myservo.writeMicroseconds(1000);  // CountereClockwise
      delay(1000); // spin for one second
      myservo.writeMicroseconds(0); // stop spinning
    }
    else {
      // close the hand
      myservo.writeMicroseconds(2000);  // Clockwise
      delay(1000); // spin for one second
      myservo.write(0); // stop spinning
    }
    delay(1000); // 1 second delay before accepting reading new values
  }

}