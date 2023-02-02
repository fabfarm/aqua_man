#include "esphome.h"
#include <Ultrasonic.h>

Ultrasonic ultrasonic(2);

class MyCustomSensor : public PollingComponent, public Sensor {
 public:
  // constructor
 
  MyCustomSensor() : PollingComponent(600000) {}


  void setup() override {
    // This will be called by App.setup()
  }
  void update() override {
    // This will be called every "update_interval" milliseconds.
    int waterlevel = 108 - ultrasonic.MeasureInCentimeters();
    publish_state(waterlevel);
  }
};