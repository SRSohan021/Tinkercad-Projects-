#include <Keypad.h>

// Define keypad rows and columns
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // Connect to keypad row pins
byte colPins[COLS] = {5, 4, 3, 2}; // Connect to keypad column pins

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// Output pins
const int redLED = 10;
const int greenLED = 11;
const int buzzer = 12;

// Password setup
String correctPassword = "1234";  // Set correct password
String inputPassword = "";

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter 4-digit Password:");
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.print(key);

    if (key == '*') {  
      // Clear input if '*' is pressed
      inputPassword = "";
      Serial.println("\nInput Cleared");
    } 
    else if (key != '#' && inputPassword.length() < 4) {
      // Add key to input if less than 4 characters
      inputPassword += key;
    }

    // Check if 4 characters entered
    if (inputPassword.length() == 4) {
      if (inputPassword == correctPassword) {
        correctPasswordAction();
      } else {
        wrongPasswordAction();
      }
      inputPassword = ""; // Reset for next attempt
      Serial.println("\nEnter 4-digit Password:");
    }
  }
}

void correctPasswordAction() {
  Serial.println("\nAccess Granted");
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
  tone(buzzer, 1000, 200); // Short beep
  delay(1000);
  digitalWrite(greenLED, LOW);
}

void wrongPasswordAction() {
  Serial.println("\nAccess Denied");
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
  tone(buzzer, 500, 1000); // Long beep
  delay(1000);
  digitalWrite(redLED, LOW);
}
