#ifndef SOLARCHARGER_H
#define SOLARCHARGER_H

#include <Wire.h>

class SolarCharger {
 public:
  SolarCharger(uint8_t address = 0x32);
#ifndef SOLARCHARGER_H
#define SOLARCHARGER_H

#include <Wire.h>

      class SolarCharger {
   public:
    SolarCharger(uint8_t address = 0x32);

    void update();
    bool isConnected() const;
    float getSolarPanelVoltage() const;
    float getBatteryVoltage() const;
    int getBatteryLevel() const;
    bool isCharging() const;
    bool isFastCharging() const;
    float getBatteryTemperature() const;

   private:
    uint8_t address;
    bool connected;
    float solarPanelVoltage;
    float batteryVoltage;
    int batteryLevel;
    bool charging;
    bool fastCharging;
    float batteryTemperature;
  };

#endif  // SOLARCHARGER_H

  void update();
  bool isConnected() const;
  float getSolarPanelVoltage() const;
  float getBatteryVoltage() const;
  int getBatteryLevel() const;
  bool isCharging() const;
  bool isFastCharging() const;
  float getBatteryTemperature() const;

 private:
  uint8_t address;
  bool connected;
  float solarPanelVoltage;
  float batteryVoltage;
  int batteryLevel;
  bool charging;
  bool fastCharging;
  float batteryTemperature;
};

#endif  // SOLARCHARGER_H