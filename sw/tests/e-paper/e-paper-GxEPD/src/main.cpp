/**
 * @file main.cpp
 * @author Kuba Andrysek (kubaandrysek.cz)
 * @brief
 * @version 0.1
 * @date 2022-02-24
 *
 * @copyright Kuba Andrysek (c) 2022
 *
 */

#include <Arduino.h>
#include "board.h"

#include <Adafruit_I2CDevice.h>
#include <GxEPD.h>
#include <GxGDEW027C44/GxGDEW027C44.h> // 2.7" b/w/r form GoodDisplay
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>


GxIO_Class io(SPI, EPD_CS, EPD_DC, EPD_RSET);
GxEPD_Class display(io, EPD_RSET);

void setup(void)
{
	Serial.begin(115200);

	SPI.begin(EPD_SCLK, EPD_MISO, EPD_MOSI);

	display.init(); // enable diagnostic output on Serial
	display.setRotation(1);


	display.setTextColor(GxEPD_BLACK);
	display.setFont(&FreeMono9pt7b);
	display.setCursor(0, 45);
	display.println("Hello World");

	display.setTextColor(GxEPD_RED);
	display.setFont(&FreeSans9pt7b);
	display.println("Hello World");

	display.setFont(&FreeSerif9pt7b);
	display.println("Hello World");
	display.update();

}

void loop() {
	
}