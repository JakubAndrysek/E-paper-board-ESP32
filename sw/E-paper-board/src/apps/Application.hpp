#pragma once
#include <functional>
#include <string>

class Application {
private:
protected:
public:
    Application(std::function<std::string(std::string url)> getHTTPRequest);
    ~Application();

    std::function<std::string(std::string url)> getHTTPRequest;

    virtual int update() = 0;
    virtual void buttonClickLeft() = 0;
    virtual void buttonClickMiddle() = 0;
    virtual void buttonClickRight() = 0;
};
