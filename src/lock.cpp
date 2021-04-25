#include "lock.h"

Lock::Lock(int pinLock) : pinLock(pinLock) {
    locked = true;
}

/**
 * @brief 初始化为锁门状态
 **/
void Lock::init() {
    servo.attach(pinLock);
    lockUp();
}

/**
 * @brief 旋转到目标位置
 **/
void Lock::rotateTo(int destPos) {
    if (destPos > 180 || destPos < 0) {
        return;
    }
    servo.write(destPos);
    delay(300);
}

/**
 * @brief 关锁
 **/
void Lock::lockUp() {
    DEBUG_PRINTLN("LockUp...");
    rotateTo(LOCK_POS);
    locked = true;
}

/**
 * @brief 开锁
 **/
void Lock::unLock() {
    if (!locked) {
        return;
    }
    DEBUG_PRINTLN("Unlock...");
    rotateTo(UNLOCK_POS);
    locked = false;
    tickerOpen.once_scheduled(3, std::bind(&Lock::lockUp, this));
}

bool Lock::isLocked() { return locked; }