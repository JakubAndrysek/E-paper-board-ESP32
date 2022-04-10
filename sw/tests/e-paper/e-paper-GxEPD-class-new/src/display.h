#include "board.h"
#include <Adafruit_I2CDevice.h>
#include <GxEPD.h>

#include <GxGDEW027C44/GxGDEW027C44.h> // 2.7" b/w/r form GoodDisplay

#include <Fonts/FreeMono9pt7b.h>
#include <Fonts/FreeSans9pt7b.h>
#include <Fonts/FreeSerif9pt7b.h>
#include <Fonts/FreeMonoBold9pt7b.h>
#include <Fonts/FreeMonoBold12pt7b.h>
#include <Fonts/FreeMonoBold18pt7b.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>

class MyDisplay
{
private:
public:
	GxIO_Class *io;
	GxEPD_Class *display;
	MyDisplay(/* args */);

	void show()
	{
		display->setTextColor(GxEPD_BLACK);
		display->setFont(&FreeMono9pt7b);
		display->setCursor(0, 45);
		display->println("Hello World");

		display->setTextColor(GxEPD_RED);
		display->setFont(&FreeSans9pt7b);
		display->println("Hello World");

		display->setFont(&FreeSerif9pt7b);
		display->println("Hello World");
		display->update();
	}

	~MyDisplay();
};

MyDisplay::MyDisplay() {
	io = new GxIO_Class(SPI, EPD_CS, EPD_DC, EPD_RSET);
	display = new GxEPD_Class(*io, EPD_RSET);

	display->init();
	display->fillCircle(5, 5, 50, GxEPD_BLACK);
	display->update();
}

MyDisplay::~MyDisplay()
{
}