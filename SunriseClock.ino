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

#include <Adafruit_NeoPixel.h>
 Adafruit_NeoPixel pixels(8, 2, NEO_GRB + NEO_KHZ800);

// Sunrise Sources
#include "SunriseSimulation.hpp"
#include "CLI.hpp"

using namespace SunriseClock;
static DS3231 RTC;

// Brightness / Contrast is set via PWM:
const int contrast = 120;
const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

CLI service_cli;

void setup() {
  Serial.begin(9600);
  delay(2000);
  service_cli.Open(2);

  analogWrite(6,120); // Contrast will be set by rotary encoder 
  RegisterSunriseHw(2);
  pixels.begin();
}

void loop() {
  service_cli.GetCommand();

//SetFadeDuration(0,10);
//StartSunrise();
while(1);
}
