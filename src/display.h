#ifndef DISPLAY_H
#define DISPLAY_H

#include <Wire.h>
#include "OLED.h"
enum DispState { idle, success, fail };

class Display {
  private:
    OLED oled;
    DispState state;
    const int pinRes;

  public:
    Display(int pinSda, int pinScl, int pinRes);
    void init();
    void update();
    void dispIdle();
    void dispSuccess();
    void dispFail();
};



#endif