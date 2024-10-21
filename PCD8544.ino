#include "PCD8544.h"
#include <Arduino.h>


#define _SCEPIN PA1
#define _DCPIN PA0
#define _RSTPIN PA4
PCD8544_LCD display_lcd;

void setup()
{
	
	display_lcd.begin(_SCEPIN , _DCPIN, _RSTPIN);

	display_lcd.Rotation(3);
	//display_lcd.drawPixel(2,2,1);
	display_lcd.setCursor(2,2);
	display_lcd.setTextColor(1);
	display_lcd.setTextSize(1);
	display_lcd.print("Hi");

	display_lcd.display();
	delay(5000);
	display_lcd.clearDisplay();
	display_lcd.display();
	




}

void loop()
{
	//display_lcd.drawPixel(5,5,1);
	//display_lcd.display();


}