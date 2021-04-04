#ifndef WEB_H
#define WEB_H

#include <ESP8266WiFi.h>
#include <Ticker.h>
#include "http.h"

class Web {
  private:
    const char *SSID = "飞机杯里泡枸杞_2.4G";
    const char *PASSWORD = "T1620183";
    const char *HOST = "door.steelblue.cn";
    // const char *HOST = "10.0.0.222";
    const int PORT = 20183;
    WiFiClient client;
    Ticker tickerPulse;

  public:
    Web(/* args */);
    void connectWifi();
    void connectServer();
    bool readServer();
    int readSerial();
    void sendPulse();
};

#endif