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
#include "apps/AppSolMarks.hpp"
#include "apps/AppTemplate.hpp"
#include "credentials.h"
#include "exception/JsonParseException.h"
#include <iostream>
#include <stdio.h>

Manager::Manager(bool WiFiConnect) {
    metronomeTimer.intervalSet(20000);
    // array of applications
    applications.emplace_back(new AppSolMarks(30, &HttpFetcher::getHTTPRequest));
    applications.emplace_back(new AppSalina(20, &HttpFetcher::getHTTPRequest));
    applications.emplace_back(new AppTemplate(60, &HttpFetcher::getHTTPRequest));
    applications.emplace_back(new AppFablab(120, &HttpFetcher::getHTTPRequest));

    for (auto it = applications.begin(); it != applications.end(); ++it) {
        (*it)->setUpdateHandler(std::bind(&Manager::update, this));
    }

    inputManager.btnLeft.setClickHandler([&](Button2& btn) {
        appIndex = (appIndex + 1) % applications.size();
        printf("appIndex: %d -> %s\n", appIndex, applications[appIndex]->toString().c_str());
        update();
    });

    inputManager.btnMiddle.setClickHandler([&](Button2& btn) {
        applications[appIndex]->buttonClickMiddle();
        update();
    });

    inputManager.btnRight.setClickHandler([&](Button2& btn) {
        applications[appIndex]->buttonClickRight();
        update();
    });

    if (WiFiConnect) {
        connectToWiFi(ssid, password);
    }
    displayManager.init();

    update();
}

int Manager::update() {
    try {
        printf("Calling update: %s\n", applications[appIndex]->toString().c_str());
        return applications[appIndex]->update(displayManager.display);
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
        displayManager.showError(e.what());
    }
    metronomeTimer.timeReset();
    return 10000; // try
}

void Manager::connectToWiFi(const char* ssid, const char* passphrase) {
    printf("Connecting to WiFi\n");
    WiFi.begin(ssid, passphrase);
    displayManager.wifiConnectInfo(ssid, passphrase);
    delay(80);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        printf(".");
    }
    printf("Connected to WiFi network with IP Address: ");
    printf("%s\n\n", WiFi.localIP().toString().c_str());
}

void Manager::run() {
    inputManager.loop();

    if (metronomeTimer.loopMs()) {
        int newInterval = update();
        metronomeTimer.intervalSet(newInterval);
    }
}
