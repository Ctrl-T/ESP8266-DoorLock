#include "http.h"
HttpClass::HttpClass(/* args */) {}

/**
 * @brief 向pushplus推送消息
 **/
void HttpClass::pushplus(const char *content, const char *title) {
    if (title == NULL) {
        title = content;
    }
    client.begin(wifi, String(URL) + "?token=" + TOKEN + "&title=" +
                           urlEncode(title) + "&content=" + urlEncode(content));
    int httpResponseCode = client.GET();
    Serial.println(client.getString());
    if (httpResponseCode != 200) {
        Serial.println("fail when sending msg to pushplus");
        Serial.printf("http code: %d\n", httpResponseCode);
    }
}

/**
 * @brief 文字编码进URL
 **/
String HttpClass::urlEncode(String str) {
    String encodedString = "";
    char c;
    char code0;
    char code1;
    for (uint i = 0; i < str.length(); i++) {
        c = str.charAt(i);
        if (c == ' ') {
            encodedString += '+';
        } else if (isalnum(c)) {
            encodedString += c;
        } else {
            code1 = (c & 0xf) + '0';
            if ((c & 0xf) > 9) {
                code1 = (c & 0xf) - 10 + 'A';
            }
            c = (c >> 4) & 0xf;
            code0 = c + '0';
            if (c > 9) {
                code0 = c - 10 + 'A';
            }
            encodedString += '%';
            encodedString += code0;
            encodedString += code1;
        }
        yield();
    }
    return encodedString;
}

/**
 * @brief 连续工作时间推送
 **/
void HttpClass::pulse() {
    String minute = String(millis() / (1000 * 60));
    String msg = String("已连续工作 ") + minute + " 分钟";
    pushplus(msg.c_str());
}

HttpClass Http;