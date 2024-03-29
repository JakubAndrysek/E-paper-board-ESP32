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
    httpUrlParams.insert(std::make_pair("marksLast", "/marksLast/"));
    httpUrlParams.insert(std::make_pair("marksSubject", "/marksSubject/"));
    httpUrlParamKey = httpUrlParams.begin()->first; // set first parameter as default
}

std::string AppSolMarks::toString() {
    return "AppSolMarks";
}

void AppSolMarks::buttonClickMiddle() {
    printf("Pressed button MIDDLE - %s\n", this->toString().c_str());
    httpUrlParamKey = "marksLast";
    appConfig.updateHandler();
}

void AppSolMarks::buttonClickRight() {
    printf("Pressed button RIGHT - %s\n", this->toString().c_str());
    httpUrlParamKey = "marksLast";
    appConfig.updateHandler();
}

int AppSolMarks::showDataOnDisplay(GxEPD* display, JSONVar data) {
    display->setFont(&FreeSans9pt8b);
    display->fillScreen(GxEPD_BG);
    display->setTextColor(GxEPD_TEXT_EX);
    display->setCursor(0, 15);
    display->println(printCz("Nejnověší známky ŠOL"));

    JSONVar marks = data["data"];
    for (int i = 0; i < marks.length(); i++) {
        JSONVar markLine = marks[i];
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
    char buffer[100];
    sprintf(buffer, "%s - %s - ", date.c_str(), substr(subject, 0, 18));
    display->print(printCz(buffer));

    display->setTextColor(GxEPD_TEXT_EX);
    display->println(printCz(mark));
}