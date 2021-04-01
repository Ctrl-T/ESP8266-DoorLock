#include "nfc.h"
NFC::NFC() {}

/**
 * 读取NFC卡号，在列表中则返回真
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
                Serial.print("Card ID: ");
                for (size_t i = 7; i <= 10; i++) {
                    Serial.printf("%x ", revdata[i]);
                }
                Serial.println();
                if (isInList(revdata + 7)) {
                    Serial.println("Card verify pass!");
                    return true;
                }
            } else {
                Serial.println("fail to Read card id!");
            }
        }
    }
    return false;
}

/**
 * 检验和, 正确则返回真
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
 * 检查卡号, 在列表中则返回真
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