#ifndef FINGER_H
#define FINFER_H

#include <Arduino.h>
#include <SoftwareSerial.h>

/*******************************************************************************
 * Security Level
 ********************************************************************************/
#define MIN_SECURITY_LEVEL 1
#define MAX_SECURITY_LEVEL 10

/*******************************************************************************
 * Baudrate
 ********************************************************************************/
#define MIN_BAUDRATE_IDX 1 // 9600
#define MAX_BAUDRATE_IDX 8 // 9216200

/*******************************************************************************
 * Device ID
 ********************************************************************************/
#define MIN_DEVICE_ID 1
#define MAX_DEVICE_ID 255

#define MAX_TEMPLATE_SIZE (2048)
#define ID_NOTE_SIZE 64
#define MODULE_SN_LEN 16
#define MAX_DEVPASS_LEN 14

#define MAX_ENROLL_COUNT (10)

#define CONNECTION_SUCCESS 0
#define CONNECTION_FAIL 1
#define ERR_COM_OPEN_FAIL 2
#define ERR_USB_OPEN_FAIL 3

/***************************************************************************/
/***************************************************************************/
#define CMD_PREFIX_CODE 0xAA55
#define CMD_DATA_PREFIX_CODE 0xA55A
#define RCM_PREFIX_CODE 0x55AA
#define RCM_DATA_PREFIX_CODE 0x5AA5

/***************************************************************************
 * System Code (0x0000 ~ 0x001F, 0x0000 : Reserved)
 ***************************************************************************/
#define CMD_TEST_CONNECTION 0x0001
#define CMD_SET_PARAM 0x0002
#define CMD_GET_PARAM 0x0003
#define CMD_GET_DEVICE_INFO 0x0004
#define CMD_SET_ID_NOTE 0x0006
#define CMD_GET_ID_NOTE 0x0007
#define CMD_SET_MODULE_SN 0x0008
#define CMD_GET_MODULE_SN 0x0009
#define CMD_SET_DEVPASS 0x000A
#define CMD_VERIFY_DEVPASS 0x000B
#define CMD_ENTER_STANDY_STATE 0x000C
#define CMD_UPGRADE_FIRMWARE 0x000D

/***************************************************************************
 * Sensor Code (0x0020 ~ 0x003F)
 ***************************************************************************/
#define CMD_GET_IMAGE 0x0020
#define CMD_FINGER_DETECT 0x0021
#define CMD_UP_IMAGE 0x0022
#define CMD_DOWN_IMAGE 0x0023
#define CMD_SLED_CTRL 0x0024
#define CMD_ADJUST_SENSOR 0x0025

/***************************************************************************
 * Template Code (0x0040 ~ 0x005F)
 ***************************************************************************/
#define CMD_STORE_CHAR 0x0040
#define CMD_LOAD_CHAR 0x0041
#define CMD_UP_CHAR 0x0042
#define CMD_DOWN_CHAR 0x0043
#define CMD_DEL_CHAR 0x0044
#define CMD_GET_EMPTY_ID 0x0045
#define CMD_GET_STATUS 0x0046
#define CMD_GET_BROKEN_ID 0x0047
#define CMD_GET_ENROLL_COUNT 0x0048
#define CMD_GET_ENROLLED_ID_LIST 0x0049

/***************************************************************************
 * FingerPrint Alagorithm Code (0x0060 ~ 0x007F)
 ***************************************************************************/
#define CMD_GENERATE 0x0060
#define CMD_MERGE 0x0061
#define CMD_MATCH 0x0062
#define CMD_SEARCH 0x0063
#define CMD_VERIFY 0x0064

/***************************************************************************
 * RTC Code (0x00A0 ~ 0x00AF)
 ***************************************************************************/
#define CMD_SET_RTC 0x00A0
#define CMD_GET_RTC 0x00A1

/***************************************************************************
 * Cryptor Commands Code (0x3300 ~ 0x330F)
 ***************************************************************************/
#define CMD_GET_OEM_RSA_PUB_KEY 0x3300
#define CMD_SET_HOST_RSA_PUB_KEY 0x3301
#define CMD_ENCRYPTED_COMMAND 0x330F

/***************************************************************************
 * Unknown Command
 ***************************************************************************/
#define RCM_INCORRECT_COMMAND 0x00FF

/***************************************************************************/
/***************************************************************************/
#define ERR_SUCCESS 0
#define ERR_FAIL 1
#define ERR_CONNECTION 2
#define ERR_VERIFY 0x10
#define ERR_IDENTIFY 0x11
#define ERR_TMPL_EMPTY 0x12
#define ERR_TMPL_NOT_EMPTY 0x13
#define ERR_ALL_TMPL_EMPTY 0x14
#define ERR_EMPTY_ID_NOEXIST 0x15
#define ERR_BROKEN_ID_NOEXIST 0x16
#define ERR_INVALID_TMPL_DATA 0x17
#define ERR_DUPLICATION_ID 0x18
#define ERR_BAD_QUALITY 0x19
#define ERR_MERGE_FAIL 0x1A
#define ERR_NOT_AUTHORIZED 0x1B
#define ERR_MEMORY 0x1C
#define ERR_INVALID_TMPL_NO 0x1D
#define ERR_INVALID_PARAM 0x22
#define ERR_GEN_COUNT 0x25
#define ERR_INVALID_BUFFER_ID 0x26
#define ERR_INVALID_OPERATION_MODE 0x27
#define ERR_FP_NOT_DETECTED 0x28

#define ERR_INPUT_CORRECT_FP 0x30
#define ERR_MOVE_FINGER 0x31
#define ERR_LEAK_TEMPLATE_INFO 0x32

#define GD_TEMPLATE_NOT_EMPTY 0x01
#define GD_TEMPLATE_EMPTY 0x00

/*******************************************************************************
 * Define Parameter Index
 ********************************************************************************/
#define DP_DEVICE_ID 0
#define DP_SECURITY_LEVEL 1
#define DP_DUP_CHECK 2
#define DP_BAUDRATE 3
#define DP_AUTO_LEARN 4
#define DP_DEV_PASS 5

/***************************************************************************/
/***************************************************************************/
#define WM_CMD_PACKET_HOOK (WM_USER + 10)
#define WM_RCM_PACKET_HOOK (WM_USER + 11)
#define WM_UP_IMAGE_PROGRESS (WM_USER + 12)

/***************************************************************************/
/***************************************************************************/
typedef enum { SERIAL_CON_MODE = 0, USB_CON_MODE } CONNECTION_MODE;

/***************************************************************************/
// RTC Type
/***************************************************************************/
typedef struct _ST_RTC_TYPE_ {
    u16 m_nYear;
    u8 m_nMonth;
    u8 m_nDay;
    u8 m_nHour;
    u8 m_nMinute;
    u8 m_nSecond;
    u8 m_nReserved;
} ST_RTC_TYPE;

/***************************************************************************/
#define RESPONSE_RET (g_pRcmPacket->m_wRetCode)
typedef struct _ST_CMD_PACKET_ {
    short m_wPrefix;
    u8 m_bySrcDeviceID;
    u8 m_byDstDeviceID;
    short m_wCMDCode;
    short m_wDataLen;
    u8 m_abyData[16];
    short m_wCheckSum;
} ST_CMD_PACKET, *PST_CMD_PACKET;

typedef struct _ST_RCM_PACKET_ {
    u16 m_wPrefix;
    u8 m_bySrcDeviceID;
    u8 m_byDstDeviceID;
    u16 m_wCMDCode;
    u16 m_wDataLen;
    u16 m_wRetCode;
    u8 m_abyData[14];
    u16 m_wCheckSum;
} ST_RCM_PACKET, *PST_RCM_PACKET;
/***************************************************************************/

class Finger {
  private:
    int Run_GetImage();
    void InitCmdPacket(u16 p_wCMDCode, u8 p_bySrcDeviceID, u8 p_byDstDeviceID,
                       u8 *p_pbyData, u16 p_wDataLen);
    bool Run_Command_NP(short p_wCMD);
    bool SendCommand(u16 p_wCMDCode, u8 p_bySrcDeviceID, u8 p_byDstDeviceID);
    void DoLedCtrl(unsigned char p_nCtrlCode)
    u8 g_Packet[1024 * 64];
    PST_CMD_PACKET g_pCmdPacket = (PST_CMD_PACKET)g_Packet;
    PST_RCM_PACKET g_pRcmPacket = (PST_RCM_PACKET)g_Packet;
    u32 g_dwPacketSize = 0;
    u8 m_bySrcDeviceID;
    u8 m_byDstDeviceID;
    SoftwareSerial softwareSerial;

  public:
    void init();
    Finger();
    ~Finger();
    bool identify();
};

#endif