#pragma once

#include <HTTPClient.h>
#include <string>

class HttpFetcher {
private:
    /* data */
public:
    HttpFetcher();
    ~HttpFetcher();

    static std::string getHTTPRequest(std::string url);
};