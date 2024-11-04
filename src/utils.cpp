#include <utils.h>
#include <images.h>

uint16_t backgroundColor = convertRGB(112, 146, 190);

/* Convert 8-bit RGB values to 16-bit RGB565 */
uint16_t convertRGB(uint8_t r, uint8_t g, uint8_t b)
{
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

/******************************************************************************************/
/* Sprite */

/* for images */
void showSprite(TFT_eSprite sprite, int x, int y, int w, int h, const unsigned char *image)
{
    if (sprite.createSprite(w, h) == nullptr)
    {
        Serial.println("Error: Failed to create sprite. Not enough memory!");
    }
    else
    {
        sprite.pushImage(0, 0, w, h, (const uint16_t *)image);
        sprite.pushSprite(x, y, TFT_BLACK);
        sprite.deleteSprite();
    }
}

/* just for filling with one color */
void fillSprite(TFT_eSprite sprite, int x, int y, int w, int h, uint16_t color)
{
    if (sprite.createSprite(w, h) == nullptr)
    {
        Serial.println("Error: Failed to create sprite. Not enough memory!");
    }
    else
    {
        sprite.fillScreen(color);
        sprite.pushSprite(x, y, TFT_BLACK);
        sprite.deleteSprite();
    }
}

/******************************************************************************************/
/* Fade Animations */
/* done by showing multiple images where coordinates and colors change, creating fading effect */

void fadeInTop(TFT_eSprite sprite,
               int x,
               int y,
               int w,
               int h,
               const unsigned char *images[],
               int imagesSize,
               int fadeDistance,
               int delayMs)
{
    for (size_t i = 0; i < imagesSize; i++)
    {
        fillSprite(sprite, x, y - (imagesSize - i) * fadeDistance, w, h, backgroundColor);
        showSprite(sprite, x, y - (imagesSize - (i + 1)) * fadeDistance, w, h, images[imagesSize - (i + 1)]);
        delay(delayMs);
    }
}

void fadeOutTop(
    TFT_eSprite sprite,
    int x,
    int y,
    int w,
    int h,
    const unsigned char *images[],
    int imagesSize,
    int fadeDistance,
    int delayMs)
{
    for (size_t i = 0; i < imagesSize; i++)
    {
        fillSprite(sprite, x, y - (i - 1) * fadeDistance, w, h, backgroundColor);
        showSprite(sprite, x, y - i * fadeDistance, w, h, images[i]);
        delay(delayMs);
        if (i == 3)
            fillSprite(sprite, x, y - i * fadeDistance, w, h, backgroundColor);
    }
}

void fadeInBottom(TFT_eSprite sprite,
                  int x,
                  int y,
                  int w,
                  int h,
                  const unsigned char *images[],
                  int imagesSize,
                  int fadeDistance,
                  int delayMs)
{
    for (size_t i = 0; i < imagesSize; i++)
    {
        fillSprite(sprite, x, y + (imagesSize - i) * fadeDistance, w, h, backgroundColor);
        showSprite(sprite, x, y + (imagesSize - (i + 1)) * fadeDistance, w, h, images[imagesSize - (i + 1)]);
        delay(delayMs);
    }
}

void fadeOutBottom(TFT_eSprite sprite,
                   int x,
                   int y,
                   int w,
                   int h,
                   const unsigned char *images[],
                   int imagesSize,
                   int fadeDistance,
                   int delayMs)
{
    for (size_t i = 0; i < imagesSize; i++)
    {
        fillSprite(sprite, x, y + (i - 1) * fadeDistance, w, h, backgroundColor);
        showSprite(sprite, x, y + i * fadeDistance, w, h, images[i]);
        delay(delayMs);
        if (i == 3)
            fillSprite(sprite, x, y + i * fadeDistance, w, h, backgroundColor);
    }
}

/******************************************************************************************/
/******************************************************************************************/

/* simple representation using only one digit */
#ifdef INCLUDE_IMAGES_100x100

void increaseNumber(TFT_eSprite sprite, int &number)
{
    fadeOutBottom(sprite, 70, 70, 100, 100, getImages(number), 4, 15, 10);
    number++;
    if (number > 9)
        number = 0;
    fadeInTop(sprite, 70, 70, 100, 100, getImages(number), 4, 15, 10);
}

void decreaseNumber(TFT_eSprite sprite, int &number)
{
    fadeOutTop(sprite, 70, 70, 100, 100, getImages(number), 4, 15, 10);
    number--;
    if (number < 0)
        number = 9;
    fadeInBottom(sprite, 70, 70, 100, 100, getImages(number), 4, 15, 10);
}

/* the real deal */
/* 3 images -> XY,Z */
/* comma look like shit ??? */
#elif INCLUDE_IMAGES_30x40

void increaseNumber(TFT_eSprite sprite, int &number)
{
    // TODO
}

void decreaseNumber(TFT_eSprite sprite, int &number)
{
    // TODO
}

#endif

/******************************************************************************************/
/******************************************************************************************/

const unsigned char **getImages(int number)
{
    switch (number)
    {
    case 0:
        return _0_images;
    case 1:
        return _1_images;
    case 2:
        return _2_images;
    case 3:
        return _3_images;
    case 4:
        return _4_images;
    case 5:
        return _5_images;
    case 6:
        return _6_images;
    case 7:
        return _7_images;
    case 8:
        return _8_images;
    case 9:
        return _9_images;
    default:
        return nullptr;
    }
}