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

void DisplayManager::test() {
    // display->setTextColor(GxEPD_BLACK);
    // display->setFont(&FreeMono9pt7b);
    // display->setCursor(0, 45);
    // display->println("Hello World");

    // display->setTextColor(GxEPD_RED);
    // display->setFont(&FreeSans9pt7b);
    // display->println("Hello World");

    // display->setFont(&FreeSerif9pt7b);
    // display->println("Hello World");
    // display->update();

    display->setCursor(0, 0);
    display->setTextColor(GxEPD_BLACK);
    display->print("Příliš žluťoučký kůň úpěl ďábelské ódy");
    // display->setFont(&FreeSansBold12pt7b);
    // display->print("\nAhoj svete!");
    // display->setRotation(3);
    // display->fillRect(50, 60, 128, 64, GxEPD_RED);
    display->drawRect(0, 0, display->width(), display->height(), GxEPD_BLACK);



    display->update();    
}