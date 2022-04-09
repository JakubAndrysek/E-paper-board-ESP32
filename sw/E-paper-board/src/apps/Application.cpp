#include "Application.hpp"
#include "exception/JsonParseException.h"
#include <stdio.h>

Application::Application(std::function<std::string(std::string url)> getHTTPRequest) {
    this->getHTTPRequest = getHTTPRequest;
    this->updateHandler = nullptr;
}

JSONVar Application::requestJson() {
    auto payload = getHTTPRequest(httpFetchUrl + httpFetchUrlParameter);
    JSONVar httpPayload = JSON.parse(payload.c_str());

    if (JSON.typeof(httpPayload) == "undefined") {
        Serial.println("DUPLICATED: Parsing input failed!");
        throw JsonParseException();
    }
    return httpPayload;
}

std::string Application::jsonToStr(JSONVar json) {
    return JSON.stringify(json).c_str();
}