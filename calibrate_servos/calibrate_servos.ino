#include <ESP32Servo.h>  // Use ESP32Servo instead of Servo.h


Servo myServo;  // Create servo object

const int SERVO_PIN = 4;  // Change this if using another pin

void setup() {
    Serial.begin(115200);
    myServo.attach(SERVO_PIN);

    //Convert the center position to the range used by the servo motor
    //int centerServoangle = map(0, -60, 60, 0, 180);
    //myServo.write(centerServoangle); //Move the servo to the center position

    int centerServoAngle = 90;  // 90 degrees is typically the center for most servos
    myServo.write(centerServoAngle); // Move the servo to the center position
}

void loop() {
  // put your main code here, to run repeatedly:

}
