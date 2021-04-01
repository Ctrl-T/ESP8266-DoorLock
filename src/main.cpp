#include "lock.h"
#include "nfc.h"
#include "web.h"
#include "http.h"
#include <Arduino.h>
#include <Ticker.h>

Web web;
Lock lock;
NFC nfc;
Ticker tickerPulse;

void setup() {
    Serial.begin(9600);
    lock.init();
    web.connectWifi();
    web.connectServer();
    tickerPulse.attach_scheduled(60 * 30, Http::pulse);
}

void loop() {
    // 是否有网络开锁消息
    int orderCode = web.readServer();
    // 是否有NFC开锁消息
    if (nfc.readCardID()) {
        orderCode = 1;
    }
    // 根据命令控制锁
    switch (orderCode) {
    case 1:
        lock.unLock();
        break;
    case 2:
        lock.lockUp();
        break;
    default:
        break;
    }
}
