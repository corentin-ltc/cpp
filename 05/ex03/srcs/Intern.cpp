#include "Intern.hpp"

using std::cout;
using std::endl;

Intern::Intern()
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
    return *this;
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	cout << "Into Makeform()\n";
	AForm *test = new ShrubberyCreationForm(target);
	if (name == test->getName())
		return test;
	delete test;
	AForm *test1 = new PresidentialPardonForm(target);
	if (name == test1->getName())
		return test1;
	delete test1;
	AForm *test2 = new RobotomyRequestForm(target);
	if (name == test2->getName())
		return test2;
	throw FormDoesntExistException();
}
