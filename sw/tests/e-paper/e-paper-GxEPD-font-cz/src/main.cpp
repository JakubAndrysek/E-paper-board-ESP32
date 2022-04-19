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
#include "display.h"

GxIO_Class io(SPI, EPD_CS, EPD_DC, EPD_RSET);

void setup(void)
{
	Serial.begin(115200);
	SPI.begin(EPD_SCLK, EPD_MISO, EPD_MOSI);

	delay(100);
	
	MyDisplay display;
	// MyDisplay display(io);

	display.show();

	printf("Zobraz\n");

}

void loop() {
}