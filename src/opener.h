#ifndef OPENER_H
#define OPENER_H

#include "WString.h"

class Opener {
  protected:
    int cntSuccess = 0, cntFail = 0;
    const char* typeName;
    void addCntSuccess();
    void addCntFail();

  public:
    Opener(const char* name);
    String getLog();
    virtual bool checkOpenInstr() = 0;
};

#endif