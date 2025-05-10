#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H
# include <iostream>
# include <string>
# include <cstdlib>
# include <limits>
# include <cmath>

enum LiteralType {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_INVALID
};

LiteralType detectType(const std::string& literal);

struct ScalarValues {
    bool isCharDisplayable;
    char c;
    int i;
    float f;
    double d;
    bool conversible[4];
};

// ScalarValues castToAllTypes(const std::string& literal, LiteralType type);

// void printScalarValues(const ScalarValues& values);

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &src);
    ScalarConverter &operator=(const ScalarConverter &other);

public:
    ~ScalarConverter();
    static void convert(const std::string &literal);

private:
    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);

    static void convertChar(const std::string &literal);
    static void convertInt(const std::string &literal);
    static void convertFloat(const std::string &literal);
    static void convertDouble(const std::string &literal);

    static void printChar(char c);
    static void printInt(int i);
    static void printFloat(float f);
    static void printDouble(double d);
};

#endif