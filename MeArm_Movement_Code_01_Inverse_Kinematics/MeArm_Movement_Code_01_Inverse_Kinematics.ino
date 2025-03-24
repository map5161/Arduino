/* MeArm IK test - York Hackspace May 2014
 * Test applying Nick Moriarty's Inverse Kinematics solver
 * to MeArm Robotics Classic MeArm robot arm, to walk a specified path.
 *
 * Pins:
 * Arduino    Base   Shoulder  Elbow    Claw
 *    GND    Brown     Brown   Brown     Brown
 *     5V      Red       Red     Red       Red
 *     11    Yellow
 *     10             Yellow
 *      9                     Yellow
 *      6                               Yellow
 */
#include <MeArm.h>
#include <ESP32Servo.h>  // Use ESP32Servo instead of Servo.h

int basePin = 2;
int shoulderPin = 4; // Left
int elbowPin = 16; // Right
int clawPin = 15;

MeArm arm;

void setup() {
  arm.begin(basePin, shoulderPin, elbowPin, clawPin);

    // Initialize arm to a known position (e.g., 0, 100, 50)
  arm.moveToXYZ(0, 100, 50);  // Starting position
  delay(1000);  // Delay to ensure arm reaches the start position before moving further
}

// Function to gradually move between two points
void smoothMove(float xStart, float yStart, float zStart, float xEnd, float yEnd, float zEnd, int steps, int delayTime) {
  float stepX = (xEnd - xStart) / steps;
  float stepY = (yEnd - yStart) / steps;
  float stepZ = (zEnd - zStart) / steps;

  for (int i = 0; i <= steps; i++) {
    arm.moveToXYZ(xStart + (stepX * i), yStart + (stepY * i), zStart + (stepZ * i));
    delay(delayTime);
  }
}

void loop() {
  //Clap - so it's obvious we're at this part of the routine
  arm.openClaw();
  arm.closeClaw();
  arm.openClaw();
  arm.closeClaw();
  arm.openClaw();
  delay(500);
  
  // Move gradually in 20 steps with 30ms delay per step
  smoothMove(0, 100, 50, -80, 100, 140, 20, 50);  
  arm.closeClaw();
  delay(500);
  
  smoothMove(-80, 100, 140, 70, 200, 10, 25, 40);  
  arm.openClaw();
  delay(500);
  
  smoothMove(70, 200, 10, 0, 100, 50, 20, 30);  
  delay(2000);
}