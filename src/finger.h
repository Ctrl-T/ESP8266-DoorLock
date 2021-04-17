#ifndef FINGER_H
#define FINFER_H

#include <Arduino.h>
#include <SoftwareSerial.h>

/* 指纹模块控制命令 */
typedef enum {
    CMD_LED_RED_ON,         // 亮红灯
    CMD_LED_GREEN_ON,       // 亮绿灯
    CMD_LED_YELLOW_ON,      // 亮黄灯
    CMD_LED_ALL_OFF,        // 熄灭所有灯
    CMD_FINGER_DETECT,      // 检测有无手指按下
    CMD_GET_IMAGE,          // 从指纹模块采集指纹数据
    CMD_SEARCH_FINGERPRINT, // 验证是否匹配已录入的指纹
    CMD_GET_EMPTY_ID,       // 获取未录入指纹的第一个编号
    CMD_GENERATE_0,         // 暂存录入的第一次指纹
    CMD_GENERATE_1,         // 暂存录入的第二次指纹
    CMD_GENERATE_2,         // 暂存录入的第三次指纹
    CMD_MERGE_CHAR,         // 合并录入的三次指纹特征
    CMD_STORE_CHAR          // 存储合并后的指纹
} Command_t;

/* 控制命令数据，和前面的枚举一一对应 */
extern const u8 CMD_DATA[][26];

class Finger {
  private:
    SoftwareSerial serialFinger;
    /* 接收缓冲区 */
    u8 recvBuff[26];

  public:
    Finger(int pinRx, int pinTx);
    void sendCmd(Command_t cmd);
    bool readFinger();
    void init();
};

#endif