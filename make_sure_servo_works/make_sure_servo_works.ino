#include <ESP32Servo.h>  // Use ESP32Servo instead of Servo.h


Servo myServo;  // Create servo object

#define SERVO_PIN 4  // Change this if using another pin

void setup() {
    Serial.begin(115200);
    myServo.attach(SERVO_PIN);
    Serial.println("Servo Calibration Started");
}

void loop() {
    for (int pos = 0; pos <= 180; pos += 10) {  // Sweep from 0 to 180 degrees
        myServo.write(pos);
        Serial.print("Angle: ");
        Serial.println(pos);
        delay(500);
    }
    
    delay(1000);

    for (int pos = 180; pos >= 0; pos -= 10) {  // Sweep from 180 to 0 degrees
        myServo.write(pos);
        Serial.print("Angle: ");
        Serial.println(pos);
        delay(500);
    }
    
    delay(1000);
}
