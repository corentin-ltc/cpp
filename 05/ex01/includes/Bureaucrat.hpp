#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
    
	public:
		Bureaucrat();
		Bureaucrat(std::string type);
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

};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);


#endif
