# 1 "D:\\Moji projekti\\PCD8544\\PCD8544.ino"
# 2 "D:\\Moji projekti\\PCD8544\\PCD8544.ino" 2




PCD8544_LCD display_lcd;

void setup()
{
 display_lcd.begin((0xC0 + 1) , 0xC0, ((((0xC0 + 1) + 1) + 1) + 1));
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
