#include "AppFablab.hpp"
#include <Arduino_JSON.h>
#include <stdio.h>

#include <Fonts/FreeMono9pt7b.h>

AppFablab::AppFablab(std::function<std::string(std::string url)> getHTTPRequest)
    : Application(getHTTPRequest) {
    httpFetchUrl = "https://jsonplaceholder.typicode.com/todos/1";
    // httpFetchUrl = "https://mapa.idsjmk.cz/api/Departures";
}

std::string AppFablab::toString() {
    return "AppFablab";
}

void AppFablab::buttonClickLeft() {
    printf("Pressed button LEFT\n");
}

void AppFablab::buttonClickMiddle() {
    printf("Pressed button MIDDLE\n");
}

void AppFablab::buttonClickRight() {
    printf("Pressed button RIGHT\n");
}

// JSONVar AppFablab::prepareSalinaStop(std::string stopParameters) {
//     auto payload = getHTTPRequest(httpFetchUrl + stopParameters);
//     JSONVar httpPayload = JSON.parse(payload.c_str());

// 	if (JSON.typeof(httpPayload) == "undefined")
// 	{
// 		Serial.println("Parsing input failed!");
// 		return new JSONVar();
// 	}
// }

// int AppFablab::update(GxGDEW027C44 &display) {
int AppFablab::update() {
    printf("%s\n", getHTTPRequest("https://jsonplaceholder.typicode.com/todos/1").c_str());
    // display.setCursor(0,0);
    // display.setTextColor(GxEPD_BLACK);
    // display.setFont(&FreeMono9pt7b);
    // display.println("Ahoj svete");
    // display.update();

    // display.setFont();

    return 44;
}
