/**
 * @file AppFablab.hpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Modul aplikace pro zobrazování obsazenosti FabLabu
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
 * @brief Modul aplikace pro zobrazování obsazenosti FabLabu
 * 
 */
class AppFablab : public Application {
private:
protected:
    std::string machineKey;
public:
    /**
     * @brief Konstruktor aplikace - dědí z výchozí aplikace
     * 
     * @param updateIntervalSec Interval mezi aktualizacemi v sekundách
     * @param getHTTPRequest Statická metoda pro HTTP request
     */
    AppFablab(int updateIntervalSec, AppConfig& appConfig);

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
     * @brief Zobrazí zformátovaná data na display
     * 
     * @param display GxEPD* ukazatel na displej
     * @param data Data získaná z HTTP requestu
     * @return int Vrací čas v ms za jak dlouho se má aplikace znovu aktualizovat
     */
    int showDataOnDisplay(GxEPD* display, JSONVar data);

    void showMachineLine(GxEPD* display, std::string name, std::string status);
};