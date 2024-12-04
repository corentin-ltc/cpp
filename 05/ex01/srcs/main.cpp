#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        
        Bureaucrat bureaucrat1("John", 50);
        std::cout << bureaucrat1;

        
        Form form1("A", 45, 30);
        std::cout << form1;

        
        bureaucrat1.signForm(form1);
        std::cout << form1;

        
        Bureaucrat bureaucrat2("Alice", 100);
        std::cout << bureaucrat2;

        
        bureaucrat2.signForm(form1);

        
        try {
            Form invalidForm("B", 0, 151);  
        } catch (const std::exception &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }

        
        Bureaucrat bureaucrat3("Bob", 150);
        std::cout << bureaucrat3;

        Form form2("C", 30, 30);
        std::cout << form2;
        bureaucrat3.signForm(form2);  

    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
