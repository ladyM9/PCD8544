#ifndef _PCD8544_H_ 
#define _PCD8544_H_ 

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#define rows 48
#define columns 84

//registers for LCD

#define PCD8544_LCD_CMD_FS1 0b00100000
#define PCD8544_LCD_CMD_FS2 0b00100001
#define PCD8544_LCD_CMD_WD 0b10101010
#define PCD8544_LCD_CMD_BS 0b00000011
#define PCD8544_LCD_CMD_TEMPC 0b00000100
#define PCD8544_LCD_CMD_VOP 0b10010000
#define PCD8544_LCD_CMD_DISPC 0b00001001
#define PCD8544_LCD_CMD_SETY 0b01000000
#define PCD8544_LCD_CMD_SETX 0b10000000

//Class for LCD driver
#ifndef _swap_int16_t
#define _swap_int16_t(a, b)                                                    \
  {                                                                            \
    int16_t t = a;                                                             \
    a = b;                                                                     \
    b = t;                                                                     \
  }
#endif
class PCD8544_LCD
{
    public:
    PCD8544_LCD();  //constructor Class
    void begin(int _SCEPIN, int _DCPIN, int _RSTPIN); 
    void drawPixel(int x, int y, int color); //method for drawPixels on LCD
    void display(); //method for print anything on LCD

    private:
 
    SPISettings _setLCD;

    uint8_t _lcdFramebuffer[columns*rows/8];

    int _DC = 1;
    int _SCE = 0;
    int _RST = 0;

    uint8_t rotation;
};
#endif
