#ifndef INTERN_HPP
#define INTERN_HPP


#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern &other);
        Intern &operator=(const Intern &other);
        ~Intern();
		class FormDoesntExistException : public std::exception
		{
			 public:
			 	const char *what() const throw(){return "The form doesn't exist.";}
		};
		AForm *makeForm(std::string name, std::string target);
};


#endif
