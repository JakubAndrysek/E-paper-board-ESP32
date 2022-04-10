/**
 * @file HttpFetcher.hpp
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Http Fetcher - získává data z internetu
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */
#pragma once

#include <HTTPClient.h>
#include <string>

/**
 * @brief Http Fetcher - získává data z internetu
 * 
 */
class HttpFetcher {
private:

public:
    HttpFetcher();

    /**
     * @brief Získá data z internetu - GET request
     * 
     * @param url URL adresa
     * @return std::string Data
     */
    static std::string getHTTPRequest(std::string url);
};