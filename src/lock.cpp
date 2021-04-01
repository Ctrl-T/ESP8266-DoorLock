#include "lock.h"

Lock::Lock() {}

/**
 * 初始化为锁门状态
 **/
void Lock::init() {
    servo.attach(LOCK_PORT);
    pos = servo.read();
    rotateTo(LOCK_POS);
    servo.detach();
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);
}

/**
 * 旋转到目标位置
 **/
void Lock::rotateTo(int destPos) {
    if (destPos > 180 || destPos < 0 || destPos == pos) {
        return;
    }
    int step = 0; // 每次转动的角度
    step = (destPos > pos) ? 1 : -1;
    // Serial.printf("pos:%d, destpos:%d, step:%d\n", pos, destPos, step);
    while ((destPos - pos) * step >= 0) { // 从当前位置开始一度一度转向目标角度
        pos += step;
        servo.write(pos);
        // Serial.printf("%d ", pos);
        delay(15);
    }
}

/**
 * 关锁
 **/
void Lock::lockUp() {
    Serial.println("LockUp...");
    digitalWrite(LED_PIN, LOW);
    rotateTo(LOCK_POS);
    servo.detach();
}

/**
 * 开锁
 **/
void Lock::unLock() {
    servo.attach(LOCK_PORT);
    Serial.println("Unlock...");
    digitalWrite(LED_PIN, HIGH);
    rotateTo(UNLOCK_POS);
    tickerOpen.once_scheduled(3, std::bind(&Lock::lockUp, this));
}
