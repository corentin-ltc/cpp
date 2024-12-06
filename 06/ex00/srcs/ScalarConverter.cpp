#include "ScalarConverter.hpp"


ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&) { return *this; }

bool ScalarConverter::isPseudoLiteral(const std::string& str)
{
    return str == "-inff" || str == "+inff" || str == "nanf" ||
           str == "-inf" || str == "+inf" || str == "nan";
}
bool ScalarConverter::isCharLiteral(const std::string& str)
{
    return str.size() == 3 && str[0] == '\'' && str[2] == '\'';
}
bool ScalarConverter::isFloatLiteral(const std::string& str)
{
    return str.size() > 1 && str[str.size() - 1] == 'f' && str.find('.') != std::string::npos;
}
bool ScalarConverter::isIntLiteral(const std::string& str)
{
    size_t i = 0;

    if (str[0] == '-' || str[0] == '+')
        i++;
    for (; i < str.size(); ++i)
        if (!isdigit(str[i]))
            return false;
    return true;
}
void ScalarConverter::convert(const std::string& str)
{
    
    if (isCharLiteral(str))
    {
        char c = str[1];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
        return;
    }
    
    if (isPseudoLiteral(str))
    {
        if (str == "-inff" || str == "-inf")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else if (str == "+inff" || str == "+inf")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
        else if (str == "nanf" || str == "nan")
        {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: nanf" << std::endl;
            std::cout << "double: nan" << std::endl;
        }
        return;
    }
    
    if (isFloatLiteral(str))
    {
        try
        {
            float f = static_cast<float>(atof(str.c_str()));
            std::cout << "char: " << ((f >= 32 && f <= 126) ? "'" + std::string(1, static_cast<char>(f)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << (std::isfinite(f) ? static_cast<int>(f) : 0) << std::endl;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
        }
        catch (...)
        {
            std::cerr << "Error: Invalid float literal" << std::endl;
        }
        return;
    }
    
    if (isIntLiteral(str))
    {
        try
        {
            int i = atoi(str.c_str());
            std::cout << "char: " << ((i >= 32 && i <= 126) ? "'" + std::string(1, static_cast<char>(i)) + "'" : "Non displayable") << std::endl;
            std::cout << "int: " << i << std::endl;
            std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(i) << std::endl;
        }
        catch (...)
        {
            std::cerr << "Error: Invalid int literal" << std::endl;
        }
        return;
    }
    
    try
    {
        double d = atof(str.c_str());
        std::cout << "char: " << ((d >= 32 && d <= 126) ? "'" + std::string(1, static_cast<char>(d)) + "'" : "Non displayable") << std::endl;
        std::cout << "int: " << (std::isfinite(d) ? static_cast<int>(d) : 0) << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    catch (...)
    {
        std::cerr << "Error: Invalid double literal" << std::endl;
    }
}
