#ifndef HTTP_H
#define HTTP_H

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

class Http {
  private:
    static HTTPClient client;
    static WiFiClient wifi;
    static constexpr const char *HOST = "http://pushplus.plus";
    static constexpr const char *URL = "/send";
    static constexpr const char *TOKEN = "d97a25a23cd7480599fc8a4836a0c44d";

  public:
    Http(/* args */);
    static void pushplus(const char *title,
                         const char *content = "来自门锁的消息");
    static String urlEncode(String str);
    static void pulse();
};

#endif