#include "finger.h"

Finger::Finger(/* args */) {}

Finger::~Finger() {}

void  Finger::init() {
softwareSerial
}

bool Finger::identify() {
    int w_nRet, w_nTmplNo, w_nLearned;

    while (1) {
        DoLedCtrl(E_LED_CTRL_CAPTURE);

        //. Get Image
        while (1) {
            //. Get Image
            w_nRet = m_clsCommu.Run_GetImage();

            if (w_nRet == ERR_SUCCESS)
                break;
            else if ((w_nRet == ERR_CONNECTION) ||
                     (w_nRet == ERR_NOT_AUTHORIZED)) {
                return false;
            }
        }

        DoLedCtrl(E_LED_CTRL_DETECTED);

        //. Create Template
        w_nRet = m_clsCommu.Run_Generate(0);

        if (w_nRet != ERR_SUCCESS) {
            return false;
        }

        //. Identify
        w_nRet = m_clsCommu.Run_Search(0, 1, 80, &w_nTmplNo, &w_nLearned);

        if (w_nRet == ERR_SUCCESS) {
            DoLedCtrl(E_LED_CTRL_IDENTIFY_OK);
            return true;
        } else {
            return false;
            DoLedCtrl(E_LED_CTRL_IDENTIFY_NG);
        }
    }
}

int Finger::Run_GetImage() {
    bool w_bRet;

    w_bRet = Run_Command_NP(CMD_GET_IMAGE);

    if (!w_bRet)
        return ERR_CONNECTION;

    return RESPONSE_RET;
}

bool Finger::Run_Command_NP(short p_wCMD) {
    bool w_bRet;

    //. Assemble command packet
    InitCmdPacket(p_wCMD, m_bySrcDeviceID, m_byDstDeviceID, NULL, 0);
    w_bRet = SendCommand(p_wCMD, m_bySrcDeviceID, m_byDstDeviceID);
    return w_bRet;
}

void Finger::InitCmdPacket(u16 p_wCMDCode, u8 p_bySrcDeviceID,
                           u8 p_byDstDeviceID, u8 *p_pbyData, u16 p_wDataLen) {
    int i;
    u16 w_wCheckSum;

    memset(g_Packet, 0, sizeof(g_Packet));
    g_pCmdPacket->m_wPrefix = CMD_PREFIX_CODE;
    g_pCmdPacket->m_bySrcDeviceID = p_bySrcDeviceID;
    g_pCmdPacket->m_byDstDeviceID = p_byDstDeviceID;
    g_pCmdPacket->m_wCMDCode = p_wCMDCode;
    g_pCmdPacket->m_wDataLen = p_wDataLen;

    if (p_wDataLen)
        memcpy(g_pCmdPacket->m_abyData, p_pbyData, p_wDataLen);

    w_wCheckSum = 0;

    for (i = 0; i < sizeof(ST_CMD_PACKET) - 2; i++) {
        w_wCheckSum = w_wCheckSum + g_Packet[i];
    }

    g_pCmdPacket->m_wCheckSum = w_wCheckSum;

    g_dwPacketSize = sizeof(ST_CMD_PACKET);
}

bool Finger::SendCommand(u16 p_wCMDCode, u8 p_bySrcDeviceID,
                         u8 p_byDstDeviceID) {
    u32 w_nSendCnt = 0;
    long w_nResult = 0;
    int w_nRet;
    bool w_bRet;

    g_Serial.Purge();

    ::SendMessage(g_hMainWnd, WM_CMD_PACKET_HOOK, 0, 0);

    // encrypt packet
    w_nRet = EncryptCommandPacket();

    w_nResult = g_Serial.Write(g_Packet, g_dwPacketSize, &w_nSendCnt, NULL,
                               COMM_TIMEOUT);

    if (ERROR_SUCCESS != w_nResult) {
        return FALSE;
    }

    if (w_nRet == ERR_SUCCESS) {
        w_bRet = ReceiveDataAck(p_wCMDCode, p_bySrcDeviceID, p_byDstDeviceID);
    } else {
        w_bRet = ReceiveAck(p_wCMDCode, p_bySrcDeviceID, p_byDstDeviceID);
    }

    return w_bRet;
}
void Finger::DoLedCtrl(unsigned char p_nCtrlCode)
{
	unsigned char w_nColor = 0;

	if (m_bAdvLed)	// Advanced
	{
		switch (p_nCtrlCode)
		{
		case E_LED_CTRL_CONNECT:
			{
				// Blue Led Breath
				w_nColor = 0x80 + (1 << E_LED_COLOR_OK);
				m_clsCommu.Run_SLEDControl(LED_VAL(w_nColor, E_LED_STATUS_BREATH));
				break;
			}
		case E_LED_CTRL_DISCONNECT:
			{
				// All Led Off
				w_nColor = 0x80 + (1 << E_LED_COLOR_OK) + (1 << E_LED_COLOR_NG);
				m_clsCommu.Run_SLEDControl(LED_VAL(w_nColor, E_LED_STATUS_OFF));
				break;
			}
		case E_LED_CTRL_WAIT:
			{
				// Blue Led Breath
				w_nColor = 0x80 + (1 << E_LED_COLOR_OK);
				m_clsCommu.Run_SLEDControl(LED_VAL(w_nColor, E_LED_STATUS_BREATH));
				break;
			}
		case E_LED_CTRL_CAPTURE:
			{
				// Blue Led Blink Slow
				w_nColor = 0x80 + (1 << E_LED_COLOR_OK);
				m_clsCommu.Run_SLEDControl(LED_VAL(w_nColor, E_LED_STATUS_BLINK_SLOW));
				break;
			}
		case E_LED_CTRL_DETECTED:
			{
				// All Led Off
				w_nColor = 0x80 + (1 << E_LED_COLOR_OK) + (1 << E_LED_COLOR_NG);
				m_clsCommu.Run_SLEDControl(LED_VAL(w_nColor, E_LED_STATUS_OFF));
				break;
			}
		case E_LED_CTRL_IDENTIFY_OK:
			{
				UpdateData(FALSE);
				DoEvents();

				// Blue Led On 1s
				w_nColor = 0x80 + (1 << E_LED_COLOR_OK);
				m_clsCommu.Run_SLEDControl(LED_VAL(w_nColor, E_LED_STATUS_ON));
				Sleep(1000);
				m_clsCommu.Run_SLEDControl(LED_VAL(w_nColor, E_LED_STATUS_OFF));
				break;
			}
		case E_LED_CTRL_IDENTIFY_NG:
			{
				UpdateData(FALSE);
				DoEvents();

				// Red Led On 1s
				w_nColor = 0x80 + (1 << E_LED_COLOR_NG);
				m_clsCommu.Run_SLEDControl(LED_VAL(w_nColor, E_LED_STATUS_ON));
				Sleep(1000);
				m_clsCommu.Run_SLEDControl(LED_VAL(w_nColor, E_LED_STATUS_OFF));
				break;
			}
		default:
			{
				break;
			}
		}
	}
	else	// Original
	{
		switch (p_nCtrlCode)
		{
		case E_LED_CTRL_WAIT:
			{
				// Led Off
				m_clsCommu.Run_SLEDControl(0);
				break;
			}
		case E_LED_CTRL_CAPTURE:
			{
				// Led On
				m_clsCommu.Run_SLEDControl(1);
				break;
			}
		case E_LED_CTRL_DETECTED:
			{
				// Led Off
				m_clsCommu.Run_SLEDControl(0);
				break;
			}
		case E_LED_CTRL_CONNECT:
		case E_LED_CTRL_DISCONNECT:
		case E_LED_CTRL_IDENTIFY_OK:
		case E_LED_CTRL_IDENTIFY_NG:
		default:
			{
				break;
			}
		}
	}
}