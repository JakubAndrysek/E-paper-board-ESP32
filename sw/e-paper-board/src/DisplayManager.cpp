/**
 * @file DisplayManager.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Správce displeje
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "DisplayManager.hpp"
#include "utils/utils.hpp"

DisplayManager::DisplayManager() {
    SPI.begin(EPD_SCLK, EPD_MISO, EPD_MOSI);
    io = new GxIO_Class(SPI, EPD_CS, EPD_DC, EPD_RSET);
    display = new GxEPD_Class(*io, EPD_RSET);
    display->init();
    display->setRotation(1);
    // display->fillScreen(GxEPD_WHITE);
    // display->update();
}

void DisplayManager::init() {
    display->fillScreen(GxEPD_WHITE);
    display->update();
}

void DisplayManager::test() {
    display->setCursor(0, 8);
    display->setTextColor(GxEPD_RED);
    display->setFont(&FreeSans9pt8b);
    display->print(printCz("Odjezdy šalin\n"));
    display->update();
}

void DisplayManager::prepareDisplay(const GFXfont *f, uint16_t fillScreenColor, uint16_t textColor) {
    display->setFont(&FreeSans9pt8b);
    display->fillScreen(GxEPD_WHITE);
    display->setTextColor(GxEPD_BLACK);
}

void DisplayManager::showError(std::string errorMsg) {
    display->setFont(&FreeSans9pt8b);
    display->fillScreen(GxEPD_WHITE);
    display->setTextColor(GxEPD_BLACK);
    display->setCursor(0, 30);
    display->println(printCz("Error:"));
    display->setTextColor(GxEPD_RED);
    display->print(printCz(errorMsg.c_str()));
    display->update();
}

void DisplayManager::wifiConnectInfo(std::string ssid, std::string password) {
    this->prepareDisplay();
    display->setCursor(0, 30);
    display->println(printCz("Připojuji se na WiFi"));
    display->setCursor(0, 50);
    display->print(printCz("Jméno: "));
    display->print(printCz(ssid.c_str()));
    display->setCursor(0, 70);
    display->print(printCz("Heslo: "));
    display->print(printCz(password.c_str()));
    display->update();
}