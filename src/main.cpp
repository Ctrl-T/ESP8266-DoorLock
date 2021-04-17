#include "OTA.h"
#include "finger.h"
#include "lock.h"
#include "nfc.h"
#include "pins.h"
#include "web.h"
#include <Arduino.h>

Lock lock(PIN_LOCK, PIN_LED);
NFC nfc;
Finger finger(PIN_FNGR_RX, PIN_FNGR_TX);

void setup() {
    Serial.begin(9600);
    finger.init();
    lock.init();
    Web.connectWifi();
    Web.connectServer();
    OTA.init();
}

void loop() {
    if (lock.isLocked()) {
        if (finger.readFinger() || nfc.readCardID() || Web.rcvCmd()) {
            lock.unLock();
        }
    }
    OTA.update();
}
