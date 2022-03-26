#include "Manager.hpp"
#include <stdio.h>

Manager::Manager(/* args */) {
    // array of applications
    applications.emplace_back(new AppSalina());
    applications.emplace_back(new AppFablab());
}

Manager::~Manager() {
}

void Manager::run() {
    printf("%d\n", applications[0]->update());
    printf("%d\n", applications[1]->update());
}