
#include "CPIoTDisplayTFT.h"


CPIoTDisplayTFT display;


void setup(){
  delay(2000);
  
  char buff[256];
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  
  Serial.println("init display...");

  display.init();

  display.drawTest();
  delay(5000);
}

void loop(){
  // clear the display
  delay(1000);
}
