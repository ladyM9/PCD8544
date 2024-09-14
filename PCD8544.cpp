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
  digitalWrite(_RSTPIN, LOW);
  digitalWrite(_DCPIN, HIGH);
  for (int i = 0; i < 8; i++)
  {
    uint8_t _lcdstart[2] = {PCD8544_LCD_CMD_SETX, PCD8544_LCD_CMD_SETY};
  }
  digitalWrite(_CSPIN, LOW);
  // Check for display area.

  // Limit color only to B/W.


  PCD8544_LCD_CMD_BS;

}

void PCD8544_LCD::drawPixel(int x, int y, int color)
{
  if ((x < 0) || (x > (rows - 1)) || (y < 0) || (y > (columns)))
    return;

    color &= 1;

  _lcdFramebuffer[x + ((y / 8) * 128)] &= ~(1 << (y % 8));
  _lcdFramebuffer[x + ((y / 8) * 128)] |= (color << (y % 8));
}

void PCD8544_LCD::display()
{
  for(int i = 0; i < 8; i++)
  {
    digitalWrite(_DC, LOW);

    PCD8544_LCD_CMD_FS1;
    PCD8544_LCD_CMD_WD;
    PCD8544_LCD_CMD_SETY;
    PCD8544_LCD_CMD_SETX;

  }


}