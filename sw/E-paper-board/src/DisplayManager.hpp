#pragma once

#include "Board_TTGO_Tdisplay.hpp"

#include <Adafruit_I2CDevice.h>
#include <GxEPD.h>
#include <GxGDEW027C44/GxGDEW027C44.h> // 2.7" b/w/r form GoodDisplay
#include <GxIO/GxIO.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>

#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>

class DisplayManager {
private:
    GxIO_Class *io;

public:
	GxEPD_Class *display;
    
    DisplayManager(/* args */);
    ~DisplayManager();

    void test();
};