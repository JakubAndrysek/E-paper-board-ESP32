#pragma once

#include "Application.hpp"
#include <GxGDEW027C44/GxGDEW027C44.h>
#include <functional>

class AppFablab : public Application {
private:
    /* data */
public:
    AppFablab(std::function<std::string(std::string url)> getHTTPRequest);
	std::string toString();

    void buttonClickLeft();
    void buttonClickMiddle();
    void buttonClickRight();
    JSONVar prepareSalinaStop(std::string stopParameters);

    // int update(GxGDEW027C44 &display);
    int update();
};