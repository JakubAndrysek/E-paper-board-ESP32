/**
 * @file InputManager.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Správce vstupů
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "InputManager.hpp"
#include "Board_TTGO_Tdisplay.hpp"

InputManager::InputManager() {
    btnLeft.begin(BUTTON_LEFT);
    btnMiddle.begin(BUTTON_MIDDLE);
    btnRight.begin(BUTTON_RIGHT);
}

void InputManager::loop() {
    btnLeft.loop();
    btnMiddle.loop();
    btnRight.loop();
}
