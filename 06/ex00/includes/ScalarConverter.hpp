#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <utility>

class ScalarConverter
{
	public:
		ScalarConverter();
		virtual ~ScalarConverter();

		class ImpossibleConversionException : public std::exception
		{
			const char *what() const throw()
			{
				return "Conversion is impossible.";
			}
		};

		static void convert(std::string str);

};
