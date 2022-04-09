#include "HttpFetcher.hpp"
#include "exception/HttpRequestException.h"
#include "exception/WifiConnException.h"
#include <WiFi.h>
#include <stdio.h>

HttpFetcher::HttpFetcher() {
}

HttpFetcher::~HttpFetcher() {
}

std::string HttpFetcher::getHTTPRequest(std::string url) {
    if (WiFi.status() != WL_CONNECTED) {
        throw WifiConnException();
    }

    HTTPClient http;

    http.begin(url.c_str());

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