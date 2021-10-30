#include "CLI.hpp"

namespace SunriseClock
{

    SimpleCLI CLI::base_cli;
    Command CLI::commandset;
    
    int CLI::argNum; 
    Argument CLI::arg;
    String   CLI::argValue;

    
    uint32_t CLI::hue;
    uint32_t CLI::value;
    uint32_t CLI::saturation;

   Adafruit_NeoPixel pixels(8, 2, NEO_GRB + NEO_KHZ800);
 
  CLI::CLI()
  {
  }

  void CLI::Open(uint32_t param_pin)
  {
    pixels.begin();
    pixels.setPin(param_pin);
   
    Command CmdSet;
    // Register Callbacks
    CmdSet = base_cli.addBoundlessCommand("test_all",HwTestCallback);
    CmdSet = base_cli.addBoundlessCommand("test_battery",BatteryChargeCallback);
    CmdSet = base_cli.addBoundlessCommand("hue",HueCallback);
    CmdSet = base_cli.addBoundlessCommand("saturation",SaturationCallback);
    CmdSet = base_cli.addBoundlessCommand("value",ValueCallback);

    CmdSet = base_cli.addBoundlessCommand("restart",RestartCallback);
    CmdSet = base_cli.addBoundlessCommand("create_defaults",CreateDefaultsSetCallback);
    CmdSet = base_cli.addBoundlessCommand("edit_defaults",EditDefaultsSetCallback);
    CmdSet = base_cli.addBoundlessCommand("add_alarm",AddAlarmCallback);
    CmdSet = base_cli.addBoundlessCommand("edit_alarm",EditAlarmCallback);
    CmdSet = base_cli.addBoundlessCommand("set_time",SetTimeCallback);
    CmdSet = base_cli.addBoundlessCommand("set_date",SetDateCallback);
    CmdSet = base_cli.addBoundlessCommand("set_display",SetDateCallback);
    CmdSet = base_cli.addBoundlessCommand("add_file",AddFile);
    CmdSet = base_cli.addCmd("help");  
    Serial.println("Service CLI started!");
  }


  void CLI::GetCommand()
  {
    if (Serial.available()) {
        // Read out string from the serial monitor
        String input = Serial.readStringUntil('\n');
    
        Serial.print("# ");
        Serial.println(input);

        // Parse the user input into the CLI
        base_cli.parse(input);
    }

  }
      void CLI::ErrorCallback(cmd* c){
        
      }
    
    /* HW-Testing Callbacks */
    void CLI::HwTestCallback(cmd* c)
    {
      
    }
    
    void CLI::BatteryChargeCallback(cmd* c)
    {
      
    }
    
    void CLI::RestartCallback(cmd* c)
    {
      
    }

    void SetPixels(uint32_t h,uint32_t s,uint32_t v)
    {
      uint32_t rgb =  pixels.gamma32(pixels.ColorHSV(h,s,v));
      pixels.fill(rgb);
      pixels.show();
      Serial.printf("Setting hue = %i, saturation = %i, value =%i\n",h,s,v);

    }
    void CLI::HueCallback(cmd* c)
    {
       Command cmd(c);               // Create wrapper object
       argNum = cmd.countArgs();    // Get number of arguments
       arg      = cmd.getArg(0);
       argValue = arg.getValue();
       hue   = argValue.toInt();
       SetPixels(hue,saturation,value);
    }
    
    void CLI::ValueCallback(cmd* c)
    {
      Command cmd(c);               
      argNum = cmd.countArgs(); 
      arg      = cmd.getArg(0);
      argValue = arg.getValue();
      value   = argValue.toInt();
      SetPixels(hue,saturation,value);
   }
    
    void CLI::SaturationCallback(cmd* c)
    {
      Command cmd(c);               
      argNum = cmd.countArgs(); 
      arg      = cmd.getArg(0);
      argValue = arg.getValue();
      saturation   = argValue.toInt();
      SetPixels(hue,saturation,value); 
    }
    
    /* Sunrise Settings Callbacks */
    void CLI::CreateDefaultsSetCallback(cmd* c)
    {
      
    }
    
    void CLI::EditDefaultsSetCallback(cmd* c)
    {
      
    }

    /* RTC Callback */
    void CLI::AddAlarmCallback(cmd* c)
    {
      
    }
    
    void CLI::EditAlarmCallback(cmd* c)
    {
      
    }
    
    void CLI::SetTimeCallback(cmd* c)
    {
      
    }
    
    void CLI::SetDateCallback(cmd* c)
    {
      
    }

    /* Display Callbacks */
    void CLI::SetDisplayLayoutCallback(cmd* c)
    {
      
    }

    /* SD Card Callbacks */
    void CLI::AddFile(cmd *c)
    {
      
    }
  
    void CLI::HelpCallback(cmd* c)
    {
      
    }
}
