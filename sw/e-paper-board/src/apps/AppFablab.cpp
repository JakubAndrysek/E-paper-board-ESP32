/**
 * @file AppFablab.cpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Modul aplikace pro zobrazování obsazenosti FabLabu
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include "AppFablab.hpp"
#include <Arduino_JSON.h>
#include <stdio.h>

#include <Fonts/FreeMono9pt7b.h>

AppFablab::AppFablab(std::function<std::string(std::string url)> getHTTPRequest)
    : Application(getHTTPRequest) {
    httpFetchUrl = "https://jsonplaceholder.typicode.com/todos/1";
}

std::string AppFablab::toString() {
    return "AppFablab";
}

void AppFablab::setUpdateHandler(std::function<int(void)> updateHandler) {
    this->updateHandler = updateHandler;
}

void AppFablab::buttonClickMiddle() {
    printf("Pressed button MIDDLE\n");
}

void AppFablab::buttonClickRight() {
    printf("Pressed button RIGHT\n");
}


int AppFablab::update(GxEPD* display) {
    return 44;
}
