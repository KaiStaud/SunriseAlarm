#include "Display.hpp"
#include <BigFont02.h>
#include <LiquidCrystal.h>

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
BigFont02     big(&lcd);

const int dot_position = 6;

byte dot[8]{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  };


/* 
 *  Initialize libraries and Display.
 *  Clear after Setup and Display Time
*/
void InitDisplay()
{
  lcd.begin(16,2);
  lcd.createChar(0, dot);
  lcd.clear();
  
  /*
  lcd.setCursor(dot_position,1);
  lcd.write(byte(0));
  lcd.setCursor(dot_position,0);
  lcd.write(byte(0));
  */
  
  big.begin();
  
  lcd.setCursor(0,0);
  delay(2000);
 
}

void ShowTime(uint8_t h, uint8_t m,uint8_t s)
{
    big.writeint(0,0,h,2,true); // display milliseconds value using 4 digits with leading zeros enabled starting at row 0 column 5
    big.writeint(0,7,m,2,true);
    lcd.setCursor(14,0);
    lcd.print(s);
}
