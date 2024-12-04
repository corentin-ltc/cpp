#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm() : AForm("Presidential Pardon", 72, 45), target("Undefined")
{
	cout << "PresidentialPardonForm default constructor called." << endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 72, 45), target(target)
{
	cout << "PresidentialPardonForm name constructor called." << endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target)
{
	cout << "PresidentialPardonForm copy constructor called." << endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "PresidentialPardonForm destructor called." << endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const 
{
	try 
	{
		this->CanBeExecuted(executor);
		std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << endl;
	}
}
