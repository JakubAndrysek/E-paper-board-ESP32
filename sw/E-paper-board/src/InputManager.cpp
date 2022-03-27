#include "InputManager.hpp"
#include "board_TTGO_Tdisplay.h"

InputManager::InputManager(/* args */) {
    btnLeft.begin(BUTTON_LEFT);
    btnMiddle.begin(BUTTON_MIDDLE);
    btnRight.begin(BUTTON_RIGHT);
}

InputManager::~InputManager() {
}
