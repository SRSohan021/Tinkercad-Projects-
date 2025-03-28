// Define pins
const int ldrPin = A0;      // LDR sensor connected to analog pin A0
const int ledPin = 13;       // LED connected to digital pin 9

void setup() {
  Serial.begin(9600);       // Start serial communication at 9600 baud rate
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Read value from LDR sensor (0-1023)
  
  // Print the light intensity value to Serial Monitor
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Control LED brightness based on LDR value
  int ledBrightness = map(ldrValue, 0, 1023, 0, 255);  // Map to PWM range (0-255)
  analogWrite(ledPin, ledBrightness);

  delay(500); // Small delay to stabilize readings
}
