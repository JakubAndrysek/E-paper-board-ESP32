#pragma once

#include "InputManager.hpp"
#include "HttpFetcher.hpp"
#include "apps/Application.hpp"
#include "Button2.h"
#include <memory>
#include <vector>
#include <WiFi.h>

class Manager {
private:
    InputManager inputManager;

    int appIndex = 0;
    std::vector<std::unique_ptr<Application>> applications;

public:
    Manager(/* args */);
    ~Manager();
    void buttonClickLeft(Button2 &btn);
    void buttonClickMiddle(Button2 &btn);
    void buttonClickRight(Button2 &btn);

    void run();
};
