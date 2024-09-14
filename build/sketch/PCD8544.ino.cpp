#include <Arduino.h>
#line 1 "D:\\Moji projekti\\PCD8544\\PCD8544.ino"
#include "PCD8544.h"

#define _SCEPIN PA1
#define _DCPIN PA0
#define _RSTPIN RESET
PCD8544_LCD display_lcd;

#line 8 "D:\\Moji projekti\\PCD8544\\PCD8544.ino"
void setup();
#line 13 "D:\\Moji projekti\\PCD8544\\PCD8544.ino"
void loop();
#line 8 "D:\\Moji projekti\\PCD8544\\PCD8544.ino"
void setup()
{
	display_lcd.begin(_SCEPIN , _DCPIN, _RSTPIN);
}

void loop()
{
	
}

