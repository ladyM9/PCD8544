#ifndef _PCD8544_H_ 
#define _PCD8544_H_ 

#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#define rows 48
#define columns 84

//registers for LCD

#define ST7567_LCD_CMD_BS 0b00010000
#define ST7567_LCD_CMD_TEMPC 0b00000100
#define  ST7567_LCD_CMD_VOP 0b10000000
#define ST7567_LCD_CMD_DISPC 0b00001000
#define ST7567_LCD_CMD_SETY 0b01000000
#define ST7567_LCD_CMD_SETX 0b10000000

//Class for LCD driver

class PCD8544_LCD
{
    public:
    PCD8544_LCD();  //constructor Class
    void begin(int _SCEPIN, int _DCPIN, int _RSTPIN); 
    void drawPixel(int x, int y, int color); //method for drawPixels on LCD
    void display(); //method for print anything on LCD

    private:
    void initLCD();
    void resetLCD();
    void functionsetLCD();
    void DisplayControl();
    void setY();
    void setX();
    void Temp();
    void Serial_initialize();
    void spiSend();
    SPISettings _setLCD;



    int _DC = 1;
    int _SCE = 0;
    int _RST = 0;
};
#endif
