#ifndef DISPLAY_H
#define DISPLAY_H

#include "OLEDDisplayUi.h"
#include "SSD1306Wire.h"
#include "logoCPC.h"
#include "logoQingjin.h"
#include <Ticker.h>
#include <Wire.h>

enum DispState : uint8_t { idle, success, fail };

class Display {
  private:
    SSD1306Wire display; // OLED实例
    OLEDDisplayUi ui;
    const int pinRes;     // rest引脚
    Ticker tickerReverse; // 帧变换的计时器
    static void dispIdle(OLEDDisplay *display, OLEDDisplayUiState *state,
                         int16_t x, int16_t y);
    static void dispSuccess(OLEDDisplay *display, OLEDDisplayUiState *state,
                            int16_t x, int16_t y);
    void dispFail();
    void setReverse();
    void setNormal();
    FrameCallback frames[2] = {dispIdle, dispSuccess};
    int frameCount = 2;
    DispState state;

  public:
    Display(int pinSda, int pinScl, int pinRes);
    void init();
    void setState(DispState newState);
    void update();
};

#endif