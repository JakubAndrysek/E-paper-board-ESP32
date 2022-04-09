#include <exception>

struct HttpRequestException : public std::exception {
    const char* what() const throw() {
        return "HTTP request error";
    }
};