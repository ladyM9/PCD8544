#ifndef _PCD8544_H_ 
#define _PCD8544_H_ 

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#define height 48
#define width 84
#define BUFFER (height*width/8)

//registers for LCD

#define PCD8544_LCD_CMD_FS1 0b00100000 //chip is active
#define PCD8544_LCD_CMD_FS2 0b00100100 //after reset
#define PCD8544_LCD_CMD_WD 0b00100000
#define PCD8544_LCD_CMD_BS 0b00000011
#define PCD8544_LCD_CMD_TEMPC 0b00000101
#define PCD8544_LCD_CMD_VOP 0b10010000
#define PCD8544_LCD_CMD_DISPC 0b00001001  //all segments on
#define PCD8544_LCD_CMD_DISP_BLANK 0b00001000 // display is blank
#define PCD8544_LCD_CMD_DISP_NORMAL_MODE 0b00001100 
#define PCD8544_LCD_CMD_DISP_INVERSE 0b00001101
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
class PCD8544_LCD : public Adafruit_GFX
{
    public:
    PCD8544_LCD();  //constructor Class
    void begin(int _SCEPIN, int _DCPIN, int _RSTPIN); 
    void drawPixel(int16_t x, int16_t y, uint16_t color); //method for drawPixels on LCD
    void display(); //method for print anything on LCD
    void spi_send(uint8_t *_lcd, uint16_t _n);
    void writedata_functionset();
    void writedata_functionset2();
    void Contrast(uint8_t contrast);
    void clearDisplay();

    private:
    void LCDreset();
    void initLCD();
    SPISettings _setLCD;

    uint8_t _lcdFramebuffer[width*height/8] = {0};
    

    int _DC = 0;
    int _SCE = 0;
    int _RST = 0;

    uint8_t rotation;
    
};
#endif
