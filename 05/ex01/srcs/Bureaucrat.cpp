#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat() : name("Undefined"), grade(150)
{
	cout << "Bureaucrat default constructor called." << endl;
}


Bureaucrat::Bureaucrat(std::string name) : name(name), grade(150)
{
	cout << "Bureaucrat name constructor called." << endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
	cout << "Bureaucrat copy constructor called." << endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat destructor called." << endl;
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

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << endl;
	return out;
}


