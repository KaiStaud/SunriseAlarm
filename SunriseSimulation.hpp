/*
 * Simulates the Sunrise with an smooth fade from dark Red to bright white.
 * 
 */
// Setter for sunrise parameters
void SetFadeDuration(uint32_t param_minutes,uint32_t param_seconds);

// Brightness shouldn't overflow 8 Bit, for caution 32 bit is used!
bool SetSunriseSettings(uint32_t param_brightness); 

// Attaches the neopixel class to specific pin
void register_pixels(uint32_t param_pin);

// Start,Stop and Continue Functions for Sunrise Simulation
void StartSunrise();
void StopSunrise();
void ContinueSunrise();
