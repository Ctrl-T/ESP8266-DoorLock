#include "finger.h"

Finger::Finger(/* args */) : serialFinger(PIN_FNGR_RX, PIN_FNGR_TX) {}

void Finger::init() { serialFinger.begin(115200); }
/**
 * @brief  根据枚举值的不同发送不同的指令给指纹模块
 * @param  cmd 指定命令 @ref Command_t
 * @retval None
 */
void Finger::sendCmd(Command_t cmd) {
    serialFinger.write(CMD_DATA[cmd], 26);
    /* 等待指纹模块返回26个字节应答数据 */
    serialFinger.readBytes(recvBuff, 26);
}

/**
 * @brief  尝试指纹解锁
 * @retval None
 */
bool Finger::readFinger() {
    /* 指示灯灭, 阻塞等待指纹模块上有手指按下 */
    sendCmd(CMD_LED_ALL_OFF);
    sendCmd(CMD_FINGER_DETECT);
    if (recvBuff[10] != 1) {
        Serial.println("无指纹按下");
        return false;
    }
    sendCmd(CMD_GET_IMAGE);
    if (recvBuff[8] != 0x00) {
        Serial.println("获取指纹失败");
        return false;
    }

    /* 生成指纹特征并验证是否匹配已录入的指纹 */
    sendCmd(CMD_GENERATE_0);
    sendCmd(CMD_SEARCH_FINGERPRINT);
    if (recvBuff[6] == 0x05 && recvBuff[10] > 0) {
        /* 绿灯亮，表示指纹匹配或者指纹录入完成，控制继电器开门 */
        Serial.println("指纹比对成功");
        sendCmd(CMD_LED_GREEN_ON);
        return true;
    }
    /* 指纹数据和录入过的都不匹配，亮红灯 */
    else {
        sendCmd(CMD_LED_RED_ON);
        Serial.println("指纹比对失败");
        return false;
    }
}
