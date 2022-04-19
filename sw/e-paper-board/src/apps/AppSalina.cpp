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

#include "fontsCz/FreeSans9pt8bfr.h"
#include "fontsCz/FreeSansBold12pt8bfr.h"
#include "utils/utils.hpp"

AppSalina::AppSalina(std::function<std::string(std::string url)> getHTTPRequest)
    : Application(getHTTPRequest) {
    httpUrlBase = "http://192.168.0.15:3333";
    // httpUrlBase = "http://192.168.42.22:3333";
    // httpUrlBase = "https://mapa.idsjmk.cz/api/Departures";

    httpUrlParams.insert(std::make_pair("Kořístkova", "/1272"));
    httpUrlParams.insert(std::make_pair("Med škola->Z", "/1377"));
    httpUrlParamKey = httpUrlParams.begin()->first; // set first parameter as default
}

std::string AppSalina::toString() {
    return "AppSalina";
}

void AppSalina::setUpdateHandler(std::function<int(void)> updateHandler) {
    this->updateHandler = updateHandler;
}

void AppSalina::buttonClickMiddle() {
    printf("Pressed button MIDDLE - %s\n", this->toString().c_str());
    httpUrlParamKey = "Kořístkova";
    updateHandler();
}

void AppSalina::buttonClickRight() {
    printf("Pressed button RIGHT - %s\n", this->toString().c_str());
    httpUrlParamKey = "Med škola->Z";
    updateHandler();
}

void AppSalina::showStopLine(GxEPD* display, std::string LineName, std::string TimeMark, std::string FinalStop) {
    char buffer[100];
    display->setTextColor(GxEPD_BLACK);
    sprintf(buffer, "- %s (%s) %s", LineName.c_str(), TimeMark.c_str(), FinalStop.c_str());
    display->println(printCz(buffer));
    printf("%s\n", buffer);
}

void AppSalina::showDeparture(GxEPD* display, JSONVar salinaStop) {
    JSONVar StopID = salinaStop["StopID"];
    printf("%s\n", JSON.stringify(StopID).c_str());

    display->setFont(&FreeSans9pt8b);
    display->fillScreen(GxEPD_WHITE);
    display->setTextColor(GxEPD_RED);
    display->setCursor(0, 8);
    display->println(printCz(std::string("Odjezdy šalin - ") + httpUrlParamKey));

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
    JSONVar salinaStop = requestJson(httpUrlBase, httpUrlParams.at(httpUrlParamKey));
    showDeparture(display, salinaStop);
    return 44;
}
