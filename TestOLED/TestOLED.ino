#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h> //OLED
#include <Arduino.h>
#include <I2CScanner.h>
#include <SPI.h>
#include <U8g2lib.h>
#include <Wire.h>  //I2C

#define bitmapWidth 128
#define bitmapHeight 32
#define I2CScanner 0x70 // #define ชื่อ ค่า
//I2C device found at address 0x3C (จอ) , 0x70 (i2c)


Adafruit_SSD1306 display0 = Adafruit_SSD1306(128, 32, &Wire);
Adafruit_SSD1306 display1 = Adafruit_SSD1306(128, 32, &Wire);


void TCA9548A(uint8_t bus) 
{
  Wire.beginTransmission(I2CScanner);  // ใช้เริ่มการส่งข้อมูลไปยังอุปกรณ์ TCA9548A address is I2CScanner 0x70
  Wire.write(1 << bus); //รับข้อมูลจากตัวส่ง
  Wire.endTransmission(); // ใช้จบการส่งข้อมูล
}
void displayoled0(){
  display0.begin(I2CScanner, 0x3C);
  display0.clearDisplay();
  display0.setCursor(0, 10);
  display0.setTextColor(1);
  display0.setTextSize(1);
  display0.print("park woo jin");

}
 
void displayoled1(){
 

  display1.clearDisplay();
  display1.setCursor(0, 10);
  display1.setTextColor(1);
  display1.setTextSize(1);
  display1.print("nsc");
  
  
}
void setup()
{
    Wire.begin(); //ใช้คำสั่งเริ่มต้นการใช้งาน I2C โดยใช้ค่าในพารามิเตอร์เป็นค่าเริ่มต้นทั้งหมด

  // Set multiplexer to channel 1 and initialize OLED-0 with I2C addr 0x3C
  TCA9548A(0);
  display0.begin(I2CScanner, 0x3C);
 
  // initialize OLED-1 with I2C addr 0x3C
  TCA9548A(1);
 display1.begin(I2CScanner, 0x3C);

}

void loop() {

  TCA9548A(0);
  displayoled0();
  display0.display();

  TCA9548A(1);
  displayoled1();
 display1.display();
}



