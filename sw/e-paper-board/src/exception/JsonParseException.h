/**
 * @file JsonParseException.h
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Vyjímka při chybě parosování JSON
 * @date 2022-04-10
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include <exception>

/**
 * @brief Vyjímka při chybě parosování JSON
 * 
 */
struct JsonParseException : public std::exception {
    /**
     * @brief Chybový text
     * 
     * @return const char* 
     */
    const char* what() const throw() {
        return "JSON parsing input failed!";
    }
};