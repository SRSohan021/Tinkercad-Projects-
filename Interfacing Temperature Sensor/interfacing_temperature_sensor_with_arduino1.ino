// Define LM35 sensor pin
const int sensorPin = A0;  

void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  int sensorValue = analogRead(sensorPin); // Read analog value from sensor

  // Convert analog value to voltage
  float voltage = sensorValue * (5.0 / 1023.0);

  // Convert voltage to temperature in Celsius (10mV per degree Celsius for LM35)
  float temperatureC = voltage * 100;

  // Convert temperature to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32;

  // Display results
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C  |  ");
  Serial.print(temperatureF);
  Serial.println(" °F");

  delay(1000); // Wait for 1 second before next reading
}
