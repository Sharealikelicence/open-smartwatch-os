
#include "./apps/tools/wifi_scan.h"

#include "WiFi.h"

OswAppWiFiScan::OswAppWiFiScan(Stream* debugStream) {
    _debugStream = debugStream;
}

OswAppWiFiScan::OswAppWiFiScan(void) {
    _debugStream = &Serial;
}

void OswAppWiFiScan::setup(OswHal* hal) {
    try
    {
        _debugStream->println("Setting WiFi mode...");
        WiFi.mode(WIFI_STA);
        _debugStream->println("Disconnecting from existing APs...");
        WiFi.disconnect();
        delay(100);
    }
    catch(const std::exception& e)
    {
        _debugStream->print("Error: ");
        _debugStream->println(e.what());
        //std::cerr << e.what() << '\n';
    }
}

void OswAppWiFiScan::loop(OswHal* hal) {
    hal->gfx()->setTextSize(4);
    hal->gfx()->setTextMiddleAligned();
    hal->gfx()->setTextLeftAligned();
    hal->gfx()->setTextCursor(120 - hal->gfx()->getTextOfsetColumns(4), 120);
    _debugStream->println("Starting network scan...");
    int n = WiFi.scanNetworks();

    if (n == 0)
    {
        _debugStream->println("No networks found");
        hal->gfx()->print("No networks found");
    } else
    {
        hal->gfx()->print(n);
        hal->gfx()->println(" networks found:");

        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            _debugStream->print(i + 1);
            hal->gfx()->print(i + 1);
            _debugStream->print(": ");
            hal->gfx()->print(": ");
            _debugStream->print(WiFi.SSID(i));
            hal->gfx()->print(WiFi.SSID(i));
            _debugStream->print(" (");
            hal->gfx()->print(" (");
            _debugStream->print(WiFi.RSSI(i));
            hal->gfx()->print(WiFi.RSSI(i));
            _debugStream->print(")");
            hal->gfx()->print(")");
            _debugStream->println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            hal->gfx()->println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN)?" ":"*");
            delay(10);
        }
    }
    
    
    hal->requestFlush();
}

void OswAppWiFiScan::stop(OswHal* hal) {}