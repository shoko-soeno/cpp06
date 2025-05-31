#include "ScalarConverter.h"

void ScalarConverter::convertChar(const std::string &literal)
{
    char c = literal[0];

    printChar(c);
    printInt(static_cast<int>(c));
    printFloat(static_cast<float>(c));
    printDouble(static_cast<double>(c));
}

void ScalarConverter::convertInt(const std::string &literal)
{
    long value = strtol(literal.c_str(), NULL, 10);

    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
    {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        float f = static_cast<float>(value);
        printFloat(f);
        double d = static_cast<double>(value);
        printDouble(d);
        return;
    }
    int i = static_cast<int>(value);
    printChar(static_cast<char>(i));
    printInt(i);
    printFloat(static_cast<float>(i));
    printDouble(static_cast<double>(i));
}

void ScalarConverter::convertFloat(const std::string &literal)
{
    float f = 0.0f;
    bool is_overflowed = false;

    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
    {
        if (literal == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff")
            f = std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            f = -std::numeric_limits<float>::infinity();
    }
    else
    {
        errno = 0; // Reset errno before conversion
        f = strtof(literal.c_str(), NULL);
        if (errno == ERANGE)
        {
            is_overflowed = true;
        }
    }
    printChar(static_cast<char>(f));
    printInt(static_cast<int>(f));
    if (is_overflowed)
        std::cout << "float: impossible (overflowed)\n";
    else
        printFloat(f);
    printDouble(static_cast<double>(f));
}

void ScalarConverter::convertDouble(const std::string &literal)
{
    double d = 0.0;
    bool is_overflowed = false;

    if (literal == "nan" || literal == "+inf" || literal == "-inf")
    {
        if (literal == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf")
            d = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            d = -std::numeric_limits<double>::infinity();
    }
    else
    {
        errno = 0; // Reset errno before conversion
        d = strtod(literal.c_str(), NULL);
        if (errno == ERANGE)
        {
            is_overflowed = true;
        }
    }
    printChar(static_cast<char>(d));
    printInt(static_cast<int>(d));
    printFloat(static_cast<float>(d));
    if (is_overflowed)
        std::cout << "double: impossible (overflowed)\n";
    else
        printDouble(d);
}
/*
special cases (nan, inf, -inf, nanf, +inff, -inff)
    not convertible to char or int
    but can be converted to float and double

Significant digits (precision)
    This tells how many digits are accurate in a number.
    float has about 7 digits of precision.
    double has about 15–16 digits of precision.

Exponent range (magnitude)
    This tells how large or small a number you can represent.
    float can store numbers up to about 10^38.
    double can go up to about 10^308.
*/
