#include "finger.h"
#include "http.h"
#include "lock.h"
#include "nfc.h"
#include "web.h"
#include <Arduino.h>
#include <Ticker.h>

Web web;
Lock lock;
NFC nfc;
Ticker tickerPulse;
Finger finger;

void setup() {
    Serial.begin(9600);
    finger.init();
    lock.init();
    web.connectWifi();
    web.connectServer();
    // tickerPulse.attach_scheduled(60 * 30, Http::pulse);
}

void loop() {
    if (lock.isLocked()) {
        if (finger.readFinger() || nfc.readCardID() || web.readServer()) {
            lock.unLock();
        }
    }
}
