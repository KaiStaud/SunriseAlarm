// Sunrise Simulation is done with Neopixels:
#include <Adafruit_NeoPixel.h>

/*
 * Simulates the Sunrise with an smooth fade from dark Red to bright white.
 * 
 */

/* -------------- Variables ----------------- */
const uint64_t timer_us = 1000000;

uint32_t T_E = 10000;
uint32_t T_white = 5000;
uint32_t T_magenta = 2500;
uint32_t T_red = 2500;
uint32_t T_yellow = 5000;
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
  T_E = param_seconds*1000+ param_minutes *60000;
  // Calculate Fading Phases in ms
  T_white = T_E /2;
  T_magenta = T_E /4;
  T_red = T_E / 4;
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

/*
 * @ brief:
 * During Sunrise the hue is changed in three phases
 * Phase1 : Fade from magenta to red
 * Phase1 : Fade from red to yellow
 * Phase3 : Not changing the hue at all (Fading by lightness)
 * 
 * Fades are done linearly. The time of each phase is set by variables above
 * 
 * @ param: elapsed time in ms
 * @ return: Hue is scaled according to Adafruits Neopixel Ueberguide:
 *           0° Hue = 0x0000, 360° Hue = 0xFFFF-1
 *           https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use 
 *            
 */
uint16_t hue (uint16_t t)
{
  uint32_t hue;
  // Fade from magenta to red
  if(t < T_magenta)
  {
    hue = 55613 +  10922 / (T_magenta)* t;
  }
  // Fade from red to yellow
  if(t > T_magenta)
  {
    hue = 10000 / (T_red)* (t-T_magenta);
  }
  // Clamp hue at yellow, lightness is fading 
  if(t >= 5000)  
  {
    hue = 10000;
  }
  return hue;
}
/*
 * @ brief:
 * During Sunrise the lightness/saturation is changed in two phases
 * Phase1 : Fade from magenta to yellow
 * Phase1 : Fade from yellow to white
 * 
 * Fades are done linearly. The time of each phase is set by variables above
 * 
 * @ param: elapsed time in ms
 * @ return: Lightness is scaled according to Adafruits Neopixel Ueberguide:
 *           0  = 0%, 0xFF = 100%
 *           https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use 
 *            
 */
uint16_t lightness (uint16_t t)
{
  uint32_t lightness = 255;

  // Start fading from yellow to white:
  // yellow is located around 12% total hue (ca. 8000)
  if(t >= (T_magenta+T_yellow)) // reached at t >= 5000
  {
    lightness = 255-(255-80)*(t-T_magenta+T_yellow)/T_white;
  }
  else // Till yellow: maximum saturation
  {
    lightness = 255;
  }
  return (uint16_t) lightness;
}

/*---------------------- RGB Color Functions ---------------------------- */
/* 
 *  @ brief: Calculate gamma corrected RGB colors based on hue(t),lightness(t)and value(t)
 *  @ param: elapsed time in ms 
 *  @ return: RGB converted HSV tripplet
*/
uint32_t SetPixels(uint64_t t)
{
  uint32_t rgb =  strip.gamma32(strip.ColorHSV(hue(t),lightness(t),255));
  strip.fill(rgb);
  strip.show();
  return rgb; 
}

// Start,Stop and Continue Functions for Sunrise Simulation
void StartSunrise()
{
  uint32_t t = 0;
  while(t <= T_E)
  {
    SetPixels(t++);
    delay(1);
  }
}

void StopSunrise()
{
}

// Continues the 
void ContinueSunrise()
{
  
}
