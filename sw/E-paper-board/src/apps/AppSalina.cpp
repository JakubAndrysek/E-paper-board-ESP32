#include "AppSalina.hpp"
#include <Arduino_JSON.h>
#include <stdio.h>

AppSalina::AppSalina(std::function<std::string(std::string url)> _getHTTPRequest)
    : Application(_getHTTPRequest) {
    httpFetchUrl = "https://jsonplaceholder.typicode.com/todos/1";
    // httpFetchUrl = "https://mapa.idsjmk.cz/api/Departures";
}

AppSalina::~AppSalina() {
}

void AppSalina::buttonClickLeft() {
    printf("Pressed button LEFT\n");
}

void AppSalina::buttonClickMiddle() {
    printf("Pressed button MIDDLE\n");
}

void AppSalina::buttonClickRight() {
    printf("Pressed button RIGHT\n");
}

// JSONVar AppSalina::prepareSalinaStop(std::string stopParameters) {
//     auto payload = getHTTPRequest(httpFetchUrl + stopParameters);
//     JSONVar httpPayload = JSON.parse(payload.c_str());

// 	if (JSON.typeof(httpPayload) == "undefined")
// 	{
// 		Serial.println("Parsing input failed!");
// 		return new JSONVar();
// 	}	
// }

int AppSalina::update() {
    printf("%s\n", getHTTPRequest("https://jsonplaceholder.typicode.com/todos/1").c_str());
    return 44;
}
