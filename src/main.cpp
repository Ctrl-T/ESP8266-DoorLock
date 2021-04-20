// #include "OTA.h"
#include "SwitchSetting.h"
#include "config.h"
#include "finger.h"
#include "lock.h"
#include "nfc.h"
#include "web.h"
// #include "display.h"
#include <Arduino.h>

Lock lock(PIN_LOCK);
NFC nfc;
Finger finger(PIN_FNGR_RX, PIN_FNGR_TX);
// Display display(PIN_OLED_SDA, PIN_OLED_SCL, PIN_OLED_RES);

void onSetChange() {}

void setup() {
    Serial.begin(9600);
    Web.init();
    // display.init();
    // display.dispIdle();
    finger.init();
    lock.init();
    setSwitchSettingPin(PIN_SETTING);
}

void loop() {
    if (lock.isLocked()) {
        if (nfc.readCardID() || Web.rcvCmd() || finger.readFinger()) {
            lock.unLock();
        }
    }
    if (isSwitchOn) {
        OTA.update();
    }
}
