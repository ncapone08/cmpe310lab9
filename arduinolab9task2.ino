#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int voltageV1 = A0;
const int voltageV2 = A1;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(voltageV1, INPUT);
  pinMode(voltageV2, INPUT);
}
void loop() {
  int voltageOut1 = analogRead(voltageV1);
  int voltageOut2 = analogRead(voltageV2);
  float Vcalc = (5.0/1023)*voltageOut1 - (5.0/1023)*voltageOut2;
  
  lcd.setCursor(0, 0);
  lcd.print("Volts: ");
  lcd.print(Vcalc);
  delay(1000);
}

