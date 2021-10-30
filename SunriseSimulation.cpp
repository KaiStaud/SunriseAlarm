// Sunrise Simulation is done with Neopixels:
#include <Adafruit_NeoPixel.h>

/*
 * Simulates the Sunrise with an smooth fade from dark Red to bright white.
 * 
 */

/* -------------- Variables ----------------- */
const uint64_t timer_us = 1000000;

uint32_t sunrise_time_ms;
uint32_t volatile elapsed_time;
uint32_t max_brightness;

const uint8_t pin = 2;
const uint8_t num_pixels = 8;

uint64_t t_ms;


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
void RegisterSunriseHw(uint32_t param_pin)
{
 // Assign new pin and start up pixels 
 //strip.setPin(param_pin); 
 strip.begin(); 
}

/*---------------------- HSV Color Functions ---------------------------- */
uint16_t hue (uint16_t t)
{
  uint32_t hue;
  // Fade from magenta to red
  if(t < 2500)
  {
    hue = 55613 +  10922 / (2500)* t;
  }
  // Fade from red to yellow
  if(t > 2500)
  {
    hue = 10000 / (2500)* (t-2500);
  }
  return hue;
}

// Increase brightness in linear fashion!
uint16_t value(uint16_t t)
{
  uint16_t value;
  value = 255 / sunrise_time_ms * t; 
  return 255;
}


// How to fade?
uint16_t lightness (uint16_t t)
{
  uint32_t lightness = 255;

  // Start fading from yellow to white:
  // yellow is located around 12% total hue (ca. 8000)
  
  return (uint16_t) lightness;
}

/*---------------------- RGB Color Functions ---------------------------- */
// Calculate gamma corrected RGB colors
uint32_t SetPixels(uint64_t t)
{
  uint32_t rgb =  strip.gamma32(strip.ColorHSV(hue(t),value(t),lightness(t)));
  strip.fill(rgb);
  strip.show();
  return rgb; 
}

// Start,Stop and Continue Functions for Sunrise Simulation
void StartSunrise()
{
  uint32_t t = 0;
  uint32_t rgb ;
  while(t <= 5000)
  {
    SetPixels(t++);
    delay(1);
  }
}

void StopSunrise()
{
  elapsed_time =0;
}

// Continues the 
void ContinueSunrise()
{
  
}
