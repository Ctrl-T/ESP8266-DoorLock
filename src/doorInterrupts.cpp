#include "doorInterrupts.h"

volatile bool isSwitchOn;
volatile bool isCmdOn;
volatile int pinSwitch;
volatile int pinCmd;

IRAM_ATTR void onSwitchIntr() {
    isSwitchOn = (digitalRead(pinSwitch) == HIGH) ? true : false;
}
IRAM_ATTR void onCmdIntr() {
    isCmdOn = (digitalRead(pinCmd) == HIGH) ? true : false;
}

void setSwitchSettingPin(int pin) {
    pinSwitch = pin;
    pinMode(pinSwitch, INPUT);
    isSwitchOn = (digitalRead(pinSwitch) == HIGH) ? true : false;
    attachInterrupt(digitalPinToInterrupt(pinSwitch), onSwitchIntr, CHANGE);
}
void setCmdIntrPin(int pin) {
    pinCmd = pin;
    pinMode(pinCmd, INPUT);
    isCmdOn = (digitalRead(pinCmd) == HIGH) ? true : false;
    attachInterrupt(digitalPinToInterrupt(pinCmd), onCmdIntr, CHANGE);
}
