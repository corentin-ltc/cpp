#ifndef 	AFORM_HPP
#define 	AFORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;

    public:
        
        AForm();
        AForm(std::string name, int gradeToSign, int gradeToExecute);
        AForm(const AForm &other);
        AForm &operator=(const AForm &other);
        virtual ~AForm();

        
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
		class IsNotSignedException : public std::exception
        {
            public:
                const char *what() const throw()
                {
                    return "Form is not signed.";
                }
        };

        
        void beSigned(const Bureaucrat &bureaucrat);
		void CanBeExecuted(const Bureaucrat &bureaucrat) const;


        virtual void execute(Bureaucrat const & executor) const = 0;
        int getGradeToExecute(void) const;
        int getGradeToSign(void) const;
        bool getSignStatus(void) const;
        const std::string getName(void) const;
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif
