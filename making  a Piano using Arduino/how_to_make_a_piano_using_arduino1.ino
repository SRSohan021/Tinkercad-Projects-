// Define the pins for the buttons and buzzer
const int buzzerPin = 13;
const int buttonPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int numButtons = 8;

// Define the musical notes (frequencies in Hz) for each button
const int notes[] = {
  262,  // C4 (Do)
  294,  // D4 (Re)
  330,  // E4 (Mi)
  349,  // F4 (Fa)
  392,  // G4 (Sol)
  440,  // A4 (La)
  494,  // B4 (Si)
  523   // C5 (Do)
};

// Variable to track if any button is currently pressed
bool buttonPressed = false;

void setup() {
  // Initialize the buzzer pin as output
  pinMode(buzzerPin, OUTPUT);
  
  // Initialize all button pins as INPUT_PULLUP
  for (int i = 0; i < numButtons; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }
}

void loop() {
  buttonPressed = false; // Reset the button state
  
  // Check each button
  for (int i = 0; i < numButtons; i++) {
    // If button is pressed (LOW because we're using INPUT_PULLUP)
    if (digitalRead(buttonPins[i]) == LOW) {
      // Play the corresponding note
      tone(buzzerPin, notes[i]);
      buttonPressed = true;
      break; // Exit the loop when a button is found pressed
    }
  }
  
  // If no buttons are pressed, stop the sound
  if (!buttonPressed) {
    noTone(buzzerPin);
  }
  
  // Small delay to prevent flickering
  delay(10);
}