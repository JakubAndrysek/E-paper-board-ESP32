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
    httpUrlParams.insert(std::make_pair("machinees1", "/fablabNow/"));
    httpUrlParamKey = httpUrlParams.begin()->first; // set first parameter as default
    machineKey = "machines";
}

std::string AppFablab::toString() {
    return "AppFablab";
}

void AppFablab::buttonClickMiddle() {
    printf("Pressed button MIDDLE - %s\n", this->toString().c_str());
    machineKey = "machines";
    appConfig.updateHandler();
}

void AppFablab::buttonClickRight() {
    printf("Pressed button RIGHT - %s\n", this->toString().c_str());
    machineKey = "printers";
    appConfig.updateHandler();
}

int AppFablab::showDataOnDisplay(GxEPD* display, JSONVar data) {
    display->setFont(&FreeSans9pt8b);
    display->fillScreen(GxEPD_BG);
    display->setTextColor(GxEPD_TEXT_EX);
    display->setCursor(0, 15);

    JSONVar fablab = data["data"];
    std::string members = (const char*)fablab["members"];
 
    display->println(printCz("Obsazenost FabLabu: " + members));
 
    JSONVar machines = fablab[machineKey.c_str()];
     
    for (int i = 0; i < machines.length(); i++) {
        JSONVar markLine = machines[i];
        std::string name = (const char*)markLine["name"];
        std::string subject = (const char*)markLine["status"];
        showMachineLine(display, name, subject);
    }

    display->update();
    return secToMs(updateIntervalSec);
}

void AppFablab::showMachineLine(GxEPD* display, std::string name, std::string status) {
    display->setTextColor(GxEPD_TEXT);
    char buffer[100];
    sprintf(buffer, "%s -", name.c_str());
    display->print(printCz(buffer));

    display->setTextColor(GxEPD_TEXT_EX);
    display->println(printCz(substr(status, 0, 18)));
}