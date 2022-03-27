#pragma once
#include <functional>
#include <string>
#include <Arduino_JSON.h>

class Application {
private:
protected:
    std::string httpFetchUrl;

public:
    Application(std::function<std::string(std::string url)> getHTTPRequest);
    ~Application();

    std::function<std::string(std::string url)> getHTTPRequest;

    virtual int update() = 0;
    virtual void buttonClickLeft() = 0;
    virtual void buttonClickMiddle() = 0;
    virtual void buttonClickRight() = 0;
};
