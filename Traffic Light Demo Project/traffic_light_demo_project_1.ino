// Define pin connections
const int redLED = 13;
const int yellowLED = 12;
const int greenLED = 8;
const int buttonPin = 2;

// Variable to store button state
int buttonState = 0;

void setup() {
    // Set LED pins as output
    pinMode(redLED, OUTPUT);
    pinMode(yellowLED, OUTPUT);
    pinMode(greenLED, OUTPUT);
    
    // Set button pin as input
    pinMode(buttonPin, INPUT);
    
    // Start serial communication
    Serial.begin(9600);
}

void loop() {
    // Read the button state
    buttonState = digitalRead(buttonPin);

    // If button is pressed
    if (buttonState == HIGH) {
        Serial.println("Red light ON");
        digitalWrite(redLED, HIGH);
        delay(3000); // Red light delay
        digitalWrite(redLED, LOW);

        Serial.println("Yellow light ON");
        digitalWrite(yellowLED, HIGH);
        delay(1000); // Yellow light delay
        digitalWrite(yellowLED, LOW);

        Serial.println("Green light ON");
        digitalWrite(greenLED, HIGH);
        delay(3000); // Green light delay
        digitalWrite(greenLED, LOW);
    }
}
