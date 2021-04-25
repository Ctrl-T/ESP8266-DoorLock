#include "display.h"
Display::Display(int pinSda, int pinScl, int pinRes)
    : display(0x3c, pinSda, pinScl), pinRes(pinRes) {}

/**
 * @brief 初始化OLED
 **/
void Display::init() {
    // reset
    pinMode(pinRes, OUTPUT);
    digitalWrite(pinRes, LOW);
    delay(200);
    digitalWrite(pinRes, HIGH);
    // init oled
    display.init();
    display.flipScreenVertically();
    dispIdle();
}

/**
 * @brief 显示空闲时图案
 **/
void Display::dispIdle() {
    if (state == idle) {
        display.clear();
        clearFrame();
        switch (iFrame) {
        case 0: // ☭
            addFrame(logoCPCBits[0]);
            break;
        case 1: // <☭>
            addFrame(logoCPCBits[0]);
            addFrame(logoCPCBits[1]);
            break;
        case 2: // <<☭>>
            addFrame(logoCPCBits[0]);
            addFrame(logoCPCBits[1]);
            addFrame(logoCPCBits[2]);
            break;
        case 3: // < ☭ >
            addFrame(logoCPCBits[0]);
            addFrame(logoCPCBits[2]);
            break;
        default:
            break;
        }
        display.drawXbm(0, 0, logoCPCWidth, logoCPCHeight, frame);
        display.display();
        iFrame = (iFrame + 1) % 4;
    }
    tickerFrame.once_ms_scheduled(300, std::bind(&Display::dispIdle, this));
}

/**
 * @brief 显示开锁时图案
 **/
void Display::dispSuccess() {
    display.clear();
    display.drawXbm(0, 0, QingjinLogoWidth, QingjinLogoHeight, QingjinLogoBits);
    display.display();
}

/**
 * @brief 显示失败时图案
 **/
void Display::dispFail() {}

/**
 * @brief 设置图案状态
 **/
void Display::setState(DispState newState) {
    state = newState;
    if (state == success) {
        dispSuccess();
    }
}

/**
 * @brief 清空图案缓冲区
 **/
void Display::clearFrame() { memset(frame, 0, FRAME_LEN); }

/**
 * @brief 往缓冲区上叠加图案（按位或）
 **/
void Display::addFrame(const uint8 *newFrame) {
    for (int i = 0; i < FRAME_LEN; ++i) {
        frame[i] |= newFrame[i];
    }
}