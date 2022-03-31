#include "Manager.hpp"
#include "apps/AppFablab.hpp"
#include "apps/AppSalina.hpp"
#include "credentials.h"
#include <stdio.h>

Manager::Manager(/* args */) {
    // array of applications
    applications.emplace_back(new AppSalina(&HttpFetcher::getHTTPRequest));

    // applications.emplace_back(new AppFablab());

    inputManager.btn2Left.setClickHandler([&](Button2 &btn) {
        applications[appIndex]->update();
    });
    // inputManager.btnMiddle.setClickHandler(buttonClickMiddle);
    // inputManager.btnRight.setClickHandler(buttonClickRight);

    // WiFi.begin(ssid, password);
    // printf("Connecting to WiFi\n");
    // while (WiFi.status() != WL_CONNECTED) {
    //     // delay(500);
    //     // printf(".");
    // }
    // printf("Connected to WiFi network with IP Address: ");
    // printf("%s\n\n", WiFi.localIP().toString().c_str());
    // delay(100);
}

Manager::~Manager() {
}

void Manager::buttonClickLeft(Button2& btn) {
    applications[appIndex]->buttonClickLeft();
}

void Manager::buttonClickMiddle(Button2& btn) {
    applications[appIndex]->buttonClickMiddle();
}

void Manager::buttonClickRight(Button2& btn) {
    applications[appIndex]->buttonClickRight();
}

void Manager::run() {

    inputManager.buttonLeft.checkPressed();
    delay(300);
    // printf("Loop\n");

    // displayManager.display->setTextColor(GxEPD_BLACK);
    // displayManager.display->setFont(&FreeSans9pt7b);
    // displayManager.display->println("Funguje");
    // displayManager.display->update();

    // try {
    //     printf("%d\n", applications[appIndex]->update());
    // } catch (HttpRequestError& e) {
    //     printf("ERROR: %s\n", e.what());
    // }
    // printf("End\n");
}