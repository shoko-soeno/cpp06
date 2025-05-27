#include "ScalarConverter.h"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    (void)src;
}
/*
This class should not be instantiated or copied
*/

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string &literal)
{
    if (literal.empty())
    {
        std::cout << "Error: Empty input" << std::endl;
        return;
    }

    if (isChar(literal))
        convertChar(literal);
    else if (isInt(literal))
        convertInt(literal);
    else if (isFloat(literal))
        convertFloat(literal);
    else if (isDouble(literal))
        convertDouble(literal);
    else
        std::cout << "Error: Invalid input" << std::endl;
}
/*
detect char/int/float/double and convert it to all types
*/
