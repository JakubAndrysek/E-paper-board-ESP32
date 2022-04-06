#include "Manager.hpp"
#include "apps/AppFablab.hpp"
#include "apps/AppSalina.hpp"
#include "credentials.h"
#include <stdio.h>

Manager::Manager(bool connectToWifi) {
    // array of applications
    applications.emplace_back(new AppSalina(&HttpFetcher::getHTTPRequest));
    applications.emplace_back(new AppFablab(&HttpFetcher::getHTTPRequest));

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

    if(connectToWifi) {
        WiFi.begin(ssid, password);
        printf("Connecting to WiFi\n");
        while (WiFi.status() != WL_CONNECTED) {
            // delay(500);
            // printf(".");
        }
        printf("Connected to WiFi network with IP Address: ");
        printf("%s\n\n", WiFi.localIP().toString().c_str());
        delay(100);
    }

    displayManager.test();
}

void Manager::run() {
    inputManager.loop();


}