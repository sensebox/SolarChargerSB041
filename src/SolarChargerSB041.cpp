#include "SolarChargerSB041.h"

SolarChargerSB041::SolarChargerSB041(uint8_t address)
    : address(address),
      connected(false),
      solarPanelVoltage(-1),
      batteryVoltage(-1),
      batteryLevel(-1),
      charging(false),
      fastCharging(false),
      batteryTemperature(-1) {}

void SolarChargerSB041::update() {
  Wire.beginTransmission(address);
  byte error = Wire.endTransmission();
  if (error == 0 || error == 2) {
    connected = (error == 0);
    Wire.requestFrom((uint8_t)address, (uint8_t)4);

    uint8_t vbat_raw = Wire.read();
    batteryVoltage = 0.02 * vbat_raw;

    uint8_t vin_raw = Wire.read();
    solarPanelVoltage = 0.1 * vin_raw;

    uint8_t flags = Wire.read();
    charging = flags & 1;
    if (flags & 32)
      batteryLevel = 4;
    else if (flags & 16)
      batteryLevel = 3;
    else if (flags & 8)
      batteryLevel = 2;
    else if (flags & 4)
      batteryLevel = 1;
    else
      batteryLevel = 0;

    fastCharging = flags & 64;
    charging = flags & 128;

    batteryTemperature = (int8_t)(Wire.read());
  } else {
    connected = false;
    fastCharging = false;
    charging = false;
    batteryVoltage = -1;
    solarPanelVoltage = -1;
    batteryLevel = -1;
    batteryTemperature = -1;
  }
}

bool SolarChargerSB041::isConnected() const { return connected; }
float SolarChargerSB041::getSolarPanelVoltage() const {
  return solarPanelVoltage;
}
float SolarChargerSB041::getBatteryVoltage() const { return batteryVoltage; }
int SolarChargerSB041::getBatteryLevel() const { return batteryLevel; }
bool SolarChargerSB041::isCharging() const { return charging; }
bool SolarChargerSB041::isFastCharging() const { return fastCharging; }
float SolarChargerSB041::getBatteryTemperature() const {
  return batteryTemperature;
}
