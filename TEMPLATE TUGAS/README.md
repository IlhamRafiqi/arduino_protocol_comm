# LAPORAN PRAKTIKUM

## SCROLLING TEXT PADA LCD 16x2 BERBASIS I2C MENGGUNAKAN ARDUINO

---

## 1. PENDAHULUAN

### 1.1 Latar Belakang

Perkembangan teknologi mikrokontroler, khususnya Arduino, memungkinkan pembuatan berbagai sistem tampilan informasi yang sederhana namun efektif. Salah satu perangkat output yang sering digunakan adalah LCD (Liquid Crystal Display) 16x2 yang dapat menampilkan karakter teks.

Dengan memanfaatkan modul I2C, penggunaan pin pada Arduino menjadi lebih efisien karena hanya membutuhkan dua jalur komunikasi, yaitu SDA dan SCL. Selain itu, tampilan teks dapat dikembangkan menjadi lebih interaktif, salah satunya dengan membuat efek **scrolling text** atau teks berjalan.

Oleh karena itu, pada praktikum ini dibuat sebuah sistem yang mampu menampilkan teks statis dan dinamis pada LCD 16x2 berbasis I2C.

---

### 1.2 Rumusan Masalah

Adapun rumusan masalah dalam praktikum ini adalah:

1. Bagaimana cara menampilkan teks pada LCD 16x2 menggunakan Arduino?
2. Bagaimana cara membuat teks statis pada baris pertama?
3. Bagaimana cara membuat teks berjalan (scrolling) pada baris kedua?

---

### 1.3 Tujuan

Tujuan dari praktikum ini adalah:

1. Memahami penggunaan LCD 16x2 berbasis I2C
2. Mampu menampilkan teks statis pada LCD
3. Mampu membuat efek scrolling text pada LCD

---

## 2. DASAR TEORI

LCD 16x2 merupakan perangkat output yang digunakan untuk menampilkan karakter teks dengan kapasitas 16 kolom dan 2 baris. Pada umumnya, LCD memerlukan banyak pin untuk komunikasi, namun dengan modul I2C, komunikasi dapat dilakukan hanya dengan dua pin, yaitu SDA (Serial Data) dan SCL (Serial Clock).

Arduino sebagai mikrokontroler digunakan untuk mengontrol tampilan pada LCD. Dalam implementasinya, digunakan library `Adafruit_LiquidCrystal` untuk mempermudah proses pemrograman.

Efek scrolling text dibuat dengan cara menggeser posisi karakter menggunakan teknik pengambilan substring dari sebuah string secara bertahap.

---

## 3. ALAT DAN BAHAN

Adapun alat dan bahan yang digunakan dalam praktikum ini adalah:

* Arduino Uno
* LCD 16x2 dengan modul I2C
* Kabel jumper
* Komputer/Laptop dengan Arduino IDE

---

## 4. PERANCANGAN SISTEM

### 4.1 Rangkaian

Koneksi antara LCD I2C dan Arduino adalah sebagai berikut:

* VCC → 5V
* GND → GND
* SDA → A4
* SCL → A5

---

### 4.2 Spesifikasi Sistem

* Baris pertama menampilkan teks **"QUOTE"** secara statis di tengah
* Baris kedua menampilkan teks berjalan dari kanan ke kiri
* Teks berjalan ditampilkan secara kontinu (looping)

---

## 5. IMPLEMENTASI PROGRAM

Berikut adalah program yang digunakan:

```cpp
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

String quote = "                HIDUP JOKOWI !!! HEY ANTEK ANTEK ASENG !!!   ";

int indexScroll = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);

  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop() {
  lcd.setCursor(0, 1);

  String tampil = quote.substring(indexScroll, indexScroll + 16);
  lcd.print(tampil);

  indexScroll++;

  if (indexScroll > quote.length() - 16) {
    indexScroll = 0;
  }

  delay(300);
}
```

---

## 6. HASIL DAN PEMBAHASAN

Hasil dari program menunjukkan bahwa:

* Teks **"QUOTE"** berhasil ditampilkan secara statis di tengah baris pertama
* Teks pada baris kedua berhasil ditampilkan secara berjalan dari kanan ke kiri
* Efek scrolling terlihat halus karena menggunakan metode substring

Namun, terdapat beberapa kendala yang ditemukan, seperti kesalahan pada library dan perbedaan alamat I2C. Kendala tersebut dapat diatasi dengan menggunakan library yang sesuai dan melakukan scanning alamat I2C.

---

## 7. KESIMPULAN

Berdasarkan hasil praktikum, dapat disimpulkan bahwa:

1. LCD 16x2 berbasis I2C dapat digunakan untuk menampilkan teks dengan efisien
2. Teks statis dapat ditampilkan dengan pengaturan posisi kursor
3. Efek scrolling text dapat dibuat dengan memanfaatkan manipulasi string

---

## 8. SARAN

Adapun saran untuk pengembangan lebih lanjut:

* Menambahkan lebih dari satu teks (multi-quote)
* Mengatur kecepatan scrolling agar lebih variatif
* Menambahkan tombol input untuk mengganti teks secara manual

---
