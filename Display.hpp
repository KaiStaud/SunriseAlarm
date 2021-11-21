/*
 * Display shows Time and Settings to user.
 * 
 */
#include <stdint.h>
struct rtc_time{
  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
};

void InitDisplay();

/* Displays Time in 24-Hour Format */
void ShowTime(uint8_t h, uint8_t m,uint8_t s);
void ShowNextAlarm(uint8_t h, uint8_t m,uint8_t s);

 /* Views for Configuration */
 void ShowErrors();
// void ShowRiseTime(rtc_time t);
// void AddAlarm(rtc_time t);

 
 
