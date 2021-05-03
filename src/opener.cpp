#include "opener.h"

Opener::Opener(const char *name) : typeName(name) {}

void Opener::addCntSuccess() { cntSuccess++; }

void Opener::addCntFail() { cntFail++; }

String Opener::getLog() {
    String log = String("[") + typeName + "] success:" + cntSuccess +
                 " fail:" + cntFail;
    cntSuccess = 0;
    cntFail = 0;
    return log;
}