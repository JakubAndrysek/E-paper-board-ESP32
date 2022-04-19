#include "board.h"
#include <Adafruit_I2CDevice.h>
#include <GxEPD.h>

#include <GxGDEW027C44/GxGDEW027C44.h> // 2.7" b/w/r form GoodDisplay

#include <Fonts/FreeMono9pt7b.h>
// #include <Fonts/FreeSans9pt7b.h>
// #include <Fonts/FreeSerif9pt7b.h>
// #include <Fonts/FreeMonoBold9pt7b.h>
// #include <Fonts/FreeMonoBold12pt7b.h>
// #include <Fonts/FreeMonoBold18pt7b.h>
#include <GxIO/GxIO.h>
#include <GxIO/GxIO_SPI/GxIO_SPI.h>

//////////NEW////////////////////
#include "FreeSans15pt8b.h"
#include "gfxlatin2.h"
//////////NEW////////////////////

#include "string.h"
#include <string>

class MyDisplay {
private:
public:
    GxIO_Class* io;
    GxEPD_Class* display;
    MyDisplay(/* args */);

    // std::string printCz(std::string str) {
    //     char text[100];
    //     strcpy(text, str.c_str());
    //     utf8tocp(text);
    //     return std::string(text);
    // }

    // const char* printCz2(std::string str) {
    //     char text[100];
    //     strcpy(text, str.c_str());
    //     utf8tocp(text);
    //     return text;
    // }

    // const char* printCz3(std::string str) {
    //     static char text[100];
    //     strcpy(text, str.c_str());
    //     utf8tocp(text);
    //     return text;
    // }

    const char* printCz(const char* str) {
        // static char text[100];
        // strcpy(text, str);
        utf8tocp(str);
        return str;
    }

    const char* printCz(std::string str) {
        return printCz(str.c_str());
    }

    std::string printCzStr(std::string str) {
        return std::string(printCz(str));
    }

    std::string printCzStr(char* str) {
        return std::string(printCz(str));
    }

    void show() {
        display->setTextColor(GxEPD_BLACK);
        // display->setFont(&FreeSans15pt8b);
        display->setFont(&FreeMono9pt7b);
        display->setCursor(0, 45);

        // char text[100];
        // strcpy(text, "ěščřžýáíéúůóü");
        // utf8tocp(text);
        // display->print(text);
        // // display->getTextBounds()

        // strcpy(text, "ĚŠČŘŽÝÁÍÉÚŮÓÜ");
        // utf8tocp(text);
        // // display->setCursor( 30, 140 );
        // display->print(text);

        display->println(printCz("1ěšýáíé").c_str());
        // display->println(printCz2("2ěščřžýáí"));
        display->println(printCz3("3ěščřžýáí"));
        display->println(printCz3("4&*(šřš"));
        display->println(printCz3("5řěáíéfz`;Aho43&*(šřš"));
        display->println(printCz3("6řš"));

        display->update();
    }

    ~MyDisplay();
};

MyDisplay::MyDisplay() {
    io = new GxIO_Class(SPI, EPD_CS, EPD_DC, EPD_RSET);
    display = new GxEPD_Class(*io, EPD_RSET);

    display->init();
}

MyDisplay::~MyDisplay() {
}