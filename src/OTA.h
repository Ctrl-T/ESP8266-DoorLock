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
        "<body style='text-align: center;'>"
        "<title>智能门锁 - OTA</title>"
        "<h2>智能门锁更新系统</h2>"
        "<iframe name='dummyFrame' style='display:none;' onload=' let ret = this.contentWindow.document.querySelector(\"body\").innerText;if (ret!=\"\") {alert(ret); document.btn.disabled = false; document.btn.value=\"更新\"}'></iframe>"
        "<form method='POST' action='/update' enctype='multipart/form-data' target='dummyFrame' onsubmit='document.btn = this.querySelector(\"input[type=submit]\"); btn.disabled = true; btn.value=\"正在上传\"'>"
        "<input type='file' name='update' accept='.bin'>"
        "<input type='submit' value='更新'>"
        "</form>";

  public:
    OTAClass();
    void init();
    void update();
};
extern OTAClass OTA;
#endif