#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  
  int analogInput = 0;
float vout = 0.0;
float vin = 0.0;
float R1 = 100000.0; // insert exact resistance value R1 (100K)
float R2 = 10000.0; // enter exact value of resistance R2 (10K)

int value = 0;

void setup(){
   pinMode(analogInput, INPUT);
   lcd.begin(16, 2);
   lcd.print("VOLTMETRO DC");
   Serial.begin(9600);
}
void loop(){
   value = analogRead(analogInput);
   
   vout = (value * 5.0) / 1024.0; 
    // insert the output in volts between 5.0V and GND of your Arduino instead of 5.0V
   
   vin = vout / (R2/(R1+R2)); 
   if (vin<0.09) {
   vin=0.0;
} 
lcd.setCursor(0, 1);
lcd.print("INPUT V= ");
lcd.print(vin);
delay(500);
}