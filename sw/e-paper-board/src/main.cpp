/**
 * @file main.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Hlavní program
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "Manager.hpp"
/**
 * @brief Hlavní program aplikace
 * 
 * @return int 
 */
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

/**
 * @brief Hlavní program aplikace - Arduino
 * 
 */
void setup() {
    mainAp();
}

void loop() {}

#else
/**
 * @brief Hlavní program aplikace - Linux
 * 
 */
int main() {
    return mainAp();
}
#endif