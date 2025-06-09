#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Si no funciona, probá con 0x3F

void setup() {
  lcd.init();          // Inicializa LCD
  lcd.backlight();     // Enciende luz de fondo
  lcd.setCursor(0, 0); // Fila 0, columna 0
  lcd.print("Hola Mundo");
}

void loop() {
  // Nada
}
