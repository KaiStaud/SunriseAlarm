// Sunrise Simulation is done with Neopixels:
#include <Adafruit_NeoPixel.h>
#include <TimerOne.h>

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

volatile uint64_t time_ms;

 Adafruit_NeoPixel strip(num_pixels, pin, NEO_GRB + NEO_KHZ800);

/* -------------- Functions ----------------- */

/* ISR Routine */
void timer_isr()
{
  time_ms++;
}

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
 Timer1.initialize(timer_us);
 Timer1.attachInterrupt(timer_isr); 
 // Stop the Interrupt for now, we will start it again when needed!
 noInterrupts();
 // Assign new pin and start up pixels 
 strip.setPin(param_pin); 
 strip.begin(); 
}

/*---------------------- HSV Color Functions ---------------------------- */
uint16_t hue (uint16_t t)
{
  uint16_t hue;
  // First fade phase: Fade from magenta to red:
  if(time_ms < sunrise_time_ms/2)
  {
    hue = 55613 +  10922 / (2500)* t;
  }
  // Seconds fade phase: Fade from red to yellow:
  else
  {
    hue = 7000 / (2500)* t;
  }
  return hue;

}

// Increase brightness in linear fashion!
uint16_t value(uint16_t t)
{
  uint16_t value;
  value = 255 * t / sunrise_time_ms; 
  return value;
}


// How to fade?
uint16_t lightness (uint16_t t)
{
  
}

/*---------------------- RGB Color Functions ---------------------------- */
// Calculate gamma corrected RGB colors
uint32_t HSV_to_RGB()
{
  uint64_t t = time_ms;
  return strip.gamma32(strip.ColorHSV(hue(t),value(t),lightness(t)));
}

// Start,Stop and Continue Functions for Sunrise Simulation
void StartSunrise()
{
// Restart timer1  
interrupts();
}

void StopSunrise()
{
  elapsed_time =0;
}

// Continues the 
void ContinueSunrise()
{
  
}
