#include "Form.hpp"

using std::cout;
using std::endl;

Form::Form() : name("Undefined"), isSigned(false), gradeToSign(1), gradeToExecute(1)
{
    cout << "Form default constructor called." << endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute)
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
    cout << "Form name constructor called." << endl;
}

Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    cout << "Form copy constructor called." << endl;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        isSigned = other.isSigned;
    return *this;
}

Form::~Form()
{
    cout << "Form destructor called." << endl;
}

int Form::getGradeToExecute(void) const
{
    return gradeToExecute;
}

int Form::getGradeToSign(void) const
{
    return gradeToSign;
}

bool Form::getSignStatus(void) const
{
    return isSigned;
}

const std::string Form::getName(void) const
{
    return name;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
        isSigned = true;
    else
        throw GradeTooLowException();  
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << (form.getSignStatus() ? " is signed" : " is not signed")
        << ", grade to sign: " << form.getGradeToSign()
        << ", grade to execute: " << form.getGradeToExecute() << "." << endl;
    return out;
}
