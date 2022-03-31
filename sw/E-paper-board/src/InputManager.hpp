#pragma once

#include "Button2.h"
#include "Button.hpp"

class InputManager {
private:

public:
    Button buttonLeft;
    Button2 btn2Left;
    // Button2 btnMiddle;
    // Button2 btnRight;
    
    InputManager(/* args */);
    ~InputManager();
};