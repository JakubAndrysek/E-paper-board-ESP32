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

struct HttpRequestError : public std::exception {
    const char* what() const throw() {
        return "HTTP request error";
    }
};