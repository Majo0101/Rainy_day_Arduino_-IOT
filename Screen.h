#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

const unsigned char logoBM[] PROGMEM = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,
  0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,
  0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,
  0x00,0x60,0x03,0xF0,0x38,0x03,0x80,0x07,0xC0,0x7C,0x07,0xF0,0x1F,0xE0,0x06,0x00,
  0x00,0x60,0x03,0xF8,0x3C,0x07,0x80,0x1E,0xE1,0xEF,0x06,0x3C,0x18,0x00,0x06,0x00,
  0x00,0x60,0x03,0x0C,0x3C,0x07,0x80,0x38,0x03,0x83,0x86,0x0C,0x18,0x00,0x06,0x00,
  0x00,0x60,0x03,0x0C,0x3C,0x05,0x80,0x30,0x03,0x01,0x86,0x06,0x18,0x00,0x06,0x00,
  0x00,0x60,0x03,0x0C,0x36,0x0D,0x80,0x60,0x06,0x01,0x86,0x06,0x18,0x00,0x06,0x00,
  0x00,0x60,0x03,0x0C,0x36,0x0D,0x80,0x60,0x06,0x01,0xC6,0x07,0x18,0x00,0x06,0x00,
  0x00,0x60,0x03,0xF8,0x33,0x19,0x80,0x60,0x06,0x01,0xC6,0x03,0x18,0x00,0x06,0x00,
  0x00,0x60,0x03,0xF8,0x33,0x19,0x80,0x60,0x06,0x01,0xC6,0x07,0x1F,0xC0,0x06,0x00,
  0x00,0x60,0x03,0x0C,0x33,0x31,0x80,0x60,0x06,0x01,0x86,0x06,0x18,0x00,0x06,0x00,
  0x00,0x60,0x03,0x06,0x31,0xB1,0x80,0x60,0x06,0x01,0x86,0x06,0x18,0x00,0x06,0x00,
  0x00,0x60,0x03,0x06,0x31,0xB1,0x80,0x30,0x07,0x01,0x86,0x06,0x18,0x00,0x06,0x00,
  0x00,0x60,0x03,0x06,0x31,0xE1,0x80,0x38,0x03,0x83,0x06,0x0C,0x18,0x00,0x06,0x00,
  0x00,0x60,0x03,0xFC,0x30,0xE1,0x80,0x1E,0xE1,0xEF,0x06,0x38,0x18,0x00,0x06,0x00,
  0x00,0x60,0x03,0xF8,0x30,0xC1,0x80,0x0F,0xC0,0xFC,0x07,0xE0,0x1F,0xE0,0x06,0x00,
  0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,
  0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,
  0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const unsigned char signalBase[] PROGMEM = {
  0xFE
};

const unsigned char signalOne[] PROGMEM = {
  0xFF,0x80,
  0xFF,0x80
};

const unsigned char signalTwo[] PROGMEM = {
  0xFF,0xE0,
  0xFF,0xE0
};

const unsigned char signalThree[] PROGMEM = {
  0xFF,0xF8,
  0xFF,0xF8
};

const unsigned char signalFour[] PROGMEM = {
  0xFF,0xFE,
  0xFF,0xFE
};

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


void setUpOled(){
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.drawBitmap(0, 0, logoBM, 128, 32, WHITE);
  display.display();

  delay(3000);
}

void printScreen(int numOfView, String temp, String hum, String index, bool connection, String timeNow){
  switch(numOfView){
    case 1:
      display.clearDisplay();
      display.setTextSize(3);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      display.print(temp);
      display.println(char(247));
      display.setTextSize(1);
      display.print("TEPLOTA");
      display.drawBitmap(120, 20, signalBase, 7, 1, WHITE);
      display.drawBitmap(118, 15, signalOne, 9, 2, WHITE);
      display.drawBitmap(116, 10, signalTwo, 11, 2, WHITE);
      display.drawBitmap(114, 5, signalThree, 13, 2, WHITE);
      display.drawBitmap(112, 0, signalFour, 15, 2, WHITE);
      if(connection){
        display.setCursor(85, 24);
        display.print("WIFI OK");
      }else{
        display.setCursor(85, 24);
        display.print("NO WIFI");
      }
      display.display();
      break;
    case 2:
      display.clearDisplay();
      display.setTextSize(3);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      display.print(hum);
      display.println("%");
      display.setTextSize(1);
      display.print("VLHKOST");
      display.drawBitmap(120, 20, signalBase, 7, 1, WHITE);
      display.drawBitmap(118, 15, signalOne, 9, 2, WHITE);
      display.drawBitmap(116, 10, signalTwo, 11, 2, WHITE);
      display.drawBitmap(114, 5, signalThree, 13, 2, WHITE);
      display.drawBitmap(112, 0, signalFour, 15, 2, WHITE);
      if(connection){
        display.setCursor(85, 24);
        display.print("WIFI OK");
      }else{
        display.setCursor(85, 24);
        display.print("NO WIFI");
      }
      display.display();
      break;
    case 3:
      display.clearDisplay();
      display.setTextSize(3);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      display.print(index);
      display.println(char(247));
      display.setTextSize(1);
      display.print("POCITOVA");
      display.drawBitmap(120, 20, signalBase, 7, 1, WHITE);
      display.drawBitmap(118, 15, signalOne, 9, 2, WHITE);
      display.drawBitmap(116, 10, signalTwo, 11, 2, WHITE);
      display.drawBitmap(114, 5, signalThree, 13, 2, WHITE);
      display.drawBitmap(112, 0, signalFour, 15, 2, WHITE);
      if(connection){
        display.setCursor(85, 24);
        display.print("WIFI OK");
      }else{
        display.setCursor(85, 24);
        display.print("NO WIFI");
      }
      display.display();
      break;
    case 4:
      display.clearDisplay();
      display.setTextSize(3);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      display.println(timeNow);
      display.setTextSize(1);
      display.print("CAS");
      display.drawBitmap(120, 20, signalBase, 7, 1, WHITE);
      display.drawBitmap(118, 15, signalOne, 9, 2, WHITE);
      display.drawBitmap(116, 10, signalTwo, 11, 2, WHITE);
      display.drawBitmap(114, 5, signalThree, 13, 2, WHITE);
      display.drawBitmap(112, 0, signalFour, 15, 2, WHITE);
      if(connection){
        display.setCursor(85, 24);
        display.print("WIFI OK");
      }else{
        display.setCursor(85, 24);
        display.print("NO WIFI");
      }
      display.display();
      break;
    default:
      display.clearDisplay();
      display.setTextSize(2);
      display.setTextColor(WHITE);
      display.setCursor(0, 0);
      display.print("CHYBA");
      display.display();
  } 
}