#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat() : name("Undefined"), grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
        grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
}

int Bureaucrat::getGrade(void) const
{
    return grade;
}

const std::string Bureaucrat::getName(void) const
{
    return name;
}

void Bureaucrat::incrementGrade(void)
{
    if (grade <= 1)
        throw GradeTooHighException();
    else
        grade--;
}

void Bureaucrat::decrementGrade(void)
{
    if (grade >= 150)
        throw GradeTooLowException();
    else
        grade++;
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);  
        cout << this->getName() << " signed " << form.getName() << endl;
    }
    catch(const std::exception& e)
    {
        cout << this->getName() << " couldn’t sign " << form.getName() << " because " << e.what() << endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << endl;
    return out;
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		cout << name << " executed " << form.getName() << endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Form can't be executed : " << e.what() << endl;
	}
}
