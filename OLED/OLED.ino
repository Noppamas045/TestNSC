#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_SSD1306 display = Adafruit_SSD1306(128, 32, &Wire);

void setup() {
  display.begin(0x3C);
  display.clearDisplay();
  display.display();
  delay(2000);
} //บรรทัด 1-15 จำเป็นต้องมี

void loop() {
  display.clearDisplay(); //จำเป็นต้องมี

  display.setCursor(20, 20);
  display.setTextColor(1);
  display.setTextSize(1);
  display.println("MDT62"); /// 20-23 เขียนข้อความ

  display.drawLine(5, 8, 32, 32, 1);
  display.drawCircle(10, 10, 20, 1); //(x,y,z,e) x y แกน X Y , z รัศมี , 1 สีเส้น
  display.drawRect(32, 0, 20, 20, 1); //(-,-,X,Y,-)
  display.fillCircle(64, 8, 10, 1);
  display.fillRect(96, 0, 20, 10, 1); // 25 - 28 วาดรูป

  display.display(); //จำเป็นต้องมี
  delay(2000); //จำเป็นต้องมี
}
