#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

int sensorPin = A0;  
int Value = 0; 
float Voltage = 0.00;

void setup() {
  Serial.begin(9600);
  lcd_1.begin(16, 2);
  //lcd_1.print("Voltage");
}

void loop() {
  Value = analogRead(sensorPin);
  Serial.print("digital value = ");
  Serial.print(Value);
  lcd_1.setCursor(0, 0);
  lcd_1.print("DC:     "); // Clearing remaining characters
  lcd_1.setCursor(3, 0);
  lcd_1.print(Value);
  /*****convert digital value to analog voltage*****/
  Voltage = (Value * 5.00) / 1023.00;
  Serial.print("  analog voltage = ");
  Serial.println(Voltage);
  lcd_1.setCursor(0, 1);
  lcd_1.print("AC: ");
  lcd_1.setCursor(3, 1);
  lcd_1.print(Voltage);
}
