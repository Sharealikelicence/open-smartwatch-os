#ifndef OSW_APP_WIFI_SCAN_H
#define OSW_APP_WIFI_SCAN_H

#include <osw_hal.h>
#include <Arduino.h>

#include "osw_app.h"

class OswAppWiFiScan : public OswApp {
 public:
  OswAppWiFiScan(void);
  OswAppWiFiScan(Stream* debugStream);
  void setup(OswHal * hal);
  void loop(OswHal* hal);
  void stop(OswHal* hal);
  ~OswAppWiFiScan(){};

 private:
  Stream* _debugStream;
};

#endif