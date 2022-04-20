/**
 * @file Application.hpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Rodičovská virtuální aplikace
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */
#pragma once

#include "GxEPD.h"
#include <Arduino_JSON.h>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <utility>

/**
 * @brief Výchozí aplikace
 * 
 */
class Application {
private:
protected:
    std::string httpUrlBase;
    std::string httpUrlParamKey;
    std::map<std::string, std::string> httpUrlParams;

    std::function<std::string(std::string url)> getHTTPRequest;
    std::function<int(void)> updateHandler;
    int updateIntervalSec;
    inline int secToMs(int sec) { return sec * 1000; }

public:
    /**
     * @brief Konstruktor výchozí aplikace
     * 
     * @param getHTTPRequest Statická metoda pro HTTP request
     */
    Application(int updateIntervalSec, std::function<std::string(std::string url)> getHTTPRequest);

    /**
     * @brief Získá data z internetu a převede na JSON objekt
     * TODO
     * @return JSONVar Objekt JSON
     */
    JSONVar requestJson(std::string httpUrlBase, std::string httpUrlParam);

    /**
     * @brief Vrátí název a popis třídy
     * 
     * Virtualní metoda
     * @return std::string Název a popis třídy
     */
    virtual std::string toString() = 0;

    /**
     * @brief Nastaví callback pro atualizaci displeje
     * 
     * Virtualní metoda
     * @param updateHandler Callback pro akutalizaci displeje
     */
    virtual void setUpdateHandler(std::function<int(void)> updateHandler) = 0;

    /**
     * @brief Callback vyvolaný po stisknutí prostředního tlačítka
     * 
     * Virtualní metoda
     */
    virtual void buttonClickMiddle() = 0;

    /**
     * @brief Callback vyvolaný po stisknutí pravého tlačítka
     * 
     * Virtualní metoda
     */
    virtual void buttonClickRight() = 0;

    virtual int showDataOnDisplay(GxEPD* display, JSONVar data) = 0;

    /**
     * @brief Aktualizuje obsah displeje
     * 
     * @param display GxEPD* ukazatel na displej
     * 
     * Virtualní metoda
     * @return int Vrací čas v ms za jak dlouho se má aplikace znovu aktualizovat
     */
    virtual int update(GxEPD* display);
};
