#ifndef LOCK_H
#define LOCK_H

#include <Servo.h>
#include <Ticker.h>
#include "pins.h"

#define LOCK_POS 45   // 关锁时所处位置
#define UNLOCK_POS 90 // 开锁后所处位置

class Lock {
  private:
    Servo servo;
    int pos;
    void rotateTo(int);
    Ticker tickerOpen;

  public:
    Lock();
    void lockUp();
    void unLock();
    void init();
};

#endif