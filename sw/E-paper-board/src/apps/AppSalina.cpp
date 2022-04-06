#include "AppSalina.hpp"
#include <stdio.h>

#include <Fonts/FreeSansBold12pt7b.h>
#include <Fonts/FreeSans9pt7b.h>

AppSalina::AppSalina(GxEPD *display, std::function<std::string(std::string url)> getHTTPRequest)
    : Application(display, getHTTPRequest) {
    httpFetchUrl = "http://192.168.0.15:3333";
    stopParameters = "/1272";
    // httpFetchUrl = "https://mapa.idsjmk.cz/api/Departures";
}

std::string AppSalina::toString() {
    return "AppSalina";
}


void AppSalina::buttonClickMiddle() {
    printf("Pressed button MIDDLE\n");

    display->setTextColor(GxEPD_BLACK);
    display->setFont(&FreeSansBold12pt7b);
    display->print("Z: Semilasso\n");

    display->setFont(&FreeSans9pt7b);
    // showStopLine("1min", "2 min");
    // showStopLine("13min");

    display->drawRect(0, 0, display->width(), display->height(), GxEPD_BLACK);
    display->update();    

    update();
}

void AppSalina::buttonClickRight() {
    printf("Pressed button RIGHT\n");
}

JSONVar AppSalina::prepareSalinaStop(std::string stopParameters) {
    std::string payload = getHTTPRequest(httpFetchUrl + stopParameters);
    JSONVar httpPayload = JSON.parse(payload.c_str());
    printf("%s\n", payload.c_str());

	if (JSON.typeof(httpPayload) == "undefined")
	{
		Serial.println("Parsing input failed!");
		return new JSONVar();
	}

    return httpPayload;
}

void AppSalina::showDeparture(JSONVar salinaStop) {
    JSONVar StopID = salinaStop["StopID"];
    printf("%s\n", JSON.stringify(StopID).c_str());
}

// int AppSalina::update(GxGDEW027C44 &display) {
int AppSalina::update() {
    printf("%s\n", this->toString().c_str());
    JSONVar salinaStop = prepareSalinaStop(stopParameters);
    showDeparture(salinaStop);

    // display.setCursor(0,0);
    // display.setTextColor(GxEPD_BLACK);
    // display.setFont(&FreeMono9pt7b);
    // display.println("Ahoj svete");
    // display.update();

    // display.setFont();

    return 44;
}
