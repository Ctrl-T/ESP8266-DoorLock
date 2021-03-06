#ifndef LOGO_PCP_H
#define LOGO_PCP_H

#define logoCPCWidth 47
#define logoCPCHeight 46

const uint8 logoCPCBits[] = {
    0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x03, 0x00,
    0x00, 0x00, 0x00, 0xC0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x80, 0x1F, 0x00,
    0x00, 0x00, 0xC0, 0x00, 0x3F, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x7E, 0x00,
    0x00, 0x80, 0xFF, 0x03, 0xFE, 0x00, 0x00, 0xC0, 0xFF, 0x03, 0xFC, 0x00,
    0x00, 0xE0, 0xFF, 0x0D, 0xF8, 0x01, 0x00, 0xF0, 0xFF, 0x0E, 0xF8, 0x03,
    0x00, 0xF8, 0x7F, 0x07, 0xF0, 0x03, 0x00, 0xFC, 0xBF, 0x03, 0xF0, 0x07,
    0x00, 0xFE, 0xDF, 0x01, 0xF0, 0x07, 0x00, 0xFF, 0xBF, 0x00, 0xE0, 0x0F,
    0x80, 0xFF, 0x7F, 0x00, 0xE0, 0x0F, 0xC0, 0xFF, 0xFF, 0x00, 0xE0, 0x2F,
    0xC0, 0xFF, 0xFF, 0x01, 0xE0, 0x2F, 0x80, 0xFF, 0xFF, 0x03, 0xE0, 0x2F,
    0x00, 0x7F, 0xFF, 0x07, 0xE0, 0x1F, 0x00, 0xBE, 0xFE, 0x0F, 0xE0, 0x5F,
    0x00, 0xDC, 0xFD, 0x1F, 0xE0, 0x5F, 0x00, 0xE8, 0xF8, 0x3F, 0xE0, 0x5F,
    0x00, 0x70, 0xF0, 0x7F, 0xE0, 0x6F, 0x00, 0x20, 0xE0, 0xFF, 0xE0, 0x6F,
    0x00, 0x00, 0xC0, 0xFF, 0xF1, 0x6F, 0x00, 0x00, 0x80, 0xFF, 0xF3, 0x2F,
    0x00, 0x00, 0x00, 0xFF, 0xFF, 0x37, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0x37,
    0x60, 0x00, 0x00, 0xFC, 0xFF, 0x37, 0xF0, 0x00, 0x00, 0xF8, 0xFF, 0x1B,
    0xF8, 0x03, 0x00, 0xF0, 0xFF, 0x1B, 0xF8, 0x07, 0x00, 0xE0, 0xFF, 0x0D,
    0xF0, 0x1F, 0x00, 0xE0, 0xFF, 0x0D, 0xE0, 0xFF, 0x00, 0xF8, 0xFF, 0x03,
    0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F,
    0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x27,
    0xFE, 0xF8, 0xFF, 0xFF, 0xF1, 0x3B, 0xFE, 0xE2, 0xFF, 0x7F, 0xEE, 0x1D,
    0x7C, 0x83, 0xFF, 0x9F, 0xCF, 0x0E, 0xB8, 0x03, 0xF0, 0xE0, 0x03, 0x06,
    0xC0, 0x01, 0x0E, 0x7F, 0x00, 0x03, 0xE0, 0x00, 0xE0, 0x07, 0x00, 0x00,
};

#define arrowWidth 27
#define arrowHeight 35

const uint8 arrowLBits[] = {
    0x00, 0x00, 0xFE, 0x01, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x80, 0x7F, 0x06,
    0x00, 0xC0, 0x3F, 0x03, 0x00, 0xE0, 0x9F, 0x01, 0x00, 0xF0, 0xCF, 0x00,
    0x00, 0xF8, 0x67, 0x00, 0x00, 0xFC, 0x33, 0x00, 0x00, 0xFE, 0x19, 0x00,
    0x00, 0xFF, 0x0C, 0x00, 0x80, 0x7F, 0x06, 0x00, 0xC0, 0x3F, 0x03, 0x00,
    0xE0, 0x9F, 0x01, 0x00, 0xF0, 0xCF, 0x00, 0x00, 0xF8, 0x67, 0x00, 0x00,
    0xFC, 0x33, 0x00, 0x00, 0xFE, 0x19, 0x00, 0x00, 0xFC, 0x0F, 0x00, 0x00,
    0xF8, 0x07, 0x00, 0x00, 0xF0, 0x0F, 0x00, 0x00, 0xE0, 0x1F, 0x00, 0x00,
    0xC0, 0x3F, 0x00, 0x00, 0x80, 0x7F, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00,
    0x00, 0xFE, 0x01, 0x00, 0x00, 0xFC, 0x03, 0x00, 0x00, 0xF8, 0x07, 0x00,
    0x00, 0xF0, 0x0F, 0x00, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0xC0, 0x3F, 0x00,
    0x00, 0x80, 0x7F, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFE, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0x07,
};

const uint8 arrowRBits[] = {
    0xFE, 0x01, 0x00, 0x00, 0xFC, 0x03, 0x00, 0x00, 0xF8, 0x07, 0x00, 0x00,
    0xF0, 0x0F, 0x00, 0x00, 0xE0, 0x1F, 0x00, 0x00, 0xC0, 0x3F, 0x00, 0x00,
    0x80, 0x7F, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x00,
    0x00, 0xFC, 0x03, 0x00, 0x00, 0xF8, 0x07, 0x00, 0x00, 0xF0, 0x0F, 0x00,
    0x00, 0xE0, 0x1F, 0x00, 0x00, 0xC0, 0x3F, 0x00, 0x00, 0x80, 0x7F, 0x00,
    0x00, 0x00, 0xFF, 0x00, 0x00, 0x00, 0xFE, 0x01, 0x00, 0x00, 0xFF, 0x00,
    0x00, 0x80, 0x7F, 0x06, 0x00, 0xC0, 0x3F, 0x03, 0x00, 0xE0, 0x9F, 0x01,
    0x00, 0xF0, 0xCF, 0x00, 0x00, 0xF8, 0x67, 0x00, 0x00, 0xFC, 0x33, 0x00,
    0x00, 0xFE, 0x19, 0x00, 0x00, 0xFF, 0x0C, 0x00, 0x80, 0x7F, 0x06, 0x00,
    0xC0, 0x3F, 0x03, 0x00, 0xE0, 0x9F, 0x01, 0x00, 0xF0, 0xCF, 0x00, 0x00,
    0xF8, 0x67, 0x00, 0x00, 0xFC, 0x33, 0x00, 0x00, 0xFE, 0x19, 0x00, 0x00,
    0x00, 0x0C, 0x00, 0x00, 0xF8, 0x07, 0x00, 0x00,
};

#define maskWidth 79
#define maskHeight 35

const uint8 maskBits[] = {
    0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x03, 0x00, 0x00, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x07, 0x00, 0x00, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x00,
    0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0xFC,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0xFE, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x01, 0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03,
    0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0xF0, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xF8, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x3F, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0xFE, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0xFC, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x03, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x01, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00,
    0xC0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x80, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x00, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x00, 0x00, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0x0F, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
    0x07, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x00,
    0x00, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0xE0,
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0xC0, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0x3F, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F,
    0x00, 0x00,
};

#define logoWelcomeWidth 88
#define logoWelcomeHeight 42
const uint8 logoWelcomeBits[] = {
  0x02, 0x00, 0x00, 0x1F, 0x00, 0x00, 0x00, 0xC0, 0x03, 0xE0, 0x01, 0x1E, 
  0x00, 0x80, 0x3F, 0x00, 0xC0, 0x00, 0xE0, 0x07, 0xF0, 0x01, 0x7E, 0x00, 
  0x80, 0x3F, 0x00, 0xC0, 0x03, 0xE0, 0x07, 0xF0, 0x05, 0xFE, 0xE0, 0xFF, 
  0xFF, 0xFF, 0xC0, 0x0F, 0xE0, 0x17, 0xF0, 0x05, 0xFE, 0xE1, 0xFF, 0xFF, 
  0xFF, 0xC0, 0x3F, 0xE0, 0x07, 0xF0, 0x01, 0xFE, 0xE3, 0xFF, 0xFF, 0xFF, 
  0xC2, 0x3F, 0xFE, 0xFF, 0xFF, 0x0F, 0xFE, 0x03, 0x80, 0x3F, 0x00, 0xC3, 
  0x3F, 0xFF, 0xFF, 0xFF, 0x1F, 0xF8, 0x0B, 0x80, 0x3F, 0x00, 0xC3, 0xBF, 
  0xFE, 0xFF, 0xFF, 0x1F, 0xE0, 0xCB, 0xFF, 0xFF, 0xFF, 0xC0, 0xBF, 0xE0, 
  0x07, 0xF0, 0x61, 0x00, 0xCB, 0xFF, 0xFF, 0xFF, 0x00, 0xBC, 0xE8, 0xF7, 
  0xF7, 0x7D, 0x80, 0xCC, 0xFF, 0xFF, 0x7F, 0x03, 0xB3, 0xE0, 0x17, 0xF0, 
  0x05, 0x00, 0x0C, 0x80, 0x3F, 0x80, 0x03, 0xA0, 0xE0, 0x17, 0xF0, 0x05, 
  0x00, 0x00, 0xBF, 0xBF, 0xFF, 0x01, 0xC0, 0xE0, 0x17, 0xF0, 0x05, 0x00, 
  0x00, 0x80, 0x3F, 0x00, 0x00, 0x80, 0xE0, 0x17, 0xF0, 0x05, 0xFF, 0xF0, 
  0xFF, 0xFF, 0xFF, 0xE0, 0x3F, 0xE0, 0x17, 0xF0, 0x05, 0xFF, 0xF0, 0xFF, 
  0xFF, 0xFF, 0xE0, 0x3F, 0xE0, 0x17, 0xF0, 0x05, 0xFF, 0xF2, 0xFF, 0xFF, 
  0xFF, 0xE2, 0xBF, 0xE0, 0x17, 0xF0, 0x05, 0xFC, 0x02, 0x00, 0x00, 0x00, 
  0x83, 0xBF, 0xE0, 0x17, 0xF0, 0x05, 0xFC, 0x02, 0x00, 0x00, 0x00, 0x83, 
  0xBF, 0xE0, 0x17, 0xF0, 0x05, 0xFC, 0xE2, 0xFF, 0xFF, 0xFF, 0x80, 0xBF, 
  0xE0, 0x17, 0xF0, 0x05, 0xFC, 0xE2, 0xFF, 0xFF, 0xFF, 0x80, 0xBF, 0xE0, 
  0x17, 0xF0, 0x05, 0xFC, 0xE2, 0xFF, 0xFF, 0xFF, 0x82, 0xBF, 0xE0, 0x07, 
  0xF0, 0x01, 0xFC, 0xE2, 0x07, 0x00, 0xFC, 0x82, 0xBF, 0xFE, 0xFF, 0xFF, 
  0x0F, 0xFC, 0xE2, 0x07, 0x00, 0xFC, 0x82, 0x3F, 0xFF, 0xFF, 0xFF, 0x1F, 
  0xFC, 0xE2, 0xFF, 0xFF, 0xFF, 0x82, 0xBF, 0xFE, 0xFF, 0xFF, 0x2F, 0xFC, 
  0xE2, 0xFF, 0xFF, 0xFF, 0x82, 0xBF, 0xF0, 0x03, 0xF0, 0x71, 0xFC, 0xE2, 
  0xFF, 0xFF, 0xFF, 0x82, 0xBF, 0xF0, 0xFB, 0xF7, 0x3D, 0xFC, 0xE2, 0x07, 
  0x00, 0xFC, 0x82, 0xBF, 0xF0, 0x0D, 0xF0, 0x05, 0xFC, 0xE2, 0xF7, 0xFF, 
  0xFD, 0x82, 0xBF, 0xF8, 0x0D, 0xF0, 0x05, 0xFC, 0xE2, 0x07, 0x00, 0xFC, 
  0x82, 0xBF, 0xF8, 0x06, 0xF0, 0x05, 0xFC, 0xE0, 0xFF, 0xFF, 0xFF, 0xC2, 
  0xBF, 0xFC, 0x06, 0xF0, 0x05, 0xFC, 0xE7, 0xFF, 0xFF, 0xFF, 0xE2, 0xBF, 
  0xFC, 0x02, 0xF0, 0x05, 0xFC, 0xE7, 0xFF, 0xFF, 0xFF, 0xE2, 0xBF, 0x7E, 
  0x03, 0xF0, 0x05, 0xFC, 0xE7, 0x07, 0x00, 0xFC, 0xE2, 0x7F, 0x7E, 0x03, 
  0xF0, 0x05, 0xFC, 0xE9, 0xF7, 0xFF, 0xFD, 0xE2, 0x7F, 0x80, 0x01, 0x00, 
  0x06, 0xFC, 0xEE, 0x17, 0x00, 0xFC, 0xE2, 0xE3, 0xF8, 0x01, 0xC0, 0x07, 
  0x3E, 0xE7, 0x17, 0x00, 0xFC, 0xE2, 0xED, 0x01, 0x00, 0x00, 0x00, 0xCF, 
  0xE3, 0x17, 0xC0, 0xFF, 0xE2, 0xCE, 0xFF, 0xFF, 0xFF, 0x3F, 0xF3, 0xE0, 
  0x17, 0xC0, 0xFF, 0x62, 0x87, 0xFF, 0xFF, 0xFF, 0x3F, 0x3C, 0xC0, 0x1B, 
  0x80, 0xFF, 0x62, 0x03, 0xFF, 0xFF, 0xFF, 0xDF, 0x0C, 0x00, 0x1C, 0x00, 
  0x00, 0x83, 0x01, 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0x0F, 0x00, 0xFE, 
  0x83, 0x01, 0xFC, 0xFF, 0xFF, 0x7F, };

#endif