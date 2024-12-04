#include "AForm.hpp"

using std::cout;
using std::endl;

AForm::AForm() : name("Undefined"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
    {
        throw GradeTooHighException();  
    }
    if (gradeToSign > 150 || gradeToExecute > 150)
    {
        throw GradeTooLowException();  
    }
}

AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

AForm::~AForm()
{
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

std::ostream &operator<<(std::ostream &out, const AForm &Aform)
{
    out << Aform.getName() << (Aform.getSignStatus() ? " is signed" : " is not signed")
        << ", grade to sign: " << Aform.getGradeToSign()
        << ", grade to execute: " << Aform.getGradeToExecute() << "." << endl;
    return out;
}

void AForm::CanBeExecuted(const Bureaucrat &bureaucrat) const
{
	if (!this->isSigned)
		throw IsNotSignedException();
	else if (this->gradeToExecute < bureaucrat.getGrade())
		throw GradeTooLowException();
	
}


void AForm::execute(Bureaucrat const & executor) const{(void)executor;}
