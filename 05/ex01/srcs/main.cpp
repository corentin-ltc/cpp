#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat test("Test");

		for (int i = 0; i < 140; i++)
			test.incrementGrade();
		std::cout << test;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}
