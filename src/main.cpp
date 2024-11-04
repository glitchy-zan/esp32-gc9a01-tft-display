#include <images.h>
#include <utils.h>

#define BUTTON_UP 5
#define BUTTON_DOWN 21

/* include lib, configuration is done in User_Setup.h */
TFT_eSPI tft = TFT_eSPI();
TFT_eSprite sprite = TFT_eSprite(&tft);
int number = 0;

void setup()
{
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  Serial.begin(9600);
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(backgroundColor);
  showSprite(sprite, 70, 70, 100, 100, _0_images[0]);
}

void loop()
{
  if (digitalRead(BUTTON_UP) == LOW)
  {
    increaseNumber(sprite, number);
    delay(300);
  }
  if (digitalRead(BUTTON_DOWN) == LOW)
  {
    decreaseNumber(sprite, number);
    delay(300);
  }
}