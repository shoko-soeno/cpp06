#include "ScalarConverter.h"

/*
ex00 float, doubleのオーバーフローを検知するコードがINT_MAXと比較していたため、
本来はオーバーフローしない場合でもimpossibleと出力されていました。
オーバーフローした際にはoverflowedと出力すると親切かもしれません。
*/

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
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
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
        f = strtof(literal.c_str(), NULL);

    {
        if (std::isnan(f) || std::isinf(f))
            std::cout << "char: impossible\n";
        else
            printChar(static_cast<char>(f));
    }

    {
        if (std::isnan(f) || std::isinf(f) || f > std::numeric_limits<int>::max() || f < std::numeric_limits<int>::min())
            std::cout << "int: impossible\n";
        else
            printInt(static_cast<int>(f));
    }
    printFloat(f);
    printDouble(static_cast<double>(f));
}

void ScalarConverter::convertDouble(const std::string &literal)
{
    double d = 0.0;

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
        d = strtod(literal.c_str(), NULL);

    {
        if (std::isnan(d) || std::isinf(d))
            std::cout << "char: impossible\n";
        else
            printChar(static_cast<char>(d));
    }

    {
        if (std::isnan(d) || std::isinf(d) || d > std::numeric_limits<int>::max() || d < std::numeric_limits<int>::min())
            std::cout << "int: impossible\n";
        else
            printInt(static_cast<int>(d));
    }
    printFloat(static_cast<float>(d));
    printDouble(d);
}
/*
special cases (nan, inf, -inf, nanf, +inff, -inff)
    not convertible to char or int
    but can be converted to float and double
*/
