/**
 * @file HttpFetcher.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Http Fetcher - získává data z internetu
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "HttpFetcher.hpp"
#include "exception/HttpRequestException.h"
#include "exception/WifiConnException.h"
#include <WiFi.h>
#include <stdio.h>

HttpFetcher::HttpFetcher() {
}

std::string HttpFetcher::getHTTPRequest(std::string url) {
    printf("HTTP GET: %s\n", url.c_str());
    if (WiFi.status() != WL_CONNECTED) {
        throw WifiConnException();
    }

    HTTPClient http;

    http.begin(url.c_str());
    http.setTimeout(8000);
    int httpResponseCode = http.GET();

    std::string payload = "{}";

    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString().c_str();
    } else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
        throw HttpRequestException();
    }
    // Free resources
    http.end();

    return payload;
}