#pragma once

// source https://github.com/espressif/arduino-esp32/blob/master/libraries/ESP32/examples/GPIO/FunctionalInterrupt/FunctionalInterrupt.ino

#include <Arduino.h>
#include <FunctionalInterrupt.h>
#include <stdio.h>

class Button {
public:
    Button(uint8_t reqPin)
        : PIN(reqPin) {
        pinMode(PIN, INPUT_PULLUP);
        attachInterrupt(PIN, std::bind(&Button::isr, this), FALLING);
    };
    ~Button() {
        detachInterrupt(PIN);
    }

    void IRAM_ATTR isr() {
        numberKeyPresses += 1;
        pressed = true;
    }

    void checkPressed() {
        if (pressed) {
            printf("Button on pin %u has been pressed %u times\n", PIN, numberKeyPresses);
            pressed = false;
        }
    }

private:
    const uint8_t PIN;
    volatile uint32_t numberKeyPresses;
    volatile bool pressed;
};