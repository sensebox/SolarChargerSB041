#include <SolarCharger.h>
#include <Wire.h>

SolarCharger solar;

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  solar.update();

  if (solar.isConnected()) {
    Serial.print("Solar Panel Voltage: ");
    Serial.println(solar.getSolarPanelVoltage());
    Serial.print("Battery Voltage: ");
    Serial.println(solar.getBatteryVoltage());
    Serial.print("Battery Level: ");
    Serial.println(solar.getBatteryLevel());
    Serial.print("Charging: ");
    Serial.println(solar.isCharging() ? "Yes" : "No");
    Serial.print("Fast Charging: ");
    Serial.println(solar.isFastCharging() ? "Yes" : "No");
    Serial.print("Battery Temperature: ");
    Serial.println(solar.getBatteryTemperature());
  } else {
    Serial.println("Solar charger not connected.");
  }

  delay(1000);
}
