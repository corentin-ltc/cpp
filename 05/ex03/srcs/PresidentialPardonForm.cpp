#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 72, 45), target("Undefined")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 72, 45), target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target)
{
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
