
#include "CPIoTDisplayTFT.h"

CPIoTDisplayTFT::CPIoTDisplayTFT():tft(TFT_eSPI()), spr(&tft) {
  
}


void CPIoTDisplayTFT::init() {
  SPI.begin(TFT_SCLK, TFT_MISO, TFT_MOSI, TFT_CS);

  pinMode(TFT_BK, OUTPUT);
  digitalWrite(TFT_BK, HIGH);

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.initDMA();
  spr.setTextFont(1);
  spr.setTextColor(TFT_WHITE);
  spr.createSprite(240, 240);
  
  tft.setTextSize(2);
  tft.setTextDatum(MC_DATUM);
  //tft.loadFont(font_12); //指定tft屏幕对象载入font_12字库
  
  int x = tft.width() / 2;
  int y = tft.height() / 2 ;

  tft.drawString("武汉", tft.width() / 2, tft.height() / 2);
  tft.drawString("LilyGo Camera Plus", tft.width() / 2, tft.height() / 2 + 20);

}

void CPIoTDisplayTFT::updatePagerMessage(String sender, String receiver, String message, unsigned char* textPixels, int dataLen) {
  tft.fillScreen(TFT_BLACK);
  int x = tft.width() / 2;
  tft.drawString("From: " + sender, x, 20);
  tft.drawString("To: " + receiver, x, 40);
  tft.drawString(message, x, 60);


  int fontWidth = sqrt(dataLen);

  unsigned char td[576];
  for (int i = 0; i < 576; i++) {
    td[i] = ((i%2) << 8);
  }
  drawTextPixel(20, 200, 24, 24, td);
}

void CPIoTDisplayTFT::setStatus(String message) {
  tft.fillScreen(TFT_BLACK);
  tft.drawString(message, tft.width() / 2, tft.height() / 2 + 20);
}

void CPIoTDisplayTFT::drawTextPixel(int x, int y, int width, int height, unsigned char* textPixels) {
  Serial.println("drawTextPixel");
  
  //spr.setColorDepth(8);
  //spr.createSprite(240, 240);
  spr.setSwapBytes(true);
  // Fill the whole sprite with black (Sprite is in memory so not visible yet)
  spr.fillSprite(TFT_BLUE);
  
  //spr.pushImage(x, y, width,height, (uint16_t *)textPixels, TFT_WHITE);
  //spr.pushSprite(0, 0, TFT_RED);


  spr.setTextFont(1);
  spr.setCursor(20, 20);
  spr.println("Hello World\n");

  spr.setCursor(20, 40);
  spr.println("Hello World\n");

  spr.pushImage(70,70,10,10, (const uint16_t*)textPixels);
  spr.pushImage(70,90,10,10, (const uint16_t*)textPixels);
  spr.pushImage(70,110,10,10, (const uint16_t*)textPixels);
  
  spr.pushSprite(0, 0);

  Serial.println("drawTextPixel end");
}

void CPIoTDisplayTFT::drawTest() {
  unsigned char td[576];
  for (int i = 0; i < 576; i++) {
    td[i] = ((i%2) << 8);
  }
  drawTextPixel(20, 200, 24, 24, td);
}
