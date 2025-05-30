#include "ScalarConverter.h"

void ScalarConverter::printChar(char value)
{
    std::cout << "char: ";
    if (!std::isfinite(value))
    {
        std::cout << "char: impossible\n";
        return ;
    }
    if (std::isprint(value))
        std::cout << "'" << value << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printInt(int value)
{
    if (!std::isfinite(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
    {
        std::cout << "int: impossible\n";
        return;
    }
    std::cout << "int: " << value << std::endl;
}

void ScalarConverter::printFloat(float value)
{
    std::cout << "float: " << value;
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double value)
{
    std::cout << "double: " << value;
    if (value == static_cast<int>(value))
        std::cout << ".0";
    std::cout << std::endl;
}
/*
if the value has no decimal part,
    print it as a float/double with .0
*/
