#include <Arduino.h>
#include "TFT_eSPI.h"

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library 

TFT_eSprite spritte = TFT_eSprite(&tft); // Sprite object "spritte" created


#define BL 4
#define IO2 2



int brightness,fadeAmount = 15; // Screen size

void setup() {
Serial.begin(115200);

Serial.println("SETUP");
tft.init();
tft.setSwapBytes(true);
pinMode(BL, OUTPUT);
pinMode(IO2, OUTPUT);

digitalWrite(BL, HIGH);

Serial.println("ESP BEGIN");

tft.fillScreen(TFT_ORANGE);
}

void loop() {
  analogWrite(IO2, brightness);
  brightness = brightness + fadeAmount; // Change the brightness
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount; // Reverse the fade direction
  }
  Serial.println("Hello World");
  delay(10);

  // put your main code here, to run repeatedly:
}

