#ifndef WEB_H
#define WEB_H

#include "http.h"
#include "config.h"
#include <ESPAsyncTCP.h>
// #include <Ticker.h>

class WebClass {
  private:
    const char *SSID = WIFI_SSID;
    const char *PASSWORD = WIFI_PASSWORD;
    const char *HOST = REMOTE_HOST;
    const int PORT = REMOTE_PORT;
    // Ticker tickerPulse;
    static void handleData(void *arg, AsyncClient *client, void *data,
                           size_t len);
    static void onConnect(void *arg, AsyncClient *client);
    static void onDisonnect(void *arg, AsyncClient *client);
    static void onTimeout(void *arg, AsyncClient *client, u32_t time);
    static void replyToServer(void *arg);
    AsyncClient client;
    bool cmdRcved;

  public:
    WebClass();
    void connectWifi();
    void connectServer();
    int readSerial();
    // void sendPulse();
    bool rcvCmd();
};

extern WebClass Web;

#endif