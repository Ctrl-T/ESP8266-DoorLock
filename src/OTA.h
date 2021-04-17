#ifndef OTA_H
#define OTA_H

#include "secrets.h"
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

class OTAClass {
  private:
    const char *host = WEBUPDATE_HOST;
    const char *update_username = "admin";
    const char *update_password = "admin";

    ESP8266WebServer server;
    const char *serverIndex =
        "<form method='POST' action='/update' enctype='multipart/form-data'>"
        "<input type='file' name='update'>"
        "<input type='submit' value='Update'></form>";

  public:
    OTAClass();
    void init();
    void update();
};
extern OTAClass OTA;
#endif