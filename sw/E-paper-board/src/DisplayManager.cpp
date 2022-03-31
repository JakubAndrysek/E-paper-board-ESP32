#include "DisplayManager.hpp"

DisplayManager::DisplayManager() {
    SPI.begin(EPD_SCLK, EPD_MISO, EPD_MOSI);
    io = new GxIO_Class(SPI, EPD_CS, EPD_DC, EPD_RSET);
    display = new GxEPD_Class(*io, EPD_RSET);
    display->init();
}

DisplayManager::~DisplayManager() {
    delete display;
    delete io;
}

void DisplayManager::test() {
    display->setTextColor(GxEPD_BLACK);
    display->setFont(&FreeMono9pt7b);
    display->setCursor(0, 45);
    display->println("Hello World");

    display->setTextColor(GxEPD_RED);
    display->setFont(&FreeSans9pt7b);
    display->println("Hello World");

    display->setFont(&FreeSerif9pt7b);
    display->println("Hello World");
    display->update();
}