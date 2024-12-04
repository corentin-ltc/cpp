#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string type, int grade);
        Bureaucrat(const Bureaucrat &other);
        Bureaucrat &operator=(const Bureaucrat &other);
        ~Bureaucrat();

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

        int getGrade(void) const;
        const std::string getName(void) const;
        void incrementGrade(void);
        void decrementGrade(void);
        void signForm(Form &form);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
