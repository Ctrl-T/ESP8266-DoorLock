#ifndef DISPLAY_H
#define DISPLAY_H

#include "SSD1306Wire.h"
#include "logoCPC.h"
#include "logoQingjin.h"
#include <Ticker.h>
#include <Wire.h>

#define FRAME_LEN 1024
enum DispState { idle, success, fail };

class Display {
  private:
    SSD1306Wire display;          // OLED实例
    DispState state;              // 当前状态
    const int pinRes;             // rest引脚
    Ticker tickerFrame;           // 帧变换的计时器
    int iFrame = 0;               // 帧计数
    uint8 frame[FRAME_LEN] = {0}; // 缓冲区
    const uint8 *logoCPCBits[3] = {logoCPC0Bits, logoCPC1Bits,
                                   logoCPC2Bits}; // 动画帧
    void clearFrame();
    void addFrame(const uint8 *newFrame);
    void dispIdle();
    void dispSuccess();
    void dispFail();

  public:
    Display(int pinSda, int pinScl, int pinRes);
    void init();
    void setState(DispState newState);
};

#endif