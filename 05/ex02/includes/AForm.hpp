#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class AForm
{
	private:
		const std::string name;
		bool isSigned;
        const int gradeToSign;
        const int gradeToExecute;
    
	public:
    // Constructors and destructors
		AForm();
		AForm(std::string type, int gradeToSign, int gradeToExecute);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
	    ~AForm();
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

std::ostream &operator<<(std::ostream &out, AForm const &bureaucrat);


#endif
