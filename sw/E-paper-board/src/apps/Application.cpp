#include "Application.hpp"
#include <stdio.h>

Application::Application(GxEPD *display, std::function<std::string(std::string url)> getHTTPRequest) {
    this->getHTTPRequest = getHTTPRequest;
    this->display = display;
}