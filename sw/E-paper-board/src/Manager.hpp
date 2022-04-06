#pragma once

#include "Button2.h"
#include "DisplayManager.hpp"
#include "HttpFetcher.hpp"
#include "InputManager.hpp"
#include "apps/Application.hpp"
#include <WiFi.h>
#include <memory>
#include <vector>

class Manager {
private:
    InputManager inputManager;
    DisplayManager displayManager;

    int appIndex = 0;
    std::vector<std::unique_ptr<Application>> applications;

public:
    Manager(bool connectToWifi = true);
    void run();
};
