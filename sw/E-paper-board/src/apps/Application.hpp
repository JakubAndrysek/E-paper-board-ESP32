#pragma once

// #include <GxGDEW027C44/GxGDEW027C44.h>
#include "GxEPD.h"
#include <functional>
#include <string>
#include <memory>

class Application {
private:
protected:
    std::string httpFetchUrl;
    GxEPD *display;
public:
    Application(GxEPD *display, std::function<std::string(std::string url)> getHTTPRequest);

    std::function<std::string(std::string url)> getHTTPRequest;

    // virtual int update(GxGDEW027C44 &display) = 0;
    virtual int update() = 0;
    virtual void buttonClickMiddle() = 0;
    virtual void buttonClickRight() = 0;
    virtual std::string toString() = 0;
};
