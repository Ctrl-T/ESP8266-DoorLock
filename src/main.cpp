#include "OTA.h"
#include "config.h"
#include "display.h"
#include "doorInterrupts.h"
#include "finger.h"
#include "lock.h"
#include "nfc.h"
#include "web.h"
#include <Arduino.h>

Lock lock(PIN_LOCK);
NFC nfc;
Finger finger(PIN_FNGR_RX, PIN_FNGR_TX);
Display display(PIN_OLED_SDA, PIN_OLED_SCL, PIN_OLED_RES);

void setup() {
    Serial.begin(9600);
    Web.init();
    display.init();
    finger.init();
    lock.init();
    setSwitchSettingPin(PIN_SETTING);
    setCmdIntrPin(PIN_CMD_INTR);
}

void loop() {
    // 开锁
    if (lock.isLocked()) {
        display.setState(DispState::idle);
        if ((isCmdOn && finger.checkOpenInstr()) || nfc.checkOpenInstr() ||
            Web.checkOpenInstr()) {
            display.setState(DispState::success);
            lock.unLock();
        }
    }
    display.update();
    // 发送日志
    if (Web.checkLogInstr()) {
        String logs[] = {finger.getLog(), nfc.getLog(), Web.getLog()};
        Web.writeLogs(logs, 3);
    }
    // OTA
    if (isSwitchOn) {
        OTA.update();
    }
}
