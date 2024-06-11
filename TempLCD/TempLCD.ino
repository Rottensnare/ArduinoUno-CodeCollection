#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
constexpr int tempPin = A0;
constexpr float baselineTemp = 18.0;
constexpr unsigned long del = 2000;

float getTemp(){
  int sensorVal = analogRead(tempPin);
  //Serial.print("Sensor Value: ");
  //Serial.print(sensorVal);

  float voltage = (sensorVal / 1024.0) * 5.0;
  //Serial.print(", Voltage: ");
  //Serial.print(voltage);

  //Serial.print(", Temperature C: ");
  float temperature = (voltage - 0.5) * 100;
  //Serial.println(temperature);
  return temperature;
}

void setup() {
  //Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(tempPin, INPUT);
  lcd.print("Lampotila:");
  lcd.setCursor(0,1);
  lcd.print(getTemp());
  lcd.setCursor(0,0);
}

void FetchAndPrintTemp(){
  lcd.clear();
  lcd.print("Lampotila:");
  lcd.setCursor(0,1);
  lcd.print(getTemp());
}

void loop() {
  delay(del);
  FetchAndPrintTemp();
}
