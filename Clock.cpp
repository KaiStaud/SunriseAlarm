#include "Clock.hpp"
#include <RTClib.h>

// One Alarm per Day + one additional alarm for everyday
AlarmTime alarms[8]; 
RTC_DS3231 rtc;

 void InitClock(uint8_t interrupt_pin)
 {
      // initializing the rtc
    if(!rtc.begin()) {
        Serial.println("Couldn't find RTC!");
        Serial.flush();
        abort();
    }

    //we don't need the 32K Pin, so disable it
    rtc.disable32K();
    
    // Making it so, that the alarm will trigger an interrupt
    pinMode(interrupt_pin, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(interrupt_pin), AckAlarm, FALLING);
    
    // set alarm 1, 2 flag to false (so alarm 1, 2 didn't happen so far)
    // if not done, this easily leads to problems, as both register aren't reset on reboot/recompile
    rtc.clearAlarm(1);
    rtc.clearAlarm(2);
    
    // stop oscillating signals at SQW Pin
    // otherwise setAlarm1 will fail
    rtc.writeSqwPinMode(DS3231_OFF);
    
    // turn off alarm 2 (in case it isn't off already)
    // again, this isn't done at reboot, so a previously set alarm could easily go overlooked
    rtc.disableAlarm(2);
 }

 void SetClock(AlarmTime param_time)
 {
  
 }

void SetClockOnCompile()
{
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}
void AckAlarm()
{
      if(rtc.alarmFired(1))
      {
        rtc.clearAlarm(1);
      }
      // Get the next alarm:
  
      // On Which day is the next alarm?

      // Is there an every-day alarm?

           // Is the next-day alarm earlier then the weekday alarm?

     // Set the next alarm in RTC's hardware      
}


void AddPermanentAlarm(AlarmDay param_day,AlarmTime param_time)
{
  alarms[param_day] = param_time;
}

void AddTemporaryAlarm(AlarmDay param_day,AlarmTime param_time)
{

}

AlarmTime GetTime()
{
  AlarmTime t;
  DateTime dt;
  dt = rtc.now();

  t.h = dt.hour();
  t.m = dt.minute();
  t.s = dt.second();
  return t;
}
