#pragma once

#include "Button2.h"

class InputManager {
private:

public:
    Button2 btnLeft;
    Button2 btnMiddle;
    Button2 btnRight;
    
    InputManager(/* args */);
    ~InputManager();
};