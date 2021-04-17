#ifndef DISPLAY_H
#define DISPLAY_H

#include "OLED.h"
#include <Wire.h>
enum DispState { idle, success, fail };

class Display {
  private:
    OLED oled;
    DispState state;

  public:
    Display(int pinSda, int pinScl);
    void init();
    void update();
    void dispIdle();
    void dispSuccess();
    void dispFail();
};

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

#endif