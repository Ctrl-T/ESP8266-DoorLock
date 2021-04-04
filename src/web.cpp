#include "web.h"
#include "http.h"

Web::Web() {
    // client.setTimeout(1000);
}

/**
 * @brief 连接wifi
 **/
void Web::connectWifi() {
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(SSID);

    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASSWORD);

    int trial = 0;
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
        ++trial;
        if (trial > 10) {
            Serial.println("fail to connect WiFi");
            return;
        }
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

/**
 * @brief 连接服务器
 **/
void Web::connectServer() {
    Serial.print("connecting to ");
    Serial.print(HOST);
    Serial.print(':');
    Serial.println(PORT);

    if (!client.connect(HOST, PORT)) {
        Serial.println("connection failed");
        Http::pushplus("尝试连接服务器失败");
        return;
    }

    Serial.println("sending hello msg to server");
    if (client.connected()) {
        client.keepAlive();
        client.print("Hello from ESP8266");
        Http::pushplus("成功连接服务器");
        // tickerPulse.attach_scheduled(60 * 10, std::bind(&Web::sendPulse, this));
    }
}

/**
 * @brief 检查来自服务器的命令
 * @retval 是否收到开锁命令
 **/
bool Web::readServer() {
    // Serial.println("reading from server..");
    if (WiFi.status() != WL_CONNECTED) { // make sure WiFi connected
        connectWifi();
    }
    if (!client.connected()) { // make sure TCP connected
        Http::pushplus("与服务器失去连接");
        connectServer();
    }
    if (!client.available()) { // check available data
        return false;
    }
    Serial.println("开始读取网络命令");
    String order = client.readStringUntil('\n');
    Http::pushplus((String("收到网络命令：") + order).c_str());
    Serial.print("receive order: ");
    Serial.println(order);
    if (order == "OPEN") {
        return true;
    }
    return false;
}

/**
 * @brief 检查来自串口的命令
 * @retval 串口收到的数字
 **/
int Web::readSerial() {
    int comInt = 0;
    if (Serial.available() > 0) {
        delay(20);
        comInt = Serial.parseInt();
        Serial.print("Input:");
        Serial.println(comInt);
    }
    return comInt;
}

/**
 * @brief 向服务器发心跳包
 **/
void Web::sendPulse() { client.print("Hello from ESP8266"); }