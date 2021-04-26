#ifndef DISPLAY_H
#define DISPLAY_H

#include "SSD1306Wire.h"
#include "logoCPC.h"
#include "logoQingjin.h"
#include <Ticker.h>
#include <Wire.h>

enum DispState { idle, success, fail };

class Display {
  private:
    SSD1306Wire display;          // OLED实例
    DispState state;              // 当前状态
    const int pinRes;             // rest引脚
    Ticker tickerFrame;           // 帧变换的计时器
    Ticker tickerReverse;           // 帧变换的计时器
    int iFrame = 0;               // 帧计数
    int offsetArrow = 0;
    void dispIdle();
    void dispSuccess();
    void dispFail();
    void setReverse();
    void setNormal();

  public:
    Display(int pinSda, int pinScl, int pinRes);
    void init();
    void setState(DispState newState);
};

#endif