#include "display.h"
Display::Display(int pinSda, int pinScl, int pinRes)
    : display(0x3c, pinSda, pinScl), pinRes(pinRes), CPCx(0) {}

void Display::init() {
    // reset
    pinMode(pinRes, OUTPUT);
    digitalWrite(pinRes, LOW);
    delay(200);
    digitalWrite(pinRes, HIGH);
    // init oled
    display.init();
    display.flipScreenVertically();
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
    display.clear();
    switch (state) {
    case idle:
        // display.drawXbm(34, 2, CPCLogoWidth, CPCLogoHeight, CPCLogoBits);
        display.drawXbm(CPCx/10 - 60, 2, CPCLogoWidth, CPCLogoHeight, CPCLogoBits);
        CPCx++;
        if (CPCx > 1880) {
            CPCx = 0;
        }
        break;
    case success:
        display.drawXbm(0, 0, QingjinLogoWidth, QingjinLogoHeight,
                        QingjinLogoBits);
        break;
    case fail:
        break;
    default:
        break;
    }
    display.display();
}