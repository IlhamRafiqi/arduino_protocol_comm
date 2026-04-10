#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// Tambahkan spasi depan & belakang biar efek jalan dari kanan halus
String quote = "                HIDUP JOKOWI !!! HEY ANTEK ANTEK ASENG !!!   ";

int indexScroll = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);

  // Baris 0: QUOTE di tengah
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop() {
  lcd.setCursor(0, 1);

  // Ambil 16 karakter untuk ditampilkan
  String tampil = quote.substring(indexScroll, indexScroll + 16);
  lcd.print(tampil);

  indexScroll++;

  // Reset scroll
  if (indexScroll > quote.length() - 16) {
    indexScroll = 0;
  }

  delay(300);
}
