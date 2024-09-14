#line 1 "D:\\Moji projekti\\PCD8544\\PCD8544.cpp"
#include "PCD8544.h"

PCD8544_LCD::PCD8544_LCD()
{
}

void PCD8544_LCD::begin(int _CSPIN, int _DCPIN, int _RSTPIN)
{
    _CSPIN = _SCE;
    _DCPIN = _DC;
    _RSTPIN = _RST;

    _setLCD = SPISettings(20000000, MSBFIRST, SPI_MODE3);

    pinMode(_CSPIN, OUTPUT);
    pinMode(_DCPIN, OUTPUT);
    pinMode(_RSTPIN, OUTPUT);

    int16_t x;
    int16_t y;
    int16_t color;
    

    digitalWrite(_CSPIN, HIGH); // CS pin must be HIGH when the SPI can be initialized
    digitalWrite(_RST, LOW);
    digitalWrite(_DC, HIGH);
    for (int i = 0; i < 8; i++)
    {
        uint8_t _lcdstart[2] = {PCD8544_LCD_CMD_SETX, PCD8544_LCD_CMD_SETY};
    }
    digitalWrite(_SCE, HIGH);

      // Check for display area.
    if ((x < 0) || (x > (rows - 1)) || (y < 0) || (y > (columns))) return;

     switch (rotation)
    {
        case 0:
          // Do nothing, default rotation.
          break;
        case 1:
          _swap_int16_t(x, y);
          x = rows - x - 1;
          break;
        case 2:
          x = columns - x - 1;
          y = rows - y - 1;
          break;
        case 3:
          _swap_int16_t(x, y);
          y = columns - y - 1;
          break;
    }

    // Limit color only to B/W.
    color &= 1;



    _lcdFramebuffer[x + ((y / 8) * 128)] &= ~(1 << (y % 8));
    _lcdFramebuffer[x + ((y / 8) * 128)] |= (color << (y % 8));

    PCD8544_LCD_CMD_BS;
    PCD8544_LCD_CMD_DISPC;
    PCD8544_LCD_CMD_SETX;
    PCD8544_LCD_CMD_SETY;
    PCD8544_LCD_CMD_TEMPC;
    PCD8544_LCD_CMD_VOP;


}
