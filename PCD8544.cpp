
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
 // digitalWrite(_SCE, HIGH); // CS pin must be HIGH when the SPI can be initialized
  digitalWrite(_DC, LOW);
  uint8_t function_s = PCD8544_LCD_CMD_FS1; //send function set to spi
  spi_send(&function_s, 1);
  uint8_t function_s1 = PCD8544_LCD_CMD_FS2;
  spi_send(&function_s1,1);


   digitalWrite(_DC, HIGH);

  display();

  initLCD();


}

void PCD8544_LCD::display()
{
  for (int i = 0; i < 8; i++) //if function set 1 these registers has on send to spi
  {
    digitalWrite(_DC, LOW); //_DC must be LOW(datasheet)

    uint8_t display_control = PCD8544_LCD_CMD_DISPC;
    spi_send(&display_control, 1);

    uint8_t set_Y = PCD8544_LCD_CMD_SETY;
    spi_send(&set_Y, 1);

    uint8_t set_X = PCD8544_LCD_CMD_SETX;
    spi_send(&set_X, 1);

   
    spi_send(_lcdFramebuffer + (i * 98), 98);

    digitalWrite(_DC, LOW);
  }
}

void PCD8544_LCD::initLCD()
{

  uint8_t bias = PCD8544_LCD_CMD_BS;
  spi_send(&bias,1);

  uint8_t temp_control = PCD8544_LCD_CMD_TEMPC;
  spi_send(&temp_control, 1);

  uint8_t vop = PCD8544_LCD_CMD_VOP;
  spi_send(&vop,1);

  


}

void PCD8544_LCD::drawPixel(int16_t x, int16_t y, uint16_t color)
{
     if ((x < 0) || (x >= width) || (y < 0) || (y >= height))
    return;

    if (color)
    _lcdFramebuffer[x + (y / 8) * width] |= 1 << (y % 8);
  else
    _lcdFramebuffer[x + (y / 8) * width] &= ~(1 << (y % 8));
}

void PCD8544_LCD::spi_send(uint8_t *_data, uint16_t _n)
{
  digitalWrite(_SCE, LOW);
  SPI.beginTransaction(_setLCD); //start the comunication with LCD

  for (int i = 0; i < _n; i++)
  {
    SPI.transfer(_data[i]); //transfer data between display and controller
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
  memset(_lcdFramebuffer, 0x00, sizeof(_lcdFramebuffer));
 // memset(buffer, color ? 0xFF : 0x00, bytes);
}



