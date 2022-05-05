#pragma once

#include "GxEPD.h"
#include <Arduino_JSON.h>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <utility>

typedef struct AppConfig {
	std::string httpUrlBase;
	std::function<std::string(std::string url)> getHTTPRequest;
	std::function<int(void)> updateHandler;
} AppConfig;