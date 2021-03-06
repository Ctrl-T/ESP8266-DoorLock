#include "OTA.h"

OTAClass::OTAClass() : server(80) {}

void OTAClass::init() {
    MDNS.begin(host);
    server.on("/", HTTP_GET, [&]() {
        server.sendHeader("Connection", "close");
        server.send(200, "text/html; charset=UTF-8", serverIndex);
    });
    server.on(
        "/update", HTTP_POST,
        [&]() {
            server.sendHeader("Connection", "close");
            server.send(200, "text/html; charset=UTF-8", Update.hasError() ? "更新失败" : "更新成功");
            // server.send(200, "text/plain; charset=UTF-8", "OK");
            delay(2000);
            ESP.restart();
        },
        [&]() {
            HTTPUpload &upload = server.upload();
            if (upload.status == UPLOAD_FILE_START) {
                Serial.setDebugOutput(true);
                WiFiUDP::stopAll();
                DEBUG_PRINTF("Update: %s\n", upload.filename.c_str());
                uint32_t maxSketchSpace =
                    (ESP.getFreeSketchSpace() - 0x1000) & 0xFFFFF000;
                if (!Update.begin(
                        maxSketchSpace)) { // start with max available size
                    Update.printError(Serial);
                }
            } else if (upload.status == UPLOAD_FILE_WRITE) {
                if (Update.write(upload.buf, upload.currentSize) !=
                    upload.currentSize) {
                    Update.printError(Serial);
                }
            } else if (upload.status == UPLOAD_FILE_END) {
                if (Update.end(true)) { // true to set the size to the
                                        // current progress
                    DEBUG_PRINTF("Update Success: %u\nRebooting...\n",
                                  upload.totalSize);
                } else {
                    Update.printError(Serial);
                }
                Serial.setDebugOutput(false);
            }
            yield();
        });
    server.begin();
    MDNS.addService("http", "tcp", 80);

    DEBUG_PRINTF("OTA ready! Open http://%s.local in your browser\n", host);
}

void OTAClass::update() {
    server.handleClient();
    MDNS.update();
}

OTAClass OTA;