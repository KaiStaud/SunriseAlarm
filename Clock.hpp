/*
 * Configures RTC and Alarms.
 * Enables Interrupt functionality on interrupt pin
 */

#include <stdbool.h>
#include <stdint.h>

enum AlarmDay
{
  monday =0,
  tuesday = 1,
  wednesday = 2,
  thursday = 3,
  friday = 4,
  saturday = 5,
  sunday = 6,
  every_day =7,
};

struct AlarmTime
{
  uint8_t h;
  uint8_t m;
  uint8_t s;
  bool enabled;
};

void InitClock(uint8_t interrupt_pin);

// Set new Time
void SetClock(AlarmTime param_time);

void SetClockOnCompile();

// Reset Alarm ins RTC's hardware
void AckAlarm();

// Add new permanent alarm to SRC 
void AddPermanentAlarm(AlarmDay param_day,AlarmTime param_time);

// Creates a temporary alarm, which will be deleted when expired!
void AddTemporaryAlarm(AlarmDay param_day,AlarmTime param_time);

// Pass RTC Time to other modules
AlarmTime GetTime();
