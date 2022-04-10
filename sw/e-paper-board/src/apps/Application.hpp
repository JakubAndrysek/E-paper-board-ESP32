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
#include <memory>
#include <string>

/**
 * @brief Výchozí aplikace
 * 
 */
class Application {
private:
protected:
    std::string httpFetchUrl;
    std::string httpFetchUrlParameter;

    std::function<std::string(std::string url)> getHTTPRequest;
    std::function<int(void)> updateHandler;

public:
    /**
     * @brief Konstruktor výchozí aplikace
     * 
     * @param getHTTPRequest Statická metoda pro HTTP request
     */
    Application(std::function<std::string(std::string url)> getHTTPRequest);

    /**
     * @brief Získá data z internetu a převede na JSON objekt
     * 
     * @return JSONVar Objekt JSON
     */
    JSONVar requestJson();

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

    /**
     * @brief 
     * 
     * @param display GxEPD* ukazatel na displej
     * 
     * Virtualní metoda
     * @return int Vrací čas v ms za jak dlouho se má aplikace znovu aktualizovat
     */
    virtual int update(GxEPD* display) = 0;
};
