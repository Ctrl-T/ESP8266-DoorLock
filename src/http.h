#ifndef HTTP_H
#define HTTP_H

#include "config.h"
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

class HttpClass {
  private:
    HTTPClient client;
    WiFiClient wifi;
    const char *URL = PUSHPLUS_URL;
    const char *TOKEN = PUSHPLUS_TOKEN;

  public:
    HttpClass(/* args */);
    void pushplus(const char *title,
                         const char *content = "来自门锁的消息");
    String urlEncode(String str);
    void pulse();
};

extern HttpClass Http;
#endif