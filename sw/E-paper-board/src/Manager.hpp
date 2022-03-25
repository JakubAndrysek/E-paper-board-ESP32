#pragma once

#include "apps/AppSalina.hpp"
#include "apps/Application.hpp"
#include "vector"

class Manager {
private:
    int appIndex = 0;
    AppSalina appSalina;
    std::vector<Application> applications;

public:
    Manager(/* args */);
    ~Manager();

    void run();
};
