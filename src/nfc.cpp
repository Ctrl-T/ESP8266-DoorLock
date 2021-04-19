#include "nfc.h"
NFC::NFC() {}

/**
 * @brief 读取NFC卡号，在列表中则返回真
 **/
bool NFC::readCardID() {
    uint8 revdata[32];
    int len = 0;
    if (Serial.available() <= 0)
        return false;
    delay(200);
    len = Serial.available();
    Serial.readBytes(revdata, len);
    if ((revdata[0] = 0x04) && (revdata[1] == 0x0C) && (revdata[2] == 0x02) &&
        (revdata[3] = 0x20)) {
        if (CheckSumIn(revdata, revdata[1])) {
            if (revdata[4] == 0x00) {
                // 数组revdata[7]开始4字节为卡号
                DEBUG_PRINT("Card ID: ");
                for (size_t i = 7; i <= 10; i++) {
                    DEBUG_PRINTF("%x ", revdata[i]);
                }
                DEBUG_PRINTLN();
                if (isInList(revdata + 7)) {
                    DEBUG_PRINTLN("Card verify pass!");
                    return true;
                }
            } else {
                DEBUG_PRINTLN("fail to Read card id!");
            }
        }
    }
    return false;
}

/**
 * @brief 检验和
 * @retval 是否正确
 **/
bool NFC::CheckSumIn(uint8 *buf, int len) {
    uint8 i;
    uint8 checksum;
    checksum = 0;
    for (i = 0; i < (len - 1); i++) {
        checksum ^= buf[i];
    }
    if (buf[len - 1] == (uint8)~checksum) {
        return true;
    }
    return false;
}

/**
 * @brief 检查卡号
 * @retval 卡号是否在列表中
 *
 **/
bool NFC::isInList(uint8 *id) {
    bool inList = false;
    for (int i = 0; i < LIST_LEN; ++i) {
        inList = true;
        for (int j = 0; j < 4; ++j) {
            if (ids[i][j] != id[j]) {
                inList = false;
                break;
            }
        }
        if (!inList) {
            continue;
        } else {
            break;
        }
    }
    return inList;
}