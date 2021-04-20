#include "SwitchSetting.h"

volatile bool isSwitchOn;
volatile int pinSwitch;

IRAM_ATTR void handleIntr() {
    isSwitchOn = (digitalRead(pinSwitch) == HIGH) ? true : false;
}

void setSwitchSettingPin(int pin) {
    pinSwitch = pin;
    pinMode(pinSwitch, INPUT);
    isSwitchOn = (digitalRead(pinSwitch) == HIGH) ? true : false;
    attachInterrupt(digitalPinToInterrupt(pinSwitch), handleIntr, CHANGE);
}
