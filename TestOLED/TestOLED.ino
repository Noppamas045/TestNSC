#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#//include <Adafruit_AM2320.h>
#include <Arduino.h>
#include <I2CScanner.h>
#include <SPI.h>
#include <U8g2lib.h>
#include <Wire.h>

#define bitmapWidth 128
#define bitmapHeight 32
#define I2CScanner 0x70 // #define ชื่อ ค่า
//I2C device found at address 0x3C , 0x70 
//#define OLED 0x3C 
//#define OLED_RESET 1

Adafruit_SSD1306 display0 = Adafruit_SSD1306(128, 32, &Wire);
Adafruit_SSD1306 display1 = Adafruit_SSD1306(128, 32, &Wire);
Adafruit_SSD1306 display2 = Adafruit_SSD1306(128, 32, &Wire);
Adafruit_SSD1306 display3 = Adafruit_SSD1306(128, 32, &Wire);



// Create an object for each OLED display
// Adafruit_SSD1306 display1(OLED_RESET);
// Adafruit_SSD1306 display2(OLED_RESET);

void TCA9548A(uint8_t bus) 
{
  Wire.beginTransmission(I2CScanner);  // ใช้เริ่มการส่งข้อมูลไปยังอุปกรณ์ TCA9548A address is I2CScanner 0x70
  Wire.write(1 << bus); //รับข้อมูลจากตัวส่ง
  Wire.endTransmission(); // ใช้จบการส่งข้อมูล
}
void displayTemp(){
 
  //Clear the display
  display0.clearDisplay();
  display0.setCursor(0, 10);
  display0.setTextColor(1);
  display0.setTextSize(1);
  display0.print("P1");

}
 
void displayHumid(){
 
  // Clear the display
  display1.clearDisplay();
  display1.setCursor(0, 10);
  display1.setTextColor(1);
  display1.setTextSize(1);
  display1.print("nsc");
  
  
}
void setup()
{
    Wire.begin(); //ใช้คำสั่งเริ่มต้นการใช้งาน I2C โดยใช้ค่าในพารามิเตอร์เป็นค่าเริ่มต้นทั้งหมด
 // Initialize Temp & Humid Sensor
  
  // Set multiplexer to channel 1 and initialize OLED-0 with I2C addr 0x3C
  TCA9548A(0);
 display1.begin(I2CScanner, 0x3C);
 
  // initialize OLED-1 with I2C addr 0x3C
  TCA9548A(1);
 display0.begin(I2CScanner, 0x3C);

}

void loop() {

  TCA9548A(0);
  display0.display();

  TCA9548A(1);
 display1.display();
}



