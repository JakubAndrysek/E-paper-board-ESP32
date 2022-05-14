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
#include "exception/JsonEmptyObjectException.h"
#include "exception/JsonParseException.h"
#include "exception/JsonBadFormatObjectException.h"
#include <stdio.h>

Application::Application(int updateIntervalSec, AppConfig& appConfig)
    : appConfig(appConfig) {
    // this->updateHandler = nullptr;
    this->updateIntervalSec = updateIntervalSec;
}

JSONVar Application::requestJson(std::string httpUrlBase, std::string httpUrlParam) {
    // if(httpUrlParam.find("?") == std::string::npos) {
    //     httpUrlParam = httpUrlParam + "?api_key=" + appConfig.apiKey;
    // // } else if(httpUrlParam.find("&")==std::string::npos) {
    // //     httpUrlParam = httpUrlParam + "&api_key=" + appConfig.apiKey;
    // } else {
    //     httpUrlParam = httpUrlParam + "&api_key=" + appConfig.apiKey;
    // }

    auto payload = appConfig.getHTTPRequest(httpUrlBase + httpUrlParam);

    printf("Request payload: %s\n", payload.c_str());
    JSONVar httpPayload = JSON.parse(payload.c_str());

    if (JSON.typeof(httpPayload) == "undefined") {
        printf("DUPLICATED: Parsing input failed!\n");
        throw JsonParseException();
    }

    // {"data": "Nen\u00ed zad\u00e1no stop_id nebo post_id", "status": "error"}
    if (!httpPayload.hasOwnProperty("status") || !httpPayload.hasOwnProperty("data")) {
        Serial.println("DUPLICATED: JSON object is empty or does't have properity 'status' or 'data'!");
        throw JsonEmptyObjectException();
    }

    // {"data": "Nen\u00ed zad\u00e1no stop_id nebo post_id", "status": "error"}
    Serial.print("Status:");
    Serial.println((const char*)httpPayload["status"]);

    // if(((const char*)httpPayload["status"]) == "error") {
    //     Serial.println( std::string((const char*)httpPayload["data"]).c_str() );
    //     throw JsonBadFormatObjectException();
    // }

    // static JSONVar data = httpPayload["data"];

    // Serial.println(JSONVar::stringify(data).c_str());
    // return data;
    Serial.println("OK-JSON");
    return httpPayload;
}

int Application::getUpdateIntervalSec() {
    return this->updateIntervalSec;
}

int Application::update(GxEPD* display) {
    JSONVar data = requestJson(appConfig.httpUrlBase, httpUrlParams.at(httpUrlParamKey));
    return showDataOnDisplay(display, data);
}