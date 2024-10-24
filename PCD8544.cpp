
#include "PCD8544.h"
#include "Adafruit_GFX.h"
#include "SPI.h"

PCD8544_LCD::PCD8544_LCD() : Adafruit_GFX(width, height)
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
  SPI.begin();
  LCDreset();
  digitalWrite(_SCE, HIGH); // CS pin must be HIGH when the SPI can be initialized

  digitalWrite(_DC, LOW);
  uint8_t function_s1 = PCD8544_LCD_CMD_FS2;
  spi_send(&function_s1, 1);
  uint8_t bias = PCD8544_LCD_CMD_BS;
  spi_send(&bias, 1);

  uint8_t temp_control = PCD8544_LCD_CMD_TEMPC;
  spi_send(&temp_control, 1);

  uint8_t vop = PCD8544_LCD_CMD_VOP;
  spi_send(&vop, 1);

  uint8_t function_s = PCD8544_LCD_CMD_FS1; // send function set to spi
  spi_send(&function_s, 1);

  uint8_t display_control = PCD8544_LCD_CMD_DISP_NORMAL_MODE;
  spi_send(&display_control, 1);
  for (int i = 0; i < 6; i++) // if function set 1 these registers has on send to spi
  {
    uint8_t set_Y = PCD8544_LCD_CMD_SETY + i;
    spi_send(&set_Y, 1);

    //  digitalWrite(_DC, HIGH);
  }

  for (int i = 0; i < 83; i++)
  {
    uint8_t set_X = PCD8544_LCD_CMD_SETX + i;
    spi_send(&set_X, 1);
  }

  digitalWrite(_SCE, LOW);
}

void PCD8544_LCD::display()
{

  for (int i = 0; i < 6; i++)
  {
    digitalWrite(_DC, LOW);

    uint8_t set_Y = PCD8544_LCD_CMD_SETY + i;
    spi_send(&set_Y, 1);

    uint8_t set_X = PCD8544_LCD_CMD_SETX;
    spi_send(&set_X, 1);
    digitalWrite(_DC, HIGH);
    spi_send(_lcdFramebuffer + (i * 84), 84);

    digitalWrite(_DC, LOW);
  }
}

void PCD8544_LCD::initLCD()
{
}

void PCD8544_LCD::drawPixel(int16_t x, int16_t y, uint16_t color)
{
  if ((x < 0) || (x >= width) || (y < 0) || (y >= height))
    return;

  color &= 1;

  switch (rotation)
  {
  case 0: // 1 kvadrant
    break;
  case 1: // 2 kvadrant

    _swap_int16_t(x, y);
    x = width - x - 1;

    break;
  case 2: // 3 kvadrant

    _swap_int16_t(x, y);
    x = width - x - 1;
    y = height - y - 1;
    break;
  case 3: // 4 kvadrant
    _swap_int16_t(x, y);
    y = height - 1 - y;
  }

  _lcdFramebuffer[x + ((y / 8) * width)] &= ~(1 << (y % 8));
  _lcdFramebuffer[x + ((y / 8) * width)] |= (color << (y % 8));
}

void PCD8544_LCD::Rotation(int _rotation)
{

  rotation = _rotation % 4;
  switch (rotation)
  {
  case 0:
    _width = WIDTH;
    _height = HEIGHT;

    break;

  case 1:
    _width = HEIGHT;
    _height = WIDTH;
    break;
  }
}

void PCD8544_LCD::spi_send(uint8_t *_data, uint16_t _n)
{
  digitalWrite(_SCE, LOW);
  SPI.beginTransaction(_setLCD); // start the comunication with LCD

  for (int i = 0; i < _n; i++)
  {
    SPI.transfer(_data[i]); // transfer data between display and controller
  }

  SPI.endTransaction();
  digitalWrite(_SCE, HIGH);
}

void PCD8544_LCD::LCDreset()
{
  digitalWrite(_RST, LOW);

  delay(100);

  digitalWrite(_RST, HIGH);

  delay(100);
}

void PCD8544_LCD::Contrast(uint8_t contrast)
{
}

void PCD8544_LCD::clearDisplay()
{

  memset(_lcdFramebuffer, 0x00, width * height / 8);

  // memset(buffer, color ? 0xFF : 0x00, bytes);
}
