#pragma once

#include <GxGDEW027C44/GxGDEW027C44.h>
#include <functional>
#include <string>

class Application {
private:
protected:
    std::string httpFetchUrl;

public:
    Application(std::function<std::string(std::string url)> getHTTPRequest);
    ~Application();

    std::function<std::string(std::string url)> getHTTPRequest;

    // virtual int update(GxGDEW027C44 &display) = 0;
    virtual int update() = 0;
    virtual void buttonClickMiddle() = 0;
    virtual void buttonClickRight() = 0;
    virtual std::string toString() = 0;
};
