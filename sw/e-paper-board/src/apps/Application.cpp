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

Application::Application(std::function<std::string(std::string url)> getHTTPRequest) {
    this->getHTTPRequest = getHTTPRequest;
    this->updateHandler = nullptr;
}

JSONVar Application::requestJson(std::string httpUrlBase, std::string httpUrlParam) {
    auto payload = getHTTPRequest(httpUrlBase + httpUrlParam);
    JSONVar httpPayload = JSON.parse(payload.c_str());

    if (JSON.typeof(httpPayload) == "undefined") {
        Serial.println("DUPLICATED: Parsing input failed!");
        throw JsonParseException();
    }

    // printf("JSON: %s\n", JSON.stringify(httpPayload).c_str());

    // if(!httpPayload.hasOwnProperty("StopID")) {
    //     Serial.println("DUPLICATED: JSON object is empty!");
    //     throw JsonEmptyObjectException();
    // }

    return httpPayload;
}