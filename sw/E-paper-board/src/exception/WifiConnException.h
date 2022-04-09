#include <exception>

struct WifiConnException : public std::exception {
    const char* what() const throw() {
        return "WiFi connection failed";
    }
};