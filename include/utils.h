#ifndef UTILS_H
#define UTILS_H

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <stddef.h>

extern uint16_t backgroundColor;

uint16_t convertRGB(uint8_t r, uint8_t g, uint8_t b);
void showSprite(TFT_eSprite sprite, int x, int y, int w, int h, const unsigned char *image);
void fillSprite(TFT_eSprite sprite, int x, int y, int w, int h, uint16_t color);
void fadeInTop(TFT_eSprite sprite, int x, int y, int w, int h, const unsigned char *images[], int imagesSize, int fadeDistance, int delayMs);
void fadeOutTop(TFT_eSprite sprite, int x, int y, int w, int h, const unsigned char *images[], int imagesSize, int fadeDistance, int delayMs);
void fadeInBottom(TFT_eSprite sprite, int x, int y, int w, int h, const unsigned char *images[], int imagesSize, int fadeDistance, int delayMs);
void fadeOutBottom(TFT_eSprite sprite, int x, int y, int w, int h, const unsigned char *images[], int imagesSize, int fadeDistance, int delayMs);
void increaseNumber(TFT_eSprite sprite, int &number);
void decreaseNumber(TFT_eSprite sprite, int &number);
const unsigned char **getImages(int number);

#endif