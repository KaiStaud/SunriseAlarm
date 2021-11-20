/*
 * Display shows Time and Settings to user.
 * 
 */

struct{
  uint8_t hours;
  uint8_t minutes;
  uint8_t seconds;
}timespec;


/* Displays Time in 24-Hour Format */
 void ShowTime(timespec t);
 void ShowNextAlarm(timespec t)

 /* Views for Configuration */
 void ShowErrors();
 void ShowRiseTime(timespec t);
 void AddAlarm(timespec t);

 
 
