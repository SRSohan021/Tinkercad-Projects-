#include <Servo.h>
#include <IRremote.h>

#define IR_PIN 5  // IR sensor connected to pin 5
#define SERVO_PIN 3 // Servo motor signal pin

Servo myServo;

void setup() {
    Serial.begin(9600); // Start Serial Monitor
    IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK); // Start IR receiver
    myServo.attach(SERVO_PIN);
    myServo.write(0); // Set initial position
}

void loop() {
    if (IrReceiver.decode()) {
        unsigned long value = IrReceiver.decodedIRData.decodedRawData;
        Serial.print("Received IR Code: ");
        Serial.println(value, HEX); // Print received IR code

        if (value == 0xEF10BF00) { // Button 1
            moveServo(45);
        } else if (value == 0xEE11BF00) { // Button 2
            moveServo(90);
        } else if (value == 0xED12BF00) { // Button 3
            moveServo(135);
        } else if (value == 0xEB14BF00) { // Button 4
            moveServo(180);
        } else {
            Serial.println("Unknown Button Pressed!");
        }

        IrReceiver.resume(); // Resume receiving IR signals
    }
}

void moveServo(int angle) {
    Serial.print("Moving Servo to: ");
    Serial.print(angle);
    Serial.println(" degrees");

    myServo.write(angle);
    delay(1000);
    myServo.write(0); // Return to initial position

    Serial.println("Servo returned to 0 degrees");
}
