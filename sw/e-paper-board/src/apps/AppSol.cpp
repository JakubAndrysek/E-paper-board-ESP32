/**
 * @file AppSol.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Modul aplikace pro zobrazování obsazenosti FabLabu
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "AppSol.hpp"
#include <Arduino_JSON.h>
#include <stdio.h>

#include "fontsCz/FreeSans9pt8bfr.h"
#include "utils/utils.hpp"

AppSol::AppSol(std::function<std::string(std::string url)> getHTTPRequest)
    : Application(getHTTPRequest) {
    httpUrlBase = "http://192.168.0.15:5000";
    httpUrlParams.insert(std::make_pair("lastMarks", "/lastMarks"));
    httpUrlParams.insert(std::make_pair("timeTable", "/timeTable"));
    httpUrlParamKey = httpUrlParams.begin()->first; // set first parameter as default
}

std::string AppSol::toString() {
    return "AppSol";
}

void AppSol::setUpdateHandler(std::function<int(void)> updateHandler) {
    this->updateHandler = updateHandler;
}

void AppSol::buttonClickMiddle() {
    printf("Pressed button MIDDLE - %s\n", this->toString().c_str());
    httpUrlParamKey = "lastMarks";
    updateHandler();
}

void AppSol::buttonClickRight() {
    printf("Pressed button RIGHT - %s\n", this->toString().c_str());
    httpUrlParamKey = "timeTable";
    updateHandler();
}

int AppSol::update(GxEPD* display) {
    display->setFont(&FreeSans9pt8b);
    display->fillScreen(GxEPD_WHITE);
    display->setTextColor(GxEPD_RED);
    display->setCursor(0, 15);
    display->println(printCz(this->toString() + httpUrlParamKey));
    display->setTextColor(GxEPD_BLACK);
    display->println(printCz(std::string("Url base: - ") + httpUrlBase));
    display->println(printCz(std::string("Url param: - ") + httpUrlParams.at(httpUrlParamKey)));
    display->update();
    return 44;
}
