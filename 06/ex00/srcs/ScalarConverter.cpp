#include "ScalarConverter.hpp"

using std::cerr;
using std::endl;
using std::cout;

ScalarConverter::ScalarConverter(){}

ScalarConverter::~ScalarConverter(){}

int ScalarConverter::to_int(char const *s)
{
     if ( s == NULL || *s == '\0' )
        throw std::invalid_argument("null or empty string argument");

     bool negate = (s[0] == '-');
     if ( *s == '+' || *s == '-' ) 
         ++s;

     if ( *s == '\0')
        throw std::invalid_argument("sign character only.");

     int result = 0;
     while(*s)
     {
          if ( *s < '0' || *s > '9' )
            throw std::invalid_argument("invalid input string");
          result = result * 10  - (*s - '0');  //assume negative number
          ++s;
     }
     return negate ? result : -result; //-result is positive!
} 

void ScalarConverter::convert(std::string str)
{
	int INT;

	try
	{
		std::istringstream(str) >> INT;
		cout << "int : " << INT << endl;
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << endl;
	}

}
