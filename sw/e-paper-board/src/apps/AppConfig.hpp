#pragma once

#include <functional>
#include <map>
#include <memory>
#include <string>
#include <utility>

typedef struct AppConfig {
    /**
     * @brief Základní URL pro HTTP požadavky
     * 
     */
    std::string httpUrlBase;

	/**
	 * @brief API klíč pro přístu na server
	 * 
	 */
	std::string apiKey;

    /**
     * @brief Callback statické metody pro HTTP request
     * 
     */
    std::function<std::string(std::string url)> getHTTPRequest;

    /**
     * @brief Callback pro aktualizaci displeje
     * 
     */
    std::function<int(void)> updateHandler;

} AppConfig;