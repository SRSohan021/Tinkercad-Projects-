// Pin Definitions
const int tempSensorPin = A0; // Temperature Sensor connected to A0
const int gasSensorPin = A1;  // Gas Sensor connected to A1
const int buzzerPin = 8;      // Buzzer connected to Pin 8
const int ledPin = 13;        // LED connected to Pin 13

// Initial Thresholds
const float initialTempC = 25.0; // Temperature threshold in degree Celsius
const int initialGasValue = 85;  // Gas sensor threshold value

void setup() {
  // Initialize Serial Communication
  Serial.begin(9600);

  // Set pin modes
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Turn off buzzer and LED initially
  digitalWrite(buzzerPin, LOW);
  digitalWrite(ledPin, LOW);
}

void loop() {
  // Read Temperature Sensor (analog value)
  int tempSensorValue = analogRead(tempSensorPin);
  // Convert to voltage (assuming 5V and 10-bit ADC)
  float voltage = tempSensorValue * (5.0 / 1023.0);
  // Convert voltage to temperature (for LM35 or similar sensor: 10mV/°C)
  float temperatureC = voltage * 100.0;

  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  // Read Gas Sensor Value
  int gasValue = analogRead(gasSensorPin);
  Serial.print("Gas Sensor Value: ");
  Serial.println(gasValue);

  // Check temperature condition
  if (temperatureC > initialTempC) {
    digitalWrite(ledPin, HIGH); // Turn LED ON
  } else {
    digitalWrite(ledPin, LOW);  // Turn LED OFF
  }

  // Check gas sensor condition
  if (gasValue > initialGasValue) {
    digitalWrite(buzzerPin, HIGH); // Turn Buzzer ON
  } else {
    digitalWrite(buzzerPin, LOW);  // Turn Buzzer OFF
  }

  delay(500); // Small delay
}
