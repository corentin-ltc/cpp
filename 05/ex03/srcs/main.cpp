#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Bureaucrat bob("Bob", 50);
    ShrubberyCreationForm shrub("Home");
    RobotomyRequestForm robot("Target");
    PresidentialPardonForm pardon("Target");
	Intern intern;
	AForm *test;

    bob.signForm(shrub);
    bob.executeForm(shrub);
    
    bob.signForm(robot);
    bob.executeForm(robot);
    
    bob.signForm(pardon);
    bob.executeForm(pardon);
	try
	{
		test = intern.makeForm("PresidentialPardonForm", "target");
		intern.makeForm("incorrect", "target");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << test->getName() << std::endl;
	

    return 0;
}
