#include <IRremote.h>

// Pin definitions
const int blueLEDPin = 2;
const int orangeLEDPin = 3;
const int greenLEDPin = 4;
const int IR_RECEIVE_PIN = 12;

void setup() {
  Serial.begin(9600);  // Initialize serial monitor for debugging
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);  // Initialize IR receiver
  
  // Set LED pins as output
  pinMode(blueLEDPin, OUTPUT);
  pinMode(orangeLEDPin, OUTPUT);
  pinMode(greenLEDPin, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {  // Check if an IR signal is received
    long int command = IrReceiver.decodedIRData.command;  // Get the command value from the IR signal
    Serial.print("Received command: ");
    Serial.println(command, HEX);  // Print the command value for debugging

    // Use switch-case to control the LEDs based on the IR command
    switch (command) {
      case 0x10:  // Button 1 ON (Blue LED)
        digitalWrite(blueLEDPin, HIGH);
        break;
      case 0x11:  // Button 2 OFF (Blue LED)
        digitalWrite(blueLEDPin, LOW);
        break;
      case 0x12:  // Button 3 ON (Orange LED)
        digitalWrite(orangeLEDPin, HIGH);
        break;
      case 0x14:  // Button 4 OFF (Orange LED)
        digitalWrite(orangeLEDPin, LOW);
        break;
      case 0x15:  // Button 5 ON (Green LED)
        digitalWrite(greenLEDPin, HIGH);
        break;
      case 0x16:  // Button 6 OFF (Green LED)
        digitalWrite(greenLEDPin, LOW);
        break;
      default:
        // If the command is not recognized, do nothing
        break;
    }

    IrReceiver.resume();  // Ready for the next IR signal
  }
}
