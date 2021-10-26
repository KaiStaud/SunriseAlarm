/*
 * Before uploading:
 * Set COM to COM4 ( Teensy 4.1)
 */

// SRC will be be approx. 66% in Powerdown-Mode, therefore deep-sleep is used:
#include <Snooze.h>


// Display Module: Parallel LCD
#include <LiquidCrystal.h>

// Selected RTC: DS3231
#include <Wire.h>
#include <RTC.h>


// Sunrise Sources
#include "SunriseSimulation.hpp"

static DS3231 RTC;

// Brightness / Contrast is set via PWM:
const int contrast = 120;
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");
  RTC.begin();
  if(RTC.isRunning());
  else
  {
    RTC.setHourMode(CLOCK_H24);
    RTC.setDateTime(__DATE__, __TIME__);
    RTC.startClock();
  }
  analogWrite(6,120); // Contrast will be set by rotary encoder 
  RegisterSunriseHw(5);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
  analogWrite(6,120);
  //rgb_fade();
  SetFadeDuration(0,5);
  while(1)
  {
  StartSunrise();
  StopSunrise();
  }

}
