#include "esphome.h"
#include <Ultrasonic.h>

Ultrasonic ultrasonic(2);

class MyCustomComponent : public Component {
 public:
  void setup() override {
  }

  void loop() override {
    float RangeInCentimeters = ultrasonic.MeasureInCentimeters();
    delay(2000);
    ESP_LOGD("waterlevel in cm", "%f ", RangeInCentimeters);

  }
};
