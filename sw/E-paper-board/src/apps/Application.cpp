#include "Application.hpp"
#include <stdio.h>

Application::Application(std::function<std::string(std::string url)> getHTTPRequest) {
    this->getHTTPRequest = getHTTPRequest;
}

Application::~Application() {
}