/**
 * @file Application.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Rodičovská virtuální aplikace
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "Application.hpp"
#include "exception/JsonParseException.h"
#include "exception/JsonEmptyObjectException.h"
#include <stdio.h>

Application::Application(int updateIntervalSec, AppConfig& appConfig) :
    appConfig(appConfig) {
    this->updateHandler = nullptr;
    this->updateIntervalSec = updateIntervalSec;
}

JSONVar Application::requestJson(std::string httpUrlBase, std::string httpUrlParam) {
    auto payload = appConfig.getHTTPRequest(httpUrlBase + httpUrlParam);
    printf("Request payload: %s\n", payload.c_str());
    JSONVar httpPayload = JSON.parse(payload.c_str());

    if (JSON.typeof(httpPayload) == "undefined") {
        printf("DUPLICATED: Parsing input failed!\n");
        throw JsonParseException();
    }

    // printf("JSON: %s\n", JSON.stringify(httpPayload).c_str());

    // if(!httpPayload.hasOwnProperty("StopID")) {
    //     Serial.println("DUPLICATED: JSON object is empty!");
    //     throw JsonEmptyObjectException();
    // }

    return httpPayload;
}

int Application::getUpdateIntervalSec() {
    return this->updateIntervalSec;
}

int Application::update(GxEPD* display) {
    JSONVar data = requestJson(appConfig.httpUrlBase, httpUrlParams.at(httpUrlParamKey));
    return showDataOnDisplay(display, data);
}