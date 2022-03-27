#include "Manager.hpp"
#include "apps/AppFablab.hpp"
#include "apps/AppSalina.hpp"
#include <stdio.h>
#include "credentials.h"

Manager::Manager(/* args */) {
    // array of applications
    applications.emplace_back(new AppSalina(&HttpFetcher::getHTTPRequest));

    // applications.emplace_back(new AppFablab());

    // inputManager.btnLeft.setClickHandler(buttonClickLeft);
    // inputManager.btnMiddle.setClickHandler(buttonClickMiddle);
    // inputManager.btnRight.setClickHandler(buttonClickRight);

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

    printf("%d\n", applications[appIndex]->update());
    printf("%d\n", applications[appIndex]->update());
    printf("Konec\n");
}