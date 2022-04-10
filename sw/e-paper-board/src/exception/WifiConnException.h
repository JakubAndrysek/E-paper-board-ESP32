/**
 * @file WifiConnException.h
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Vyjímka při chybě WiFi připojení
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include <exception>

/**
 * @brief Vyjímka při chybě WiFi připojení
 * 
 */
struct WifiConnException : public std::exception {
    /**
     * @brief Chybový text
     * 
     * @return const char* 
     */
    const char* what() const throw() {
        return "WiFi connection failed";
    }
};