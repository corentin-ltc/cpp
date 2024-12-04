#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    Bureaucrat bob("Bob", 50);
    ShrubberyCreationForm shrub("Home");
    RobotomyRequestForm robot("Target");
    PresidentialPardonForm pardon("Target");


    bob.signForm(shrub);
    bob.executeForm(shrub);
    
    bob.signForm(robot);
    bob.executeForm(robot);
    
    bob.signForm(pardon);
    bob.executeForm(pardon);
    return 0;
}
