/**
 * @file Manager.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Správce celého panelu
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "Manager.hpp"
#include "apps/AppFablab.hpp"
#include "apps/AppSalina.hpp"
#include "credentials.h"
#include "exception/JsonParseException.h"
#include <iostream>
#include <stdio.h>

Manager::Manager(bool WiFiConnect) {
    // array of applications
    applications.emplace_back(new AppSalina(&HttpFetcher::getHTTPRequest));
    applications.emplace_back(new AppFablab(&HttpFetcher::getHTTPRequest));

    for (auto it = applications.begin(); it != applications.end(); ++it) {
        (*it)->setUpdateHandler(std::bind(&Manager::update, this));
    }

    inputManager.btnLeft.setClickHandler([&](Button2& btn) {
        appIndex = (appIndex + 1) % applications.size();
        printf("appIndex: %d -> %s\n", appIndex, applications[appIndex]->toString().c_str());
    });

    inputManager.btnMiddle.setClickHandler([&](Button2& btn) {
        applications[appIndex]->buttonClickMiddle();
    });

    inputManager.btnRight.setClickHandler([&](Button2& btn) {
        applications[appIndex]->buttonClickRight();
    });

    if (WiFiConnect) {
        connectToWiFi(ssid, password);
    }

    displayManager.init();
    update();
}

int Manager::update() {
    try {
        return applications[appIndex]->update(displayManager.display);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        displayManager.showError(e.what());
    }
    return -1;
}

void Manager::connectToWiFi(const char* ssid, const char* passphrase) {
    WiFi.begin(ssid, passphrase);
    delay(80);
    printf("Connecting to WiFi\n");
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        printf(".");
    }
    printf("Connected to WiFi network with IP Address: ");
    printf("%s\n\n", WiFi.localIP().toString().c_str());
    // delay(100);
}

void Manager::run() {
    inputManager.loop();
}