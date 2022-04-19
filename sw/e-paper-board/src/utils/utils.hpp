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

static const char* printCz(const char* str) {
    static char text[100];
    strcpy(text, str);
    utf8tocp(text);
    return text;
}

static const char* printCz(std::string str) {
    return printCz(str.c_str());
}