/**
 * @file utils.hpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Užitečné funkce
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */
#pragma once

#include "display/gfxlatin2.h"
#include "string.h"
#include <string>

/**
 * @brief Upraví český znak pro správné zobrazení na displeji
 * 
 * @param const char* Český text
 * @return const char* Upravený text
 */
static const char* printCz(const char* str) {
    static char text[100];
    strcpy(text, str);
    utf8tocp(text);
    return text;
}

/**
 * @brief Upraví český znak pro správné zobrazení na displeji
 * 
 * @param str Český text
 * @return const char* Upravený text
 */
static const char* printCz(std::string str) {
    return printCz(str.c_str());
}

/**
 * @brief Převede číslo ze sekund na milisekundy
 * 
 * @param sec Číslo v sekundách
 * @return int Číslo v milisekundách
 */
static int secToMs(int sec) {
    return sec * 1000;
}

/**
 * @brief Převede číslo ze sekund na milisekundy
 * 
 * @param sec Číslo v sekundách
 * @return int Číslo v milisekundách
 */
static int minToSec(int minutes) {
    return minutes * 60;
}