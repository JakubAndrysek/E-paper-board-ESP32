#pragma once

#include "Application.hpp"
#include <functional>

class AppSalina : public Application {
private:
    /* data */
public:
    AppSalina(std::function<std::string(std::string url)> getHTTPRequest);
    ~AppSalina();

    void buttonClickLeft();
    void buttonClickMiddle();
    void buttonClickRight();
    JSONVar prepareSalinaStop(std::string stopParameters);

    int update();
};