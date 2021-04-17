#ifndef LOCK_H
#define LOCK_H

#include "pins.h"
#include <Servo.h>
#include <Ticker.h>

class Lock {
  private:
    Servo servo;
    int pos;
    void rotateTo(int);
    Ticker tickerOpen;
    bool locked;
    const int LOCK_POS = 45;   // 关锁时所处位置
    const int UNLOCK_POS = 90; // 开锁后所处位置
    const int pinLock, pinLed;

  public:
    Lock(int pinLock, int pinLed);
    void lockUp();
    void unLock();
    void init();
    bool isLocked();
};

#endif