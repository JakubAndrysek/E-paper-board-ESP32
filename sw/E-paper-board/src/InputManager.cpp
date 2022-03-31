#include "InputManager.hpp"
#include "Board_TTGO_Tdisplay.hpp"

InputManager::InputManager(/* args */): buttonLeft(BUTTON_LEFT) {
    btn2Left.begin(BUTTON_LEFT);
    // btnMiddle.begin(BUTTON_MIDDLE);
    // btnRight.begin(BUTTON_RIGHT);
}

InputManager::~InputManager() {
}
