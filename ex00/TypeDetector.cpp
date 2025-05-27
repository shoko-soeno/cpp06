#include "ScalarConverter.h"

bool ScalarConverter::isChar(const std::string &literal)
{
    return (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]));
}

bool ScalarConverter::isInt(const std::string &literal)
{
    char *ptr;

    strtol(literal.c_str(), &ptr, 10);
    return (*ptr == '\0' && literal.find('.') == std::string::npos);
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    char *ptr;

    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;

    strtof(literal.c_str(), &ptr);
    return (*ptr == 'f' && *(ptr + 1) == '\0');
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    char *ptr;

    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;

    strtod(literal.c_str(), &ptr);
    return (*ptr == '\0');
}
