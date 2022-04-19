/**
 * @file JsonEmptyObjectException.h
 * @author Kuba Andrýsek (email@kubaandrysek.cz)
 * @brief Vyjímka při prázdném objektu JSON
 * @date 2022-04-11
 * 
 * @copyright Copyright (c) 2022 Kuba Andrýsek
 * 
 */

#include <exception>

/**
 * @brief Vyjímka při prázdném objektu JSON
 * 
 */
struct JsonEmptyObjectException : public std::exception {
    /**
     * @brief Chybový text
     * 
     * @return const char* 
     */
    const char* what() const throw() {
        return "JSON object is empty!";
    }
};