/**
 * @file Manager.hpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Správce celého panelu
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#pragma once

#include "ArduinoMetronome.hpp"
#include "Button2.h"
#include "DisplayManager.hpp"
#include "HttpFetcher.hpp"
#include "InputManager.hpp"
#include "apps/AppConfig.hpp"
#include "apps/Application.hpp"
#include <WiFi.h>
#include <memory>
#include <vector>

/**
 * @brief Správce aplikací
 * 
 * Asd
 */
class Manager {
private:
    /**
     * @brief Objekt Správce vstupů 
     * 
     */
    InputManager inputManager;

    /**
     * @brief Objekt Správce displeje
     * 
     */
    DisplayManager displayManager;

    /**
     * @brief Metronom pro automatické překreslení aplikace
     * Po každé aktualizaci je nastaven nový čas následujícího překreslení
     */
    ArduinoMetronome metronomeTimer;

    /**
     * @brief Metronom pro automatické přepínání aplikací
     * Každých X sekund je aplikace přepnuta na další
     */
    ArduinoMetronome metronomeApp;

    /**
     * @brief Vketor ukazatelů na aplikace
     * 
     */
    std::vector<std::unique_ptr<Application>> applications;

    /**
     * @brief Index aktuálně zobrazované aplikace
     */
    int appIndex = 0;

    /**
     * @brief Výchozí konfigurace aplikací
     * 
     */
    AppConfig appConfig;

    /**
     * @brief Vykreslí vybranou aplikaci na displej
     * 
     * @return int Vrací čas v ms za jak dlouho se má aplikace znovu aktualizovat
     */
    int update();

    /**
     * @brief Připojí ESP na wifi - blokující
     * 
     * @param ssid Jméno sítě
     * @param passphrase Heslo sítě
     */
    void connectToWiFi(const char* ssid, const char* passphrase);

public:
    /**
     * @brief Konstruktor Manageru
     * 
     * Vytvoří správce aplikací, připojí ESP na wifi, inicializuje displej
     */
    Manager(bool connectToWifi = true);

    /**
     * @brief Hlavní smyčka správce aplikací
     * 
     * Zpracováva vstupy, volá překreslení aplikace
     */
    void run();
};
