#ifndef WEB_H
#define WEB_H

#include "OTA.h"
#include "config.h"
#include "http.h"
#include "opener.h"
#include "WString.h"
#include <ESPAsyncTCP.h>
// #include <Ticker.h>

class WebClass : public Opener {
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
    bool cmdOpenRcvd, cmdLogRcvd;
    WiFiEventHandler staConnectedHandler;

  public:
    WebClass();
    void init();
    void connectWifi();
    void connectServer();
    int readSerial();
    // void sendPulse();
    bool checkOpenInstr();
    bool checkLogInstr();
    void writeLogs(String logs[], uint size);
};

extern WebClass Web;

#endif