#include <SimpleCLI.h>
#include <Adafruit_NeoPixel.h>

namespace SunriseClock{
  class CLI
  {
   public:
    CLI(); 
    void Open(uint32_t param_pin);
    static void GetCommand();
    
    private:
    
    static void ErrorCallback(cmd* c);
    
    /* HW-Testing Callbacks */
    static void HwTestCallback(cmd* c);
    static void BatteryChargeCallback(cmd* c);
    static void RestartCallback(cmd* c);

    static void HueCallback(cmd* c);
    static void ValueCallback(cmd* c);
    static void SaturationCallback(cmd* c);
    
    /* Sunrise Settings Callbacks */
    static void CreateDefaultsSetCallback(cmd* c);
    static void EditDefaultsSetCallback(cmd* c);

    /* RTC Callback */
    static void AddAlarmCallback(cmd* c);
    static void EditAlarmCallback(cmd* c);
    static void SetTimeCallback(cmd* c);
    static void SetDateCallback(cmd* c);

    /* Display Callbacks */
    static void SetDisplayLayoutCallback(cmd* c);

    /* SD Card Callbacks */
    static void AddFile(cmd *c);
  
    static void HelpCallback(cmd* c);


    static SimpleCLI base_cli;
    static Command commandset;
    
    static int argNum; 
    static Argument arg;
    static String   argValue;

    
    static uint32_t hue;
    static uint32_t value;
    static uint32_t saturation;
   
  };
}
