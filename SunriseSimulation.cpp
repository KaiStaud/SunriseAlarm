// Sunrise Simulation is done with Neopixels:
#include <Adafruit_NeoPixel.h>

/*
 * Simulates the Sunrise with an smooth fade from dark Red to bright white.
 * 
 */

/* -------------- Variables ----------------- */
uint32_t sunrise_time_ms;
uint32_t volatile elapsed_time
uint32_t max_brightness;

const max_hue = 65536*5/6; // Middle purple
const min_hue = 65536/6;

 Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

/* -------------- Functions ----------------- */


// Setter for sunrise parameters
void SetFadeDuration(uint32_t param_minutes,uint32_t param_seconds)
{
  // Convert to ms:
  sunrise_time_ms = param_seconds*1000+ param_minutes *60000;
}

// Brightness shouldn't overflow 8 Bit, for caution 32 bit is used!
bool SetSunriseSettings(uint32_t param_brightness)
{
   
}

// Attaches the neopixel class to specific pin
void register_pixels(uint32_t param_pin)
{
  
}

// Calculates the Fading Paramters by a linear fit
uint32_t CalculateFade(uint32_t param_minutes,uint32_t param_seconds)
{
 uint32_t  m_hue;
 m_hue = (max_hue - min_hue) / sunrise_time_ms; // hue per ms (hpms)
 new_hue = m_hue * sunrise_time_ms + min_hue;
 return new_hue;
}

// Start,Stop and Continue Functions for Sunrise Simulation
void StartSunrise()
{
  uint32_t start_hue = CalculateFade(0,0);
  while(elapsed_time <= sunrise_time_ms)
  {
    uint32_t rgb_color = pixels.ColorHSV(hue,saturation,value);
    pixels.fill(rgb_color);
    pixels.show();
    delay(1); // Will be replaced with interrupt
    elapsed_time++;
  }
  
}

void StopSunrise()
{
  
}

// Continues the 
void ContinueSunrise()
{
  
}
