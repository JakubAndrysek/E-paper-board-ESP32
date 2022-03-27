#include "AppSalina.hpp"
#include <stdio.h>

AppSalina::AppSalina(std::function<std::string(std::string url)> _getHTTPRequest) 
: Application(_getHTTPRequest) {
}

AppSalina::~AppSalina() {
}

void AppSalina::buttonClickLeft() {
    printf("Pressed button LEFT\n");
}

void AppSalina::buttonClickMiddle() {
    printf("Pressed button MIDDLE\n");
}

void AppSalina::buttonClickRight() {
    printf("Pressed button RIGHT\n");
}

int AppSalina::update() {
	printf("%s\n", getHTTPRequest("https://jsonplaceholder.typicode.com/todos/1").c_str());
    return 44;
}
