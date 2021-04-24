#ifndef DISPLAY_H
#define DISPLAY_H

#include <Wire.h>
#include "SSD1306Wire.h"
#include "logoCPC.h"
#include "logoQingjin.h"
enum DispState { idle, success, fail };

class Display {
  private:
    SSD1306Wire display;
    DispState state;
    const int pinRes;
    int CPCx;

  public:
    Display(int pinSda, int pinScl, int pinRes);
    void init();
    void update();
    void dispIdle();
    void dispSuccess();
    void dispFail();
};



#endif