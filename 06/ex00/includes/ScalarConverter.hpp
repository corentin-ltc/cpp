#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:
    // Prevent instantiation of the class
    ScalarConverter();
    ScalarConverter(const ScalarConverter&);
    ScalarConverter& operator=(const ScalarConverter&);
    ~ScalarConverter();

    static bool isPseudoLiteral(const std::string& str);
    static bool isCharLiteral(const std::string& str);
    static bool isFloatLiteral(const std::string& str);
    static bool isIntLiteral(const std::string& str);

public:
    static void convert(const std::string& str);
};

