#ifndef DOOR_INTERRUPTS_H
#define DOOR_INTERRUPTS_H
#include <Arduino.h>

extern volatile bool isSwitchOn;
extern volatile bool isCmdOn;

void onSwitchIntr();
void onCmdIntr();
void setSwitchSettingPin(int pin);
void setCmdIntrPin(int pin);

#endif