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

#include "Button2.h"
#include "DisplayManager.hpp"
#include "HttpFetcher.hpp"
#include "InputManager.hpp"
#include "apps/Application.hpp"
#include "ArduinoMetronome.hpp"
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
    InputManager inputManager;
    DisplayManager displayManager;
    ArduinoMetronome metronomeTimer;
    ArduinoMetronome metronomeApp;
    std::vector<std::unique_ptr<Application>> applications;

    int appIndex = 0;

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
