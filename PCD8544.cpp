<<<<<<< HEAD
#include "PCD8544.h"
#include "Adafruit_GFX.h"

PCD8544_LCD::PCD8544_LCD() : Adafruit_GFX(rows, columns)
{
}

void PCD8544_LCD::begin(int _SCEPIN, int _DCPIN, int _RSTPIN)
{
  _SCE = _SCEPIN;
  _DC = _DCPIN;
  _RST = _RSTPIN;

  _setLCD = SPISettings(2000000ULL, MSBFIRST, SPI_MODE3);

  pinMode(_SCE, OUTPUT);
  pinMode(_DC, OUTPUT);
  pinMode(_RST, OUTPUT);

 // digitalWrite(_SCE, HIGH); // CS pin must be HIGH when the SPI can be initialized
  digitalWrite(_DC, LOW);
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(_SCE, LOW);
    uint8_t _lcdstart[2] = {PCD8544_LCD_CMD_SETX, PCD8544_LCD_CMD_SETY};
    spi_send(_lcdstart);

  }

  LCDreset();
  digitalWrite(_DC, HIGH);

  uint8_t lcdBS = PCD8544_LCD_CMD_BS;
  spi_send(&lcdBS);

  display();
}

void PCD8544_LCD::display()
{
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(_DC, LOW);

    uint8_t function_s = PCD8544_LCD_CMD_FS1;
    spi_send(&function_s);

    uint8_t wd = PCD8544_LCD_CMD_WD;
    spi_send(&wd);

    uint8_t set_Y = PCD8544_LCD_CMD_SETY;
    spi_send(&set_Y);

    uint8_t set_X = PCD8544_LCD_CMD_SETX;
    spi_send(&set_X);

    digitalWrite(_DC, LOW);
  }
}

void PCD8544_LCD::drawPixel(int16_t x, int16_t y, uint16_t color)
{
  if ((x > rows - 1) || x < 0)
    return;
  if ((y > columns - 1) || y < 0)
    return;

  _frameBuffer[480 * y + x] = color >> 8;
  _frameBuffer[480 * y + x + 1] = color & 0xff;
}

void PCD8544_LCD::spi_send(uint8_t *_data)
{
  digitalWrite(_SCE, LOW);
}

void PCD8544_LCD::LCDreset()
{
  digitalWrite(_RST, LOW);

  delay(100);

  digitalWrite(_RST, HIGH);

  delay(100);
}

void PCD8544_LCD::writedata_functionset()
{
  uint8_t wsfs = PCD8544_LCD_CMD_FS2;
  spi_send(&wsfs);

  uint8_t tempc = PCD8544_LCD_CMD_TEMPC;
  spi_send(&tempc);

  uint8_t vop = PCD8544_LCD_CMD_VOP;
  spi_send(&vop);

  uint8_t bias = PCD8544_LCD_CMD_BS;
  spi_send(&bias);
=======
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


>>>>>>> 4a88d965454ffe2dc159a174deb1f1cc707f49d4
}