#include "ScalarConverter.hpp"

using std::cerr;
using std::endl;
using std::cout;

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		cerr << "There must be only one argument" << endl;
		return(1);
	}
	ScalarConverter::convert(argv[1]);
    ScalarConverter::convert("'c'");
    ScalarConverter::convert("42");
    ScalarConverter::convert("4.2f");
    ScalarConverter::convert("4.2");
    ScalarConverter::convert("-inff");
    ScalarConverter::convert("+inf");
    ScalarConverter::convert("nanf");
    return 0;
}
