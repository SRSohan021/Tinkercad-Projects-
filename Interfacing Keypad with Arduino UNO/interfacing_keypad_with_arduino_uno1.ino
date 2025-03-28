#include <Keypad.h>

// Define the Keypad size (4x4)
const byte ROW_NUM    = 4; // Four rows
const byte COLUMN_NUM = 4; // Four columns

// Define the Arduino pins connected to the rows and columns
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pin_rows[ROW_NUM] = {11,10,9,8}; // Rows connected to pins 8, 9, 10, and 11
byte pin_column[COLUMN_NUM] = {7,6,5,4}; // Columns connected to pins 4, 5, 6, and 7

// Create the keypad object
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
}

void loop() {
  char key = keypad.getKey(); // Read the pressed key

  if (key) {
    Serial.println(key); // Print the pressed key to the serial monitor
  }
}
