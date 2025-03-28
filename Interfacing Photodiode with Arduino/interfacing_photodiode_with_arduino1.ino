const int photodiodePin = A0;  // Photodiode connected to A0

void setup() {
    Serial.begin(9600);  // Start serial communication
}

void loop() {
    int sensorValue = analogRead(photodiodePin);  // Read analog value from photodiode
    Serial.print("Photodiode Value: ");
    Serial.println(sensorValue);  // Print value to serial monitor

    delay(500);  // Small delay for stability
}
