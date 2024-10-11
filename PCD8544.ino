#include "PCD8544.h"
#include <Arduino.h>


#define _SCEPIN PA1
#define _DCPIN PA0
#define _RSTPIN PA4
PCD8544_LCD display_lcd;

void setup()
{
	display_lcd.begin(_SCEPIN , _DCPIN, _RSTPIN);
	//display_lcd.setTextColor(0xFFFFFF, 0x000000);

	display_lcd.display();
	delay(5000);
	display_lcd.clearDisplay();



}

void loop()
{
	display_lcd.drawPixel(5,5,1);
	display_lcd.display();

}