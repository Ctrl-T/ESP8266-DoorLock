#ifndef NFC_H
#define NFC_H

#include <Arduino.h>
#include <HardwareSerial.h>
#define LIST_LEN 4

class NFC {
  private:
    const uint8 ids[LIST_LEN][4] = {{0xc0, 0xac, 0x12, 0x49},
                                    {0x20, 0xd7, 0x14, 0x49},
                                    {0xa1, 0xb7, 0x93, 0x74},
                                    {0xf0, 0xd, 0x12, 0x49}}; // 允许的门卡ID
  public:
    NFC();
    bool readCardID();
    bool CheckSumIn(uint8 *buf, int len);
    bool isInList(uint8 *id);
};

#endif