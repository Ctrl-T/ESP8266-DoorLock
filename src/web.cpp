#include "web.h"
#include "http.h"

WebClass::WebClass() { cmdRcved = false; }

void WebClass::init() { connectWifi(); }

/**
 * @brief 连接wifi
 **/
void WebClass::connectWifi() {
    DEBUG_PRINTLN();
    DEBUG_PRINTLN();
    DEBUG_PRINT("Connecting to ");
    DEBUG_PRINTLN(SSID);

    WiFi.mode(WIFI_STA);
    staConnectedHandler = WiFi.onStationModeGotIP(
        [&](const WiFiEventStationModeGotIP &event) {
            Serial.print("WiFi connected, IP: ");
            Serial.println(WiFi.localIP());
            connectServer();
            OTA.init();
        });
    WiFi.begin(SSID, PASSWORD);
    WiFi.setAutoReconnect(true);
    return;
}

/**
 * @brief 连接服务器
 **/
void WebClass::connectServer() {
    DEBUG_PRINT("connecting to ");
    DEBUG_PRINT(HOST);
    DEBUG_PRINT(':');
    DEBUG_PRINTLN(PORT);

    client.onData(&handleData, this);
    client.onConnect(&onConnect, &client);
    client.onDisconnect(&onDisonnect, this);
    client.onTimeout(&onTimeout, this);
    client.connect(HOST, PORT);
}

/**
 * @brief 接收数据回调函数
 **/
void WebClass::handleData(void *arg, AsyncClient *client, void *data,
                          size_t len) {
    DEBUG_PRINT("收到网络命令：");
    DEBUG_PRINTLN((char *)data);
    // Http::pushplus((String("收到网络命令：") + (char *)data).c_str());
    if (strncmp((char *)data, "OPEN\n", len) == 0) {
        reinterpret_cast<WebClass *>(arg)->cmdRcved = true;
    }
}

/**
 * @brief 连接成功回调函数
 **/
void WebClass::onConnect(void *arg, AsyncClient *client) {
    client->keepAlive(10, 5, 3);
    // 发送握手信号
    if (client->space() > 32 && client->canSend()) {
        client->write("Hello from ESP8266");
    }
    DEBUG_PRINTLN("成功连接服务器");
    // Http.pushplus("成功连接服务器");
}

/**
 * @brief 连接断开回调函数
 **/
void WebClass::onDisonnect(void *arg, AsyncClient *client) {
    DEBUG_PRINTLN("与服务器的连接断开");
    WebClass *web = reinterpret_cast<WebClass *>(arg);
    client->connect(web->HOST, web->PORT);
}

/**
 * @brief 连接超时回调函数
 **/
void WebClass::onTimeout(void *arg, AsyncClient *client, u32_t time) {
    DEBUG_PRINTLN("服务器连接超时");
    WebClass *web = reinterpret_cast<WebClass *>(arg);
    client->connect(web->HOST, web->PORT);
}

/**
 * @brief 检查来自串口的命令
 * @retval 串口收到的数字
 **/
int WebClass::readSerial() {
    int comInt = 0;
    if (Serial.available() > 0) {
        delay(20);
        comInt = Serial.parseInt();
        DEBUG_PRINT("Input:");
        DEBUG_PRINTLN(comInt);
    }
    return comInt;
}

/**
 * @brief 读取网络命令
 * @retval 是否收到开锁信号
 **/
bool WebClass::rcvCmd() {
    if (cmdRcved) {
        cmdRcved = false;
        return true;
    }
    return false;
}

WebClass Web;