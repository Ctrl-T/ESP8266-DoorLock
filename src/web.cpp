#include "web.h"
#include "http.h"

WebClass::WebClass() { cmdRcved = false; }

/**
 * @brief 连接wifi
 **/
void WebClass::connectWifi() {
    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(SSID);

    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASSWORD);

    if (WiFi.waitForConnectResult(6000) != WL_CONNECTED) {
        Serial.println("fail to connect WiFi");
        return;
    }

    WiFi.setAutoReconnect(true);
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

/**
 * @brief 连接服务器
 **/
void WebClass::connectServer() {
    Serial.print("connecting to ");
    Serial.print(HOST);
    Serial.print(':');
    Serial.println(PORT);

    client.onData(&handleData, this);
    client.onConnect(&onConnect, &client);
    client.onDisconnect(&onDisonnect, this);
    client.onError(&onError, this);
    client.connect(HOST, PORT);
}

void WebClass::replyToServer(void *arg) {
    AsyncClient *client = reinterpret_cast<AsyncClient *>(arg);

    // send reply
    if (client->space() > 32 && client->canSend()) {
        client->write("Hello from ESP8266");
    }
}

void WebClass::handleData(void *arg, AsyncClient *client, void *data,
                          size_t len) {
    Serial.print("收到网络命令：");
    Serial.println((char *)data);
    // Http.pushplus("收到网络命令");
    // Http::pushplus((String("收到网络命令：") + (char *)data).c_str());
    if (strncmp((char *)data, "OPEN\n", len) == 0) {
        reinterpret_cast<WebClass *>(arg)->cmdRcved = true;
    }
}

void WebClass::onConnect(void *arg, AsyncClient *client) {
    client->keepAlive();
    replyToServer(client);
    Serial.println("成功连接服务器");
    // Http.pushplus("成功连接服务器");
}

void WebClass::onDisonnect(void *arg, AsyncClient *client) {
    Serial.println("与服务器的连接断开");
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
        Serial.print("Input:");
        Serial.println(comInt);
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

void WebClass::onError(void *arg, AsyncClient *client, err_t err) {
    Serial.println("与服务器的连接发生错误");
    WebClass *web = reinterpret_cast<WebClass *>(arg);
    client->connect(web->HOST, web->PORT);
}

WebClass Web;