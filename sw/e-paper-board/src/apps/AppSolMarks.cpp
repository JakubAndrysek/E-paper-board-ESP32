/**
 * @file AppSolMarks.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Modul aplikace pro zobrazování nejnovějších známek ze systému Škola Online
 * @date 2022-04-19
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "AppSolMarks.hpp"
#include <Arduino_JSON.h>
#include <stdio.h>

#include "fontsCz/FreeSans9pt8bfr.h"
#include "utils/utils.hpp"

AppSolMarks::AppSolMarks(int updateIntervalSec, AppConfig& appConfig)
    : Application(updateIntervalSec, appConfig) {
    // httpUrlBase = "http://192.168.0.15:5000"; // Pletacka
    // httpUrlBase = "http://192.168.0.5:5000"; // Rotex
    // httpUrlBase = "http://192.168.42.22:5000"; // Technika
    // httpUrlBase = "http://panel.kubaandrysek.cz:3266"; // Rotex
    httpUrlParams.insert(std::make_pair("marksLast", "/marksLast/?api_key=P@n3l"));
    httpUrlParams.insert(std::make_pair("marksSubject", "/marksSubject/"));
    httpUrlParamKey = httpUrlParams.begin()->first; // set first parameter as default
}

std::string AppSolMarks::toString() {
    return "AppSolMarks";
}

void AppSolMarks::setUpdateHandler(std::function<int(void)> updateHandler) {
    this->updateHandler = updateHandler;
}

void AppSolMarks::buttonClickMiddle() {
    printf("Pressed button MIDDLE - %s\n", this->toString().c_str());
    httpUrlParamKey = "marksLast";
    updateHandler();
}

void AppSolMarks::buttonClickRight() {
    printf("Pressed button RIGHT - %s\n", this->toString().c_str());
    httpUrlParamKey = "marksSubject";
    updateHandler();
}

int AppSolMarks::showDataOnDisplay(GxEPD* display, JSONVar data) {
    display->setFont(&FreeSans9pt8b);
    display->fillScreen(GxEPD_BG);
    display->setTextColor(GxEPD_TEXT_EX);
    display->setCursor(0, 15);
    display->println(printCz("Nejnověší známky ŠOL"));

    for (int i = 0; i < data.length(); i++) {
        JSONVar markLine = data[i];
        std::string date = (const char*)markLine["date"];
        std::string subject = (const char*)markLine["subject"];
        std::string mark = (const char*)markLine["mark"];
        showMarkLine(display, date, subject, mark);
    }

    display->update();
    return secToMs(updateIntervalSec);
}

void AppSolMarks::showMarkLine(GxEPD* display, std::string date, std::string subject, std::string mark) {
    display->setTextColor(GxEPD_TEXT);
    display->print(printCz(date + " - " + subject + " - "));
    display->setTextColor(GxEPD_TEXT_EX);
    display->println(printCz(mark));
}