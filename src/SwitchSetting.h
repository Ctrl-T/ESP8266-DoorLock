#ifndef SWITCH_SETTING_H
#define SWITCH_SETTING_H
#include <Arduino.h>

extern volatile bool isSwitchOn;
extern volatile int pinSwitch;

void handleIntr();
void setSwitchSettingPin(int pin);

#endif