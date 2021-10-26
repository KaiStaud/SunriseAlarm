// Sunrise Simulation is done with Neopixels:
#include <Adafruit_NeoPixel.h>

/*
 * Simulates the Sunrise with an smooth fade from dark Red to bright white.
 * 
 */

/* -------------- Variables ----------------- */
uint32_t sunrise_time_ms;
uint32_t volatile elapsed_time;
uint32_t max_brightness;

const uint32_t max_hue = 65536*5/6; // Middle purple
const uint32_t min_hue = 65536/6;

const uint8_t pin = 5;
const uint8_t num_pixels = 8;

 Adafruit_NeoPixel strip(num_pixels, pin, NEO_GRB + NEO_KHZ800);

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
uint32_t CalculateFade(uint32_t param_mseconds)
{
 uint32_t  m_hue,new_hue;
 m_hue = (max_hue - min_hue) / sunrise_time_ms; // hue per ms (hpms)
 new_hue = m_hue * param_mseconds + min_hue;
 return new_hue;
}

// Start,Stop and Continue Functions for Sunrise Simulation
void StartSunrise()
{
  uint32_t hue;
  while(elapsed_time <= sunrise_time_ms)
  {
    hue = CalculateFade(0);
    uint32_t rgb_color = strip.ColorHSV(hue,255,255);
    strip.fill(rgb_color);
    strip.show();
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
