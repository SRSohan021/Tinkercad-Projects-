#include <Keypad.h>
#include <LiquidCrystal.h>

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', '/'},
  {'4', '5', '6', '*'},
  {'7', '8', '9', '-'},
  {'C', '0', '=', '+'}
};
byte rowPins[ROWS] = {7,6,5,4};
byte colPins[COLS] = {3,2,1,0};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

String input = "";
char lastOperator;
float num1, num2;
bool newEntry = true;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Arduino Calc");
  delay(2000);
  lcd.clear();
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key >= '0' && key <= '9') {
      if (newEntry) {
        input = "";
        newEntry = false;
      }
      input += key;
      lcd.print(key);
    } else if (key == 'C') {
      input = "";
      lcd.clear();
    } else if (key == '=') {
      num2 = input.toFloat();
      float result = 0;
      switch (lastOperator) {
        case '+': result = num1 + num2; break;
        case '-': result = num1 - num2; break;
        case '*': result = num1 * num2; break;
        case '/': result = (num2 != 0) ? num1 / num2 : 0; break;
      }
      lcd.setCursor(0, 1);
      lcd.print("= ");
      lcd.print(result);
      newEntry = true;
    } else {
      num1 = input.toFloat();
      lastOperator = key;
      lcd.setCursor(0, 1);
      lcd.print(key);
      input = "";
    }
  }
}