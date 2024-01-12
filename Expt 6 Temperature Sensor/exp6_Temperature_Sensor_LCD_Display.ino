#include <LiquidCrystal.h>
int sensorpin = A0;
int temperature = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  pinMode(sensorpin, INPUT);
  lcd.begin(16, 2);
  lcd.print("Temperature: ");
}
void loop() {
  temperature = analogRead(sensorpin);
  temperature = temperature * 0.48828125;
  lcd.setCursor(0, 1);
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C");
}