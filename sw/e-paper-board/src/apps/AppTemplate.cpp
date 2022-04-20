/**
 * @file AppTemplate.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Modul aplikace pro zobrazování obsazenosti FabLabu
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "AppTemplate.hpp"
#include <Arduino_JSON.h>
#include <stdio.h>

#include "fontsCz/FreeSans9pt8bfr.h"
#include "utils/utils.hpp"

AppTemplate::AppTemplate(int updateIntervalSec, std::function<std::string(std::string url)> getHTTPRequest)
    : Application(updateIntervalSec, getHTTPRequest) {
    httpUrlBase = "http://baseUrl";
    httpUrlParams.insert(std::make_pair("key1", "/key1json"));
    httpUrlParams.insert(std::make_pair("key2", "/key2json"));
    httpUrlParamKey = httpUrlParams.begin()->first; // set first parameter as default
}

std::string AppTemplate::toString() {
    return "AppTemplate";
}

void AppTemplate::setUpdateHandler(std::function<int(void)> updateHandler) {
    this->updateHandler = updateHandler;
}

void AppTemplate::buttonClickMiddle() {
    printf("Pressed button MIDDLE - %s\n", this->toString().c_str());
    httpUrlParamKey = "key1";
    updateHandler();
}

void AppTemplate::buttonClickRight() {
    printf("Pressed button RIGHT - %s\n", this->toString().c_str());
    httpUrlParamKey = "key2";
    updateHandler();
}

int AppTemplate::showDataOnDisplay(GxEPD* display, JSONVar data) {
    display->setFont(&FreeSans9pt8b);
    display->fillScreen(GxEPD_WHITE);
    display->setTextColor(GxEPD_RED);
    display->setCursor(0, 15);
    display->println(printCz(this->toString() + httpUrlParamKey));
    display->setTextColor(GxEPD_BLACK);
    display->println(printCz(std::string("Url base: - ") + httpUrlBase));
    display->println(printCz(std::string("Url param: - ") + httpUrlParams.at(httpUrlParamKey)));
    display->update();
    return secToMs(updateIntervalSec);
}

int AppTemplate::update(GxEPD* display) {
    return showDataOnDisplay(display, JSONVar());
}