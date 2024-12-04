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
	return 0;
}
