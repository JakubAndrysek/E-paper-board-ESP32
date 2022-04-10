/**
 * @file InputManager.hpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Správce vstupů
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */
#pragma once

#include "Button2.h"

/**
 * @brief Správce vstupů
 * 
 */
class InputManager {
private:
public:
    /**
     * @brief Konstruktor správce vstupů
     * 
     */
    InputManager();

    Button2 btnLeft;
    Button2 btnMiddle;
    Button2 btnRight;

    /**
     * @brief Hlavní smyčka správce vstupů
     * 
     */
    void loop();
};