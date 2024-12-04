#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        
        Form();
        Form(std::string name, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form &operator=(const Form &other);
        ~Form();

        
        class GradeTooHighException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Grade is too high.";
                }
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Grade is too low.";
                }
        };

        
        void beSigned(const Bureaucrat &bureaucrat);

        
        int getGradeToExecute(void) const;
        int getGradeToSign(void) const;
        void getSignStatus(void) const;
        const std::string getName(void) const;
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
