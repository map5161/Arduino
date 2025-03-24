#include <ESP32Servo.h>  // Use ESP32Servo instead of Servo.h

Servo baseServo;
Servo elbowServo;
Servo clawServo;

int basePin = 2;     // Base servo pin
int elbowPin = 16;   // Elbow servo pin
int clawPin = 15;    // Claw servo pin

void setup() {
  baseServo.attach(basePin);
  elbowServo.attach(elbowPin);
  clawServo.attach(clawPin);

  delay(1000);  // Allow servos to initialize

  clawServo.write(180);  // Close claw
  delay(1000);           // Wait for 1 second

  int baseAngle = 100;   // Set desired base angle (0-180)      180 is left limit         100 is middle      0 is right limit
  int elbowAngle = 90;  // Set desired elbow angle (0-180)     30 is backward limit      105 is middle      180 is forward limit

  baseServo.write(baseAngle);   // Move base to set position
  delay(500);  // Give time for movement

  elbowServo.write(elbowAngle); // Move elbow to set position
  delay(500);  // Give time for movement

  //clawServo.write(130);    // Open claw
}

void loop() {
  clawServo.write(80);    // Open claw
  delay(1000);           // Wait for 1 second
  
  clawServo.write(180);  // Close claw
  delay(1000);           // Wait for 1 second
}


