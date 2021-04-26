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
    setNormal();
}

// /**
//  * @brief 显示空闲时图案
//  **/
// void Display::dispIdle() {
//     if (state == idle) {
//         display.clear();
//         clearFrame();
//         switch (iFrame) {
//         case 0: // ☭
//             addFrame(logoCPCBits[0]);
//             break;
//         case 1: // <☭>
//             addFrame(logoCPCBits[0]);
//             addFrame(logoCPCBits[1]);
//             break;
//         case 2: // <<☭>>
//             addFrame(logoCPCBits[0]);
//             addFrame(logoCPCBits[1]);
//             addFrame(logoCPCBits[2]);
//             break;
//         case 3: // < ☭ >
//             addFrame(logoCPCBits[0]);
//             addFrame(logoCPCBits[2]);
//             break;
//         default:
//             break;
//         }
//         display.drawXbm(0, 0, logoCPCWidth, logoCPCHeight, frame);
//         display.display();
//         iFrame = (iFrame + 1) % 4;
//     }
//     tickerFrame.once_ms_scheduled(300, std::bind(&Display::dispIdle, this));
// }
/**
 * @brief 显示空闲时图案
 **/
void Display::dispIdle() {
    if (state == idle) {
        display.clear();
        // arrows
        for (int i = 0; i < 3; ++i) {
            display.drawXbm(35 - i * 20 - offsetArrow, 15, arrowWidth,
                            arrowHeight, arrowLBits);
            display.drawXbm(69 + i * 20 + offsetArrow, 15, arrowWidth,
                            arrowHeight, arrowRBits);
        }
        // mask
        display.setColor(BLACK);
        display.fillRect(39, 15, 50, 33);
        display.drawXbm(23, 15, arrowWidth, arrowHeight, arrowLBits);
        display.drawXbm(31, 15, arrowWidth, arrowHeight, arrowLBits);
        display.drawXbm(73, 15, arrowWidth, arrowHeight, arrowRBits);
        display.drawXbm(81, 15, arrowWidth, arrowHeight, arrowRBits);
        display.setColor(WHITE);
        // CPC logo
        display.drawXbm(42, 10, logoCPCWidth, logoCPCHeight, logoCPCBits);
        // horizontal lines
        for (int i = 0; i < 3; ++i) {
            display.drawHorizontalLine(0, 4 + i, 128);
            display.drawHorizontalLine(0, 57 + i, 128);
        }
        display.display();
        offsetArrow = (offsetArrow + 1) % 20;
    }
    tickerFrame.once_ms_scheduled(30, std::bind(&Display::dispIdle, this));
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