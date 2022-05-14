/**
 * @file DisplayManager.hpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Správce displeje
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */
#pragma once

#include "Board_TTGO_Tdisplay.hpp"

#include <string>
#include <Adafruit_I2CDevice.h>
#include <GxEPD.h>
#include <GxGDEW027C44/GxGDEW027C44.h> // 2.7" b/w/r form GoodDisplay
#include <GxIO/GxIO.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>

#include "fontsCz/FreeSans9pt8bfr.h"

/**
 * @brief Správce displeje
 * 
 */
class DisplayManager {
private:
    GxIO_Class* io;

public:
    /**
     * @brief Veřejná objekt pro řízení displeje typu GxEPD
     * 
     * Pozor je to ukazatel
     */
    GxEPD_Class* display;

    /**
     * @brief Konstruktor správce displeje
     * 
     */
    DisplayManager();

    /**
     * @brief Vyčistí displej
     * 
     */
    void init();

    /**
     * @brief Test displeje - vykreslení zkušebního textu
     * 
     */
    void test();

    /**
     * @brief 
     * 
     */
    // void prepareDisplay();
    void prepareDisplay(const GFXfont* f = &FreeSans9pt8b, uint16_t fillScreenColor = GxEPD_BG, uint16_t textColor = GxEPD_TEXT);

    /**
     * @brief Zobrazí zprávy chyby
     * 
     * @param errorMsg std::string Zpráva chyby
     */
    void showError(std::string errorMsg);

    /**
     * @brief Zobrazí informace o připojení k WiFi
     * 
     * @param ssid std::string SSID
     * @param password std::string Heslo
     */
    void wifiConnectInfo(std::string ssid, std::string password);
};