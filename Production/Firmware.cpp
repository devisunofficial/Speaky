
#include "BluetoothA2DPSink.h"

#define I2S_BCLK      26   
#define I2S_LRCK      25   
#define I2S_DIN       22   
#define PAIRING_PIN   13   

const char* bluetooth_name = "Jazz";


unsigned long touch_start_time = 0;       
bool touch_was_active = false;            
const unsigned long required_hold_time = 10000; 


BluetoothA2DPSink a2dp_sink;

void setup() {
  Serial.begin(115200);
  Serial.println("[SYSTEM] Booting Speaker Engine...");

  
  pinMode(PAIRING_PIN, INPUT_PULLDOWN);

  
  i2s_pin_config_t my_pin_config = {
    .bcl_io_num = I2S_BCLK,
    .ws_io_num = I2S_LRCK,
    .data_out_num = I2S_DIN,
    .data_in_num = I2S_PIN_NOT_USED
  };
  a2dp_sink.set_pin_config(my_pin_config);

  
  a2dp_sink.set_mono_downmix(true); 

  
  a2dp_sink.set_auto_reconnect(true); 
  
  a2dp_sink.start(bluetooth_name);
  Serial.println("[BLUETOOTH] Engine active. Searching for saved devices...");
}

void loop() {
    

  bool current_touch_state = digitalRead(PAIRING_PIN);

  
  if (current_touch_state == HIGH) {
    
    if (!touch_was_active) {
        
      touch_start_time = millis();
      touch_was_active = true;
      Serial.println("[TOUCH] Pad touched. Keep holding for 10s to FORGET phone memory.");
    } 
    else {
      unsigned long elapsed_time = millis() - touch_start_time;
      
      
      if (elapsed_time % 1000 < 50) { 
        Serial.print("[TOUCH] Timing: ");
        Serial.print(elapsed_time / 1000);
        Serial.println("/10 seconds elapsed.");
      }

      
      if (elapsed_time >= required_hold_time) {
        Serial.println("[SYSTEM] 10 seconds reached! Executing Full Cache Memory Wipe...");
        
        
        if (a2dp_sink.is_connected()) {
          Serial.println("[BLUETOOTH] Disconnecting existing host link...");
          a2dp_sink.disconnect();
        }
        
        
        Serial.println("[FLASH] Wiping saved device MAC keys from memory...");
        a2dp_sink.clean_last_connection(); 
        
        Serial.println("[BLUETOOTH] Speaker is now completely blank. Ready for new phone registration!");
        
        
        touch_was_active = false; 
        delay(1500); 
      }
    }
  } 
  
  else {
    
    if (touch_was_active) {
      Serial.println("[TOUCH] Finger lifted early. Stored pairing memory intact.");
      touch_was_active = false;
      touch_start_time = 0;
    }
  }

  delay(50);
}