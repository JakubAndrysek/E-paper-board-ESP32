#pragma once

// #include <GxGDEW027C44/GxGDEW027C44.h>
#include "GxEPD.h"
#include <Arduino_JSON.h>
#include <functional>
#include <memory>
#include <string>

class Application {
private:
protected:
    std::string httpFetchUrl;
    std::string httpFetchUrlParameter;

    std::function<std::string(std::string url)> getHTTPRequest;
    std::function<int(void)> updateHandler;

public:
    Application(std::function<std::string(std::string url)> getHTTPRequest);

    JSONVar requestJson();
    std::string jsonToStr(JSONVar json);

    virtual std::string toString() = 0;
    virtual void setUpdateHandler(std::function<int(void)> updateHandler) = 0;
    virtual void buttonClickMiddle() = 0;
    virtual void buttonClickRight() = 0;

    // virtual int update(GxGDEW027C44 &display) = 0;
    virtual int update(GxEPD* display) = 0;
};
