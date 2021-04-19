#include "display.h"
Display::Display(int pinSda, int pinScl, int pinRes) : oled(pinSda, pinScl), pinRes(pinRes) {}

void Display::init() {
    // reset
    pinMode(pinRes, OUTPUT);
    digitalWrite(pinRes, LOW);
    delay(200);
    digitalWrite(pinRes, HIGH);
    // init oled
    oled.begin();
    oled.on();
    oled.print("Hello");
}

void Display::dispIdle() {
    state = idle;
    update();
}
void Display::dispSuccess() {
    state = success;
    update();
}
void Display::dispFail() {
    state = fail;
    update();
}

void Display::update() {
    oled.clear();
    switch (state) {
    case idle:
        oled.print("Hello!", 3, 5);
        break;
    case success:
        oled.print("Welcome!", 2, 4);
        oled.print("PUSH", 4, 6);
        break;
    case fail:
        oled.print("Access denied!", 3, 1);
        break;
    default:
        break;
    }
}