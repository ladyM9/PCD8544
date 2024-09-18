#line 1 "D:\\Moji projekti\\PCD8544\\PCD8544.cpp"
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