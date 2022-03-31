#include "AppSalina.hpp"
#include <Arduino_JSON.h>
#include <stdio.h>

#include <Fonts/FreeMono9pt7b.h>

AppSalina::AppSalina(std::function<std::string(std::string url)> _getHTTPRequest)
    : Application(_getHTTPRequest) {
    httpFetchUrl = "https://jsonplaceholder.typicode.com/todos/1";
    // httpFetchUrl = "https://mapa.idsjmk.cz/api/Departures";
}

AppSalina::~AppSalina() {
}

void AppSalina::buttonClickLeft() {
    printf("Pressed button LEFT\n");
    printf("%s\n", getHTTPRequest("https://jsonplaceholder.typicode.com/todos/1").c_str());
}

void AppSalina::buttonClickMiddle() {
    printf("Pressed button MIDDLE\n");
    printf("%s\n", getHTTPRequest("https://jsonplaceholder.typicode.com/todos/1").c_str());
}

void AppSalina::buttonClickRight() {
    printf("Pressed button RIGHT\n");
    printf("%s\n", getHTTPRequest("https://jsonplaceholder.typicode.com/todos/1").c_str());
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

// int AppSalina::update(GxGDEW027C44 &display) {
int AppSalina::update() {
    printf("%s\n", getHTTPRequest("https://jsonplaceholder.typicode.com/todos/1").c_str());
	// display.setCursor(0,0);
	// display.setTextColor(GxEPD_BLACK);
	// display.setFont(&FreeMono9pt7b);
	// display.println("Ahoj svete");
	// display.update();

	// display.setFont();

    return 44;
}
