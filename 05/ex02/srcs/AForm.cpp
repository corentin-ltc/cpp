#include "AForm.hpp"

using std::cout;
using std::endl;

AForm::AForm() : name("Undefined"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
	cout << "AForm default constructor called." << endl;
}


AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
        throw GradeTooHighException();
	}
    if (gradeToSign > 150 || gradeToExecute > 150)
	{
        throw GradeTooLowException();
	}
	cout << "AForm name constructor called." << endl;
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(false), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	cout << "AForm copy constructor called." << endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return *this;
}

AForm::~AForm()
{
	cout << "AForm destructor called." << endl;
}

int AForm::getGradeToExecute(void) const
{
	return gradeToExecute;
}

int AForm::getGradeToSign(void) const
{
	return gradeToSign;
}

bool AForm::getSignStatus(void) const
{
	return isSigned;
}

const std::string AForm::getName(void) const
{
	return name;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= gradeToSign)
		isSigned = true;
	else
		throw GradeTooLowException();
}

void AForm::signAForm(Bureaucrat &bureaucrat)
{
	try
	{
		beSigned(bureaucrat);
		cout << bureaucrat.getName() << " signed " << name << endl;
	}
	catch(const std::exception& e)
	{
        cout << bureaucrat.getName() << " couldn’t sign " << name << " because " << e.what() << endl;
	}	
}

std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
	out << Aform.getName() << (Aform.getSignStatus() ? " is signed" : " is not signed") << ", grade to sign : " << Aform.getGradeToSign() << ", grade to execute : " << Aform.getGradeToExecute() << "." << endl;
	return out;
}

