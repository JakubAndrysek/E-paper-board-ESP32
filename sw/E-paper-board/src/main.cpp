#include "Manager.hpp"

int mainAp() {
    Manager manager;

    manager.run();
    return 0;
}

#if defined(ARDUINO)
// Arduino platform
#include <Arduino.h>
void setup() {
    mainAp();
}

void loop() {}

#else
// Linux platform
int main() {
    return mainAp();
}
#endif