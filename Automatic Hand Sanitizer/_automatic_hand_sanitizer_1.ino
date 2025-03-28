#include <Servo.h>

// Define sensor pins
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

// Create servo object
Servo myServo;

// Define distance threshold (in cm)
const int distanceThreshold = 30;  // Adjust if needed

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    myServo.attach(servoPin);
    myServo.write(0);  // Start position (closed)
    Serial.begin(9600);  // For debugging
}

void loop() {
    long duration;
    int distance;

    // Send ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read echo time
    duration = pulseIn(echoPin, HIGH);

    // Convert time to distance (in cm)
    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Check if hand is detected
    if (distance > 0 && distance <= distanceThreshold) {
        Serial.println("Hand detected! Dispensing sanitizer...");
        myServo.write(90);  // Move servo to 90° to press the bottle
        delay(3000);        // Hold position for 3 seconds
        myServo.write(0);   // Reset to 0° (original position)
        delay(2000);        // Delay to prevent multiple triggers
    }

    delay(100);  // Small delay to avoid continuous triggering
}
