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
#include "cert.h"
#include "display.h"

// #include <Adafruit_I2CDevice.h>
// #include <GxEPD.h>
// #include <GxGDEW027C44/GxGDEW027C44.h> // 2.7" b/w/r form GoodDisplay
// #include <GxIO/GxIO_SPI/GxIO_SPI.h>
// #include <GxIO/GxIO.h>

// #include <Fonts/FreeMono9pt7b.h>
// #include <Fonts/FreeSans9pt7b.h>
// #include <Fonts/FreeSerif9pt7b.h>
// #include <Fonts/FreeMonoBold9pt7b.h>
// #include <Fonts/FreeMonoBold12pt7b.h>
// #include <Fonts/FreeMonoBold18pt7b.h>

#include <WiFi.h>
#include <HTTPClient.h>
#include <Arduino_JSON.h>
#include "Button2.h"

const char *ssid = "Pletacka-IoT";
const char *password = "PletackaPlete";

String serverName = "https://mapa.idsjmk.cz/api/Departures";
String KoriskovaToCenter = "?stopid=1272&postid=2";
String MedlankyToIvanovice = "?stopid=1377&postid=1";

void btnHandler1(Button2 &btn);
void btnHandler2(Button2 &btn);
void btnHandler3(Button2 &btn);
JSONVar loadDepartures(String departure);
void updateDepartures(String departure);
void showDepartures(JSONVar postList);

GxIO_Class io(SPI, EPD_CS, EPD_DC, EPD_RSET);

void setup(void)
{
	Serial.begin(115200);
	SPI.begin(EPD_SCLK, EPD_MISO, EPD_MOSI);

	delay(100);

	// MyDisplay disp(io);

	static Button2 button1;
	static Button2 button2;
	static Button2 button3;

	button1.begin(BUTTON_1);
	button2.begin(BUTTON_2);
	button3.begin(BUTTON_3);

	//display.init(); // enable diagnostic output on Serial
	//display.setRotation(1);
	//display.fillScreen(GxEPD_WHITE);

	// WiFi.begin(ssid, password);
	// Serial.println("Connecting");
	// while (WiFi.status() != WL_CONNECTED)
	// {
	// 	delay(500);
	// 	Serial.print(".");
	// }
	// Serial.println("");
	// Serial.print("Connected to WiFi network with IP Address: ");
	// Serial.println(WiFi.localIP());
	// delay(100);

	button1.setClickHandler(btnHandler1);
	button2.setClickHandler(btnHandler2);
	button3.setClickHandler(btnHandler3);

	while (true)
	{
		button1.loop();
		button2.loop();
		button3.loop();
	}
}

void btnHandler1(Button2 &btn)
{
	updateDepartures(KoriskovaToCenter);
}

void btnHandler2(Button2 &btn)
{
	updateDepartures(MedlankyToIvanovice);
}

void btnHandler3(Button2 &btn)
{
	// loadDepartures(MedlankyToIvanovice);
}

void updateDepartures(String departure)
{
	JSONVar postList = loadDepartures(departure);
	showDepartures(postList);
	//display.update();
	Serial.println("Updated");
}

String httpGETRequest(String serverName)
{
	// WiFiClient client;
	HTTPClient http;

	// Your Domain name with URL path or IP address with path
	http.begin(serverName.c_str());

	// Send HTTP POST request
	int httpResponseCode = http.GET();

	String payload = "{}";

	if (httpResponseCode > 0)
	{
		Serial.print("HTTP Response code: ");
		Serial.println(httpResponseCode);
		payload = http.getString();
	}
	else
	{
		Serial.print("Error code: ");
		Serial.println(httpResponseCode);
	}
	// Free resources
	http.end();

	return payload;
}

JSONVar loadDepartures(String departure)
{
	Serial.println("BTN");
	if (WiFi.status() == WL_CONNECTED)
	{
		String sensorReadings;

		sensorReadings = httpGETRequest(serverName + departure);
		Serial.println(sensorReadings);
		JSONVar myObject = JSON.parse(sensorReadings);

		// JSON.typeof(jsonVar) can be used to get the type of the var
		if (JSON.typeof(myObject) == "undefined")
		{
			Serial.println("Parsing input failed!");
			return new JSONVar();
		}

		// if(!myObject["PostList"]) {
		// 	return new JSONVar();
		// }

		Serial.println(myObject.keys());

		JSONVar postList = myObject["PostList"][0]; // First PostList
		Serial.println("load");
		Serial.println(postList);
		return postList;
	}
	else
	{
		return new JSONVar();
	}
}

void showDepartures(JSONVar postList)
{
	Serial.println(postList);
	//display.fillScreen(GxEPD_WHITE);
	//display.setTextColor(GxEPD_BLACK);
	//display.setCursor(5, 5);
	//display.setFont(&FreeMono9pt7b);
	Serial.printf("Name: %s", postList["Name"]);
	//display.println(postList["Name"]);
	//display.println();

	JSONVar departures = postList["Departures"][0];
	Serial.println(departures);
	if (!departures.length())
	{
		//display.println("Zadne spoje");
		return;
	}

	for (int i = 0; i < departures.length(); i++)
	{
		//display.printf("%s - %s \n", departures["LineName"], departures["TimeMark"]);
	}
}

void loop()
{
}

// display.setTextColor(GxEPD_BLACK);
// //display.setFont(&FreeMono9pt7b);
// //display.setCursor(0, 45);
// //display.println("Hello World");

// //display.setTextColor(GxEPD_RED);
// //display.setFont(&FreeSans9pt7b);
// //display.println("Hello World");

// //display.setFont(&FreeSerif9pt7b);
// //display.println("Hello World");
// //display.update();