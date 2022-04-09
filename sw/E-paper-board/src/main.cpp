#include "Manager.hpp"
#include "utils.hpp"

int mainAp() {
    delay(100);
    printf("Start application\n");

    Manager manager;

    while (true) {
        manager.run();
    }
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