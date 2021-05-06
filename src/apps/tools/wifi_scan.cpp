
#include "./apps/tools/wifi_scan.h"

#include "WiFi.h"

OswAppWiFiScan::OswAppWiFiScan(void) {
    debugStream = &Serial;
}

OswAppWiFiScan::OswAppWiFiScan(Stream* debugStream) {
    _debugStream = debugStream;
}

void OswAppWifiScan::setup(OswHal* hal) {
    try
    {
        /* code */
    }
    catch()
    {
        
    }
    
}

void OswAppWifiScan::loop(OswHal* hal) {}

void OswAppWifiScan::stop(OswHal* hal) {}