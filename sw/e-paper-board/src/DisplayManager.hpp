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

#include <Adafruit_I2CDevice.h>
#include <GxEPD.h>
#include <GxGDEW027C44/GxGDEW027C44.h> // 2.7" b/w/r form GoodDisplay
#include <GxIO/GxIO.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>

// #include <Fonts/FreeMono9pt7b.h>
// #include <Fonts/FreeMonoBold12pt7b.h>
// #include <Fonts/FreeMonoBold18pt7b.h>
// #include <Fonts/FreeMonoBold9pt7b.h>
// #include <Fonts/FreeSans9pt7b.h>
// #include <Fonts/FreeSerif9pt7b.h>

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
     * @brief Zobrazí zprávy chyby
     * 
     * @param errorMsg std::string Zpráva chyby
     */
    void showError(std::string errorMsg);
};