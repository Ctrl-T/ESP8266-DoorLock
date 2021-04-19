#ifndef LOCK_H
#define LOCK_H

#include "config.h"
#include <Servo.h>
#include <Ticker.h>

class Lock {
  private:
    Servo servo;
    void rotateTo(int);
    Ticker tickerOpen;
    bool locked;
    const int LOCK_POS = 90;   // 关锁时所处位置
    const int UNLOCK_POS = 50; // 开锁后所处位置
    const int pinLock;

  public:
    Lock(int pinLock);
    void lockUp();
    void unLock();
    void init();
    bool isLocked();
};

#endif