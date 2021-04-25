#ifndef CONFIG_H
#define CONFIG_H

#define WIFI_SSID "飞机杯里泡枸杞_2.4G"          // WiFi名称
#define WIFI_PASSWORD "T1620183"                 // WiFi密码
#define REMOTE_HOST "door.steelblue.cn"          // 远程主机地址
#define REMOTE_PORT 20183                        // 远程主机端口
#define PUSHPLUS_URL "http://pushplus.plus/send" // pushpuls消息推送地址
#define PUSHPLUS_TOKEN                                                         \
    "d97a25a23cd7480599fc8a4836a0c44d"      // pushpuls消息推送Token
#define WEBUPDATE_HOST "doorlock-webupdate" // OTA网页地址

#define PIN_LOCK 15     // 锁
#define PIN_SETTING 5   // 设置按键
#define PIN_FNGR_RX 12  // 指纹RX
#define PIN_FNGR_TX 13  // 指纹TX
#define PIN_OLED_SCL 14 // OLED时钟
#define PIN_OLED_SDA 2  // OLED数据
#define PIN_OLED_RES 16 // OLED复位
#define PIN_CMD_INTR 4  // NFC和指纹中断

// #define DEBUG_DOORLOCK // debug开关

#ifdef DEBUG_DOORLOCK
#define DEBUG_PRINT(x) Serial.print(x)
#define DEBUG_PRINTLN(x) Serial.println(x)
#define DEBUG_PRINTF(x, ...) Serial.printf(x, __VA_ARGS__)
#else
#define DEBUG_PRINT(x)                                                         \
    do {                                                                       \
    } while (0)
#define DEBUG_PRINTLN(x)                                                       \
    do {                                                                       \
    } while (0)
#define DEBUG_PRINTF(x, ...)                                                   \
    do {                                                                       \
    } while (0)
#endif

#endif