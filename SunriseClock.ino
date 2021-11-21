/*
 * Before uploading:
 * Set COM to COM4 ( Teensy 4.1)
 */

// SRC will be be approx. 66% in Powerdown-Mode, therefore deep-sleep is used:
#include <Snooze.h>

// Sunrise Sources
#include "SunriseSimulation.hpp"
#include "CLI.hpp"
#include "Display.hpp"
#include "Clock.hpp"

using namespace SunriseClock;

// Brightness / Contrast is set via PWM:
const int contrast = 120;

CLI service_cli;


void setup() {
  Serial.begin(9600);
  delay(2000);
  service_cli.Open(2);

  analogWrite(6,120); // Contrast will be set by rotary encoder 
  RegisterSunriseHw(2);
  InitDisplay();
  InitClock(0);
  SetClockOnCompile();
 }

void loop() {
  service_cli.GetCommand();
//StartSunrise();
AlarmTime t = GetTime();
ShowTime(t.h,t.m,t.s);
}
