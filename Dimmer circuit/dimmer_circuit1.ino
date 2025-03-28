const int bulbPin = 9;    // Light bulb connected to D9 (PWM pin)
const int potPin = A0;    // Potentiometer wiper connected to A0

void setup() {
    pinMode(bulbPin, OUTPUT);
    pinMode(potPin, INPUT);
    Serial.begin(9600);  // Start serial communication
}

void loop() {
    int potValue = analogRead(potPin);  // Read potentiometer value (0-1023)
    int brightness = map(potValue, 0, 1023, 0, 255);  // Scale to PWM range (0-255)

    analogWrite(bulbPin, brightness);  // Adjust bulb brightness
    Serial.print("Brightness Level: ");
    Serial.println(brightness);  // Print brightness value

    delay(100);  // Small delay for stability
}
