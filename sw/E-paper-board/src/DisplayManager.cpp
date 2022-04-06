#include "DisplayManager.hpp"

#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSansBold9pt7b.h>

DisplayManager::DisplayManager() {
    SPI.begin(EPD_SCLK, EPD_MISO, EPD_MOSI);
    io = new GxIO_Class(SPI, EPD_CS, EPD_DC, EPD_RSET);
    display = new GxEPD_Class(*io, EPD_RSET);
    display->init();
    display->setRotation(1);
}

void DisplayManager::showStopLine(std::string time, std::string delay) {
    display->setTextColor(GxEPD_BLACK);
    display->printf(std::string("- " + time + " ").c_str());

    if(delay != "") {
        display->setTextColor(GxEPD_RED);
        display->print(std::string("(" + delay + ")\n").c_str());
        display->setTextColor(GxEPD_BLACK);
    } else {
        display->print("\n");
    }

}

void DisplayManager::test() {

    display->setCursor(0, 8);
    display->setTextColor(GxEPD_RED);
    display->setFont(&FreeSansBold9pt7b);
    display->print("Odjezdy salin\n");

    display->setTextColor(GxEPD_BLACK);
    display->setFont(&FreeSansBold12pt7b);
    display->print("Z: Semilasso\n");

    display->setFont(&FreeSansBold9pt7b);
    showStopLine("1min", "2 min");
    showStopLine("13min");

    display->drawRect(0, 0, display->width(), display->height(), GxEPD_BLACK);
    display->update();

}