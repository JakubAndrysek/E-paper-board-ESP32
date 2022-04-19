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

AppFablab::AppFablab(std::function<std::string(std::string url)> getHTTPRequest)
    : Application(getHTTPRequest) {
    httpUrlBase = "http://baseUrl";
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

int AppFablab::update(GxEPD* display) {
    display->setFont(&FreeSans9pt8b);
    display->fillScreen(GxEPD_WHITE);
    display->setTextColor(GxEPD_RED);
    display->setCursor(0, 15);
    display->println(printCz(std::string("TemplateApp - ") + httpUrlParamKey));
    display->setTextColor(GxEPD_BLACK);
    display->println(printCz(std::string("Url: - ") + httpUrlParams.at(httpUrlParamKey)));
    display->update();
    return 44;
}
