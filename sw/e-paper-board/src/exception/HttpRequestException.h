/**
 * @file HttpRequestException.h
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Vyjímka při chybě HTTP požadavku
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include <exception>

/**
 * @brief Vyjímka při chybě HTTP požadavku
 * 
 */
struct HttpRequestException : public std::exception {
    /**
     * @brief Chybový text
     * 
     * @return const char* 
     */
    const char* what() const throw() {
        return "HTTP request error";
    }
};