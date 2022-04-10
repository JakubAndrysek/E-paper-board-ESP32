/**
 * @file AppSalina.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Modul aplikace pro monitorování šalin v IDSJMK
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "AppSalina.hpp"
#include <stdio.h>

#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSansBold12pt7b.h>

AppSalina::AppSalina(std::function<std::string(std::string url)> getHTTPRequest)
    : Application(getHTTPRequest) {
    httpFetchUrl = "http://192.168.0.5:3333";
    httpFetchUrlParameter = "/1272";
    // httpFetchUrl = "https://mapa.idsjmk.cz/api/Departures";
}

std::string AppSalina::toString() {
    return "AppSalina";
}

void AppSalina::setUpdateHandler(std::function<int(void)> updateHandler) {
    this->updateHandler = updateHandler;
}

void AppSalina::buttonClickMiddle() {
    printf("Pressed button MIDDLE\n");
    httpFetchUrlParameter = "/1272";
    updateHandler();
}

void AppSalina::buttonClickRight() {
    httpFetchUrlParameter = "/1377";
    updateHandler();
    printf("Pressed button RIGHT\n");
}

void AppSalina::showStopLine(GxEPD* display, std::string LineName, std::string TimeMark, std::string FinalStop) {
    char buffer[100];
    display->setTextColor(GxEPD_BLACK);
    sprintf(buffer, "- %s (%s) %s\n", LineName.c_str(), TimeMark.c_str(), FinalStop.c_str());
    display->print(buffer);
    printf("%s\n", buffer);
}

void AppSalina::showDeparture(GxEPD* display, JSONVar salinaStop) {
    JSONVar StopID = salinaStop["StopID"];
    printf("%s\n", JSON.stringify(StopID).c_str());

    display->fillScreen(GxEPD_WHITE);
    display->setCursor(0, 8);
    display->setTextColor(GxEPD_RED);
    display->setFont(&FreeSans9pt7b);
    display->printf("Odjezdy salin - %s\n", JSON.stringify(StopID).c_str());

    JSONVar PostList0 = salinaStop["PostList"][0];
    JSONVar Departures = PostList0["Departures"];

    JSONVar Departures0 = Departures[0];

    for (int i = 0; i < Departures.length(); i++) {
        JSONVar Departure = Departures[i];

        std::string LineName = (const char*)Departure["LineName"];
        std::string TimeMark = (const char*)Departure["TimeMark"];
        std::string FinalStop = (const char*)Departure["FinalStop"];
        showStopLine(display, LineName, TimeMark, FinalStop);
    }

    display->update();
}

// int AppSalina::update(GxGDEW027C44 &display) {
int AppSalina::update(GxEPD* display) {
    printf("%s\n", this->toString().c_str());
    JSONVar salinaStop = requestJson();
    showDeparture(display, salinaStop);
    return 44;
}
