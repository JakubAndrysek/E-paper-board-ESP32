/**
 * @file AppFablab.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Modul aplikace pro zobrazování obsazenosti FabLabu
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "AppFablab.hpp"
#include <Arduino_JSON.h>
#include <stdio.h>

#include "fontsCz/FreeSans9pt8bfr.h"
#include "utils/utils.hpp"

AppFablab::AppFablab(int updateIntervalSec, AppConfig& appConfig)
    : Application(updateIntervalSec, appConfig) {
    // httpUrlBase = "http://baseUrl";
    httpUrlParams.insert(std::make_pair("key1", "/key1json"));
    httpUrlParams.insert(std::make_pair("key2", "/key2json"));
    httpUrlParamKey = httpUrlParams.begin()->first; // set first parameter as default
}

std::string AppFablab::toString() {
    return "AppFablab";
}

void AppFablab::setUpdateHandler(std::function<int(void)> updateHandler) {
    this->updateHandler = updateHandler;
}

void AppFablab::buttonClickMiddle() {
    printf("Pressed button MIDDLE - %s\n", this->toString().c_str());
    httpUrlParamKey = "key1";
    updateHandler();
}

void AppFablab::buttonClickRight() {
    printf("Pressed button RIGHT - %s\n", this->toString().c_str());
    httpUrlParamKey = "key2";
    updateHandler();
}

int AppFablab::showDataOnDisplay(GxEPD* display, JSONVar data) {
    display->setFont(&FreeSans9pt8b);
    display->fillScreen(GxEPD_BG);
    display->setTextColor(GxEPD_TEXT_EX);
    display->setCursor(0, 15);
    display->println(printCz(this->toString() + httpUrlParamKey));
    display->setTextColor(GxEPD_TEXT);
    display->println(printCz(std::string("Url base: - ") + appConfig.httpUrlBase));
    display->println(printCz(std::string("Url param: - ") + httpUrlParams.at(httpUrlParamKey)));
    display->update();
    return secToMs(updateIntervalSec);
}

int AppFablab::update(GxEPD* display) {
    return showDataOnDisplay(display, JSONVar());
}