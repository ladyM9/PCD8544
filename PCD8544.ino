#include "PCD8544.h"

#define _SCEPIN PA1
#define _DCPIN PA0
#define _RSTPIN PA4
PCD8544_LCD display_lcd;

void setup()
{
	display_lcd.begin(_SCEPIN , _DCPIN, _RSTPIN);
	//display_lcd.setTextColor(0xFFFFFF, 0x000000);
	display_lcd.setTextColor(0x000000, 0xFFFFFF);
	display_lcd.setTextSize(2);
	display_lcd.setCursor(20,20);
	display_lcd.print("Hello");
	display_lcd.display();
	delay(5000);
}

void loop()
{
	

}
