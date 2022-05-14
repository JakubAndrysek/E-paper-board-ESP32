/**
 * @file AppAlojz.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Modul aplikace pro zobrazování aktuálního počasí z aplikace Alojz.cz
 * @date 2022-04-27
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "AppAlojz.hpp"
#include <Arduino_JSON.h>
#include <stdio.h>

#include "fontsCz/FreeSans9pt8bfr.h"
#include "utils/utils.hpp"

AppAlojz::AppAlojz(int updateIntervalSec, AppConfig& appConfig)
    : Application(updateIntervalSec, appConfig) {
    httpUrlParams.insert(std::make_pair("Brno", "/alojz?alojzId=brno&lat=49.195060&lon=16.606837&alt=237"));
    httpUrlParamKey = httpUrlParams.begin()->first; // set first parameter as default
    dayKey = "day1";
}

std::string AppAlojz::toString() {
    return "AppAlojz";
}

void AppAlojz::buttonClickMiddle() {
    printf("Pressed button MIDDLE - %s\n", this->toString().c_str());
    dayKey = "day1";
    appConfig.updateHandler();
}

void AppAlojz::buttonClickRight() {
    printf("Pressed button RIGHT - %s\n", this->toString().c_str());
    dayKey = "day2";
    appConfig.updateHandler();
}

int AppAlojz::showDataOnDisplay(GxEPD* display, JSONVar data) {
    display->setFont(&FreeSans9pt8b);
    display->fillScreen(GxEPD_BG);
    display->setTextColor(GxEPD_TEXT_EX);
    display->setCursor(0, 15);
    display->println(printCz(std::string("Počasí Alojz: ") + httpUrlParamKey));

    JSONVar weather = data["data"];
    JSONVar weatherDay = weather[dayKey.c_str()];

    std::string today_tomorrow = (const char*)weatherDay["today_tomorrow"];
    std::string string = (const char*)weatherDay["string"] ? (const char*)weatherDay["string"] : "";

    display->setTextColor(GxEPD_TEXT);
    display->println(printCz(today_tomorrow));
    display->setTextColor(GxEPD_TEXT_EX);
    display->println(printCz(string));

    display->update();
    return secToMs(updateIntervalSec);
}