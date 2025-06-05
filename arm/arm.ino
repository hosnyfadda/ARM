#include <Servo.h>

// Create servo objects
Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;
Servo servo06;

void setup() {
  // Attach the servos to their respective pins
  servo01.attach(5);
  servo02.attach(6);
  servo03.attach(7);
  servo04.attach(8);
  servo05.attach(9);
  servo06.attach(10);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Move each servo to a specific position
  servo01.write(0);   // Move servo01 to 0 degrees
  delay(500);         // Wait 0.5 seconds
  servo02.write(45);  // Move servo02 to 45 degrees
  delay(500);         // Wait 0.5 seconds
  servo03.write(90);  // Move servo03 to 90 degrees
  delay(500);         // Wait 0.5 seconds
  servo04.write(135); // Move servo04 to 135 degrees
  delay(500);         // Wait 0.5 seconds
  servo05.write(180); // Move servo05 to 180 degrees
  delay(500);         // Wait 0.5 seconds
  servo06.write(90);  // Move servo06 to 90 degrees
  delay(500);         // Wait 0.5 seconds

  // Repeat the movement
  for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo01.write(pos);              // tell servo to go to position in variable 'pos'
    servo02.write(180 - pos);        // inverse movement
    servo03.write(pos);              // same direction as servo01
    servo04.write(180 - pos);        // inverse movement
    servo05.write(pos);              // same direction as servo01
    servo06.write(180 - pos);        // inverse movement
    delay(15);                       // waits 15ms for the servo to reach the position
  }

  delay(1000); // Wait 1 second before repeating the loop
}
