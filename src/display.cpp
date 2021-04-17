#include "display.h"
Display::Display(int pinSda, int pinScl) : oled(pinSda, pinScl) {}

void Display::init() {
    oled.begin();
}