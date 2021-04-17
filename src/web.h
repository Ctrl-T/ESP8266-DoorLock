#ifndef WEB_H
#define WEB_H

#include "http.h"
#include "secrets.h"
// #include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
// #include <Ticker.h>

class WebClass {
  private:
    const char *SSID = WIFI_SSID;
    const char *PASSWORD = WIFI_PASSWORD;
    const char *HOST = REMOTE_HOST;
    const int PORT = REMOTE_PORT;
    // WiFiClient client;
    // Ticker tickerPulse;
    static void handleData(void *arg, AsyncClient *client, void *data,
                           size_t len);
    static void onConnect(void *arg, AsyncClient *client);
    static void onDisonnect(void *arg, AsyncClient *client);
    static void onError(void *arg, AsyncClient *client, err_t err);
    static void replyToServer(void *arg);
    AsyncClient client;

  public:
    bool cmdRcved;
    WebClass();
    void connectWifi();
    void connectServer();
    // bool readServer();
    int readSerial();
    // void sendPulse();
    bool rcvCmd();
};

extern WebClass Web;

#endif