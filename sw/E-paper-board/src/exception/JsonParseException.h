#include <exception>

struct JsonParseException : public std::exception {
    const char* what() const throw() {
        return "JSON parsing input failed!";
    }
};