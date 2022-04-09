#pragma once

#include "Application.hpp"
#include <Arduino_JSON.h>
#include <GxGDEW027C44/GxGDEW027C44.h>
#include <functional>

class AppSalina : public Application {
private:
    // std::string stopParameters;
public:
    AppSalina(GxEPD *display, std::function<std::string(std::string url)> getHTTPRequest);
    std::string toString();
    void setUpdateHandler(std::function<int(void)> updateHandler);

    void buttonClickMiddle();
    void buttonClickRight();

    void showStopLine(std::string LineName, std::string TimeMark, std::string FinalStop = "");
    void showDeparture(JSONVar salinaStop);

    // int update(GxGDEW027C44 &display);
    int update();
};