#ifndef OTA_H
#define OTA_H

#include "config.h"
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

class OTAClass {
  private:
    const char *host = WEBUPDATE_HOST;
    const char *update_username = "admin";
    const char *update_password = "admin";

    ESP8266WebServer server;
    const char *serverIndex =
        "<body style='text-align: center;'>"
        "<h2>智能门锁 OTA</h2>"
        "<form method='POST' action='/update' enctype='multipart/form-data'>"
        "<input type='file' name='update'>"
        "<input type='submit' value='更新'>"
        "</form>";

  public:
    OTAClass();
    void init();
    void update();
};
extern OTAClass OTA;
#endif