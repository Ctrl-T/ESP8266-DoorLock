#ifndef LOCK_H
#define LOCK_H

#include "pins.h"
#include <Servo.h>
#include <Ticker.h>

#define LOCK_POS 45   // 关锁时所处位置
#define UNLOCK_POS 90 // 开锁后所处位置

class Lock {
  private:
    Servo servo;
    int pos;
    void rotateTo(int);
    Ticker tickerOpen;
    bool locked;

  public:
    Lock();
    void lockUp();
    void unLock();
    void init();
    bool isLocked();
};

#endif