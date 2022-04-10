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
#include <Arduino_JSON.h>
#include <GxGDEW027C44/GxGDEW027C44.h>
#include <functional>

/**
 * @brief Modul aplikace pro zobrazování obsazenosti FabLabu
 * 
 */
class AppFablab : public Application {
private:
public:
    /**
     * @brief Konstruktor aplikace AppFablab dědí z výchozí aplikace
     * 
     * @param getHTTPRequest Statická metoda pro HTTP request
     */
    AppFablab(std::function<std::string(std::string url)> getHTTPRequest);

    /**
     * @brief Vrátí název a popis třídy
     * 
     * Virtualní metoda
     * @return std::string Název a popis třídy
     */
    std::string toString();

    /**
     * @brief Nastaví callback pro atualizaci displeje
     * 
     * Implementace z výchozí aplikace
     * 
     * @param updateHandler Callback pro akutalizaci displeje
     */
    void setUpdateHandler(std::function<int(void)> updateHandler);

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
     * @brief 
     * 
     * @param display GxEPD* ukazatel na displej
     * 
     * Implementace z výchozí aplikace
     * @return int Vrací čas v ms za jak dlouho se má aplikace znovu aktualizovat
     */
    int update(GxEPD* display);
};