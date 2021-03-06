/**
 * @file AppSalina.hpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Modul aplikace pro monitorování šalin v IDSJMK
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */
#pragma once

#include "Application.hpp"
#include "apps/AppConfig.hpp"
#include <Arduino_JSON.h>
#include <GxGDEW027C44/GxGDEW027C44.h>
#include <functional>

/**
 * @brief Modul aplikace pro monitorování šalin v IDSJMK
 * 
 */
class AppSalina : public Application {
private:
public:
    /**
     * @brief Konstruktor aplikace - dědí z výchozí aplikace
     * 
     * @param updateIntervalSec Interval mezi aktualizacemi v sekundách
     * @param getHTTPRequest Statická metoda pro HTTP request
     */
    AppSalina(int updateIntervalSec, AppConfig& appConfig);

    /**
     * @brief Vrátí název a popis třídy
     * 
     * Virtualní metoda
     * @return std::string Název a popis třídy
     */
    std::string toString();

    /**
     * @brief Callback vyvolaný po stisknutí prostředního tlačítka
     * 
     * Implementace z výchozí aplikace
     */
    void buttonClickMiddle();

    /**
     * @brief Callback vyvolaný po stisknutí pr tlačítka
     * 
     * Implementace z výchozí aplikace
     */
    void buttonClickRight();

    /**
     * @brief Vykreslí na displej jeden řádek odjezdu ze zastávky
     * 
     * @param display Ukazatel na displej
     * @param LineName Název linky
     * @param TimeMark Zpoždění odjezdu
     * @param FinalStop Konečná zastávka
     */
    void showStopLine(GxEPD* display, std::string LineName, std::string TimeMark, std::string FinalStop = "");

    /**
     * @brief Vykreslí na displej odjezd ze zastávky
     * 
     * Využívá metodu showStopLine
     * @param display Ukazatel na displej
     * @param salinaStop Objekt s odjezdy ze zastávky
     */
    int showDataOnDisplay(GxEPD* display, JSONVar data);
};