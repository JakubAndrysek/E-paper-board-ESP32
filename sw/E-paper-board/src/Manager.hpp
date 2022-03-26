#pragma once

#include "apps/AppFablab.hpp"
#include "apps/AppSalina.hpp"
#include "apps/Application.hpp"
#include <memory>
#include <vector>

class Manager {
private:
    int appIndex = 0;
    std::vector<std::unique_ptr<Application>> applications;

public:
    Manager(/* args */);
    ~Manager();

    void run();
};
