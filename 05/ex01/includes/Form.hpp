#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string name;
		bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    
	public:
    // Constructors and destructors
		Form();
		Form(std::string type, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form &operator=(const Form &other);
	    ~Form();
    // Exceptions
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
    // Members functions
        void                signForm(Bureaucrat &bureaucrat);
        void                beSigned(const Bureaucrat &bureaucrat);
    // Getters
        int           getGradeToExecute(void) const;
        int           getGradeToSign(void) const;
        bool                getSignStatus(void) const;
        const std::string   getName(void) const;


};

std::ostream &operator<<(std::ostream &out, Form const &bureaucrat);


#endif
