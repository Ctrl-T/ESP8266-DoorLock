#ifndef OTA_H
#define OTA_H

#include "config.h"
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

class OTAClass {
  private:
    const char *host = WEBUPDATE_HOST;

    ESP8266WebServer server;
    const char *serverIndex =
        "<body>"
        "<link rel='stylesheet' href='http://door.steelblue.cn/css/ota-style.css'>"
        "<title>智能门锁 - OTA</title>"
        "<h1>智能门锁更新系统</h1>"
        "<div class='line'></div>"
        "<iframe name='dummyFrame' onload='onUploadOk(this)'></iframe>"
        "<form method='POST' action='/update' enctype='multipart/form-data' target='dummyFrame' onsubmit='onUpload(this)'>"
        "<input type='file' name='update' accept='.bin'>"
        "<input type='submit' value='更新'>"
        "</form>"
        "<script src='http://door.steelblue.cn/js/ota.js'></script>";

  public:
    OTAClass();
    void init();
    void update();
};
extern OTAClass OTA;
#endif