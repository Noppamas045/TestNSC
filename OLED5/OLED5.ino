// Display - https://pmdway.com/collections/oled-displays/products/0-49-64-x-32-white-graphic-oled-i2c
// Guide - https://pmdway.com/blogs/product-guides-for-arduino/tutorial-using-the-0-49-64-x-32-graphic-i2c-oled-display-with-arduino
// TCA9548A - https://pmdway.com/blogs/product-guides-for-arduino/using-the-tca9548a-1-to-8-i2c-multiplexer-breakout-with-arduino

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

void TCA9548A(uint8_t bus)
{
  Wire.beginTransmission(0x70);  // TCA9548A address is 0x70
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
}

U8G2_SSD1306_64X32_1F_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() 
{
  Wire.begin();
  u8g2.begin();
}

void loop()
{
  TCA9548A(0); // tell the TCA9548A we want to use I2C bus number zero (to talk to the OLED)

  // use the OLED as normal
  for (int a = 10; a >= 0; --a)
  {
    u8g2.clearBuffer();          // clear the internal memory
    u8g2.setFont(u8g2_font_inb24_mr );  // choose a suitable font
    u8g2.setCursor(0, 24);
    u8g2.print(a);
    a = a - 1;
    u8g2.sendBuffer();          // transfer internal memory to the display
    delay(1000);
  }
}