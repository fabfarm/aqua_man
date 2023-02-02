#include "esphome.h"
#include <Ultrasonic.h>

Ultrasonic ultrasonic(2);

class Waterlevelsensor : public Component {
 public:
  void setup() override {
    // This will be called once to set up the component
    // think of it as the setup() call in Arduino
  }

  void loop() override {
    
    // This will be called very often after setup time.
    // think of it as the loop() call in Arduino
    int waterlevel = 108 - ultrasonic.MeasureInCentimeters();
    float percent = waterlevel / float(0.95);
    delay(2000);
    ESP_LOGD("waterlevel", "%i cm -> %.0f %%", waterlevel, percent);
  }
};
