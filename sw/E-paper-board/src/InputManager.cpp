#include "InputManager.hpp"
#include "Board_TTGO_Tdisplay.hpp"

InputManager::InputManager() {
    btnLeft.begin(BUTTON_LEFT);
    btnMiddle.begin(BUTTON_MIDDLE);
    btnRight.begin(BUTTON_RIGHT);
}

InputManager::~InputManager() {
}

void InputManager::loop() {
    btnLeft.loop();
    btnMiddle.loop();
    btnRight.loop();
}
