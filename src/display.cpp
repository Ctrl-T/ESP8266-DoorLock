#include "display.h"
Display::Display(int pinSda, int pinScl, int pinRes)
    : display(0x3c, pinSda, pinScl), ui(&display), pinRes(pinRes), state(idle) {
}

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
    ui.setTargetFPS(30);
    ui.setFrameAnimation(SLIDE_RIGHT);
    ui.setFrames(frames, frameCount);
    ui.disableAutoTransition();
    ui.disableAllIndicators();
    ui.setTimePerTransition(200);
    ui.init();
    display.flipScreenVertically();
    setNormal();
}

/**
 * @brief 显示空闲时图案
 **/
void Display::dispIdle(OLEDDisplay *display, OLEDDisplayUiState *state,
                       int16_t x, int16_t y) {
    static int offsetArrow = 0;
    // arrows
    for (int i = 0; i < 3; ++i) {
        display->drawXbm(35 - i * 20 - offsetArrow + x, 15 + y, arrowWidth,
                         arrowHeight, arrowLBits);
        display->drawXbm(69 + i * 20 + offsetArrow + x, 15 + y, arrowWidth,
                         arrowHeight, arrowRBits);
    }
    // mask
    display->setColor(BLACK);
    display->drawXbm(26 + x, 15 + y, maskWidth, maskHeight, maskBits);
    display->setColor(WHITE);
    // CPC logo
    display->drawXbm(42 + x, 9 + y, logoCPCWidth, logoCPCHeight, logoCPCBits);
    // horizontal lines
    for (int i = 0; i < 3; ++i) {
        display->drawHorizontalLine(0 + x, 4 + i + y, 128);
        display->drawHorizontalLine(0 + x, 57 + i + y, 128);
    }
    offsetArrow = (offsetArrow + 1) % 20;
}

/**
 * @brief 显示开锁时图案
 **/
void Display::dispSuccess(OLEDDisplay *display, OLEDDisplayUiState *state,
                          int16_t x, int16_t y) {
    display->drawXbm(x, y, QingjinLogoWidth, QingjinLogoHeight,
                     QingjinLogoBits);
}

/**
 * @brief 显示失败时图案
 **/
void Display::dispFail() {}

/**
 * @brief 设置图案状态
 **/
void Display::setState(DispState newState) {
    if (newState == state) {
        return;
    }
    state = newState;
    ui.transitionToFrame(static_cast<uint8_t>(newState));
    // ui.switchToFrame(newState);
}

/**
 * @brief 使图案反相显示
 **/
void Display::setReverse() {
    display.invertDisplay();
    tickerReverse.once_scheduled(60, std::bind(&Display::setNormal, this));
}

/**
 * @brief 使图案正常显示
 **/
void Display::setNormal() {
    display.normalDisplay();
    tickerReverse.once_scheduled(60, std::bind(&Display::setReverse, this));
}

void Display::update() { ui.update(); }