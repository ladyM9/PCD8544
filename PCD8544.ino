#include "PCD8544.h"

#define _SCEPIN PA1
#define _DCPIN PA0
#define _RSTPIN RESET
PCD8544_LCD display_lcd;

void setup()
{
	display_lcd.begin(_SCEPIN , _DCPIN, _RSTPIN);
}

void loop()
{
	
}
