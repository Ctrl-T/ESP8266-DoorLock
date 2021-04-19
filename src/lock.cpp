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
    // pos = servo.read();
    // rotateTo(LOCK_POS);
    // servo.detach();
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

    // int step = 0; // 每次转动的角度
    // step = (destPos > pos) ? 1 : -1;
    // // DEBUG_PRINTF("pos:%d, destpos:%d, step:%d\n", pos, destPos, step);
    // while ((destPos - pos) * step >= 0) { // 从当前位置开始一度一度转向目标角度
    //     pos += step;
    //     servo.write(pos);
    //     // DEBUG_PRINTF("%d ", pos);
    //     delay(15);
    // }
}

/**
 * @brief 关锁
 **/
void Lock::lockUp() {
    DEBUG_PRINTLN("LockUp...");
    rotateTo(LOCK_POS);
    locked = true;
    // servo.detach();
}

/**
 * @brief 开锁
 **/
void Lock::unLock() {
    if (!locked) {
        return;
    }
    // servo.attach(PIN_LOCK);
    DEBUG_PRINTLN("Unlock...");
    rotateTo(UNLOCK_POS);
    locked = false;
    tickerOpen.once_scheduled(3, std::bind(&Lock::lockUp, this));
}

bool Lock::isLocked() { return locked; }