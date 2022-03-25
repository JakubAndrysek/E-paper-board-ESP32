#include "Manager.hpp"
#include <stdio.h>

Manager::Manager(/* args */) {
}

Manager::~Manager() {
}

void Manager::run() {
    printf("%d\n", appSalina.update());
}