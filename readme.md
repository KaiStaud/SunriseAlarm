## Architecture
The Sunrise Alarm Clock is using an Teensy 4.1 as its processin unit.
This choice is depending on the following reasons:
- Build-In SD-Card Slot (will be used as plug-in timeprofile provider)
- Compatible with Arduino Platform (reduced dev-time)
- Sufficient Memory for Neopixel animation patterns

This pick may be "overpowered" for its task, but is currently the best platform
by price regarding its options.

## Capabilities
- Can retain enough time/alarm profiles as desired
- Battery Backup for min. 8 hours
- Alarm proviles will be stored in non-volutile memory of choice
- Time is kept even after full power failure in seperate RTC
- Easily available Display Option 16x2 Display
- Encoder-driven Interface 

## Dependencies
- Snooze
- LiquidCrystal
- Adafruit_Neopixel
- Wire
- RTC
