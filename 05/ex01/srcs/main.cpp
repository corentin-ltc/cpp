#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat	bureaucrat("Laurent");
	Form		form("Formulaire A1", 150, 150);
	Form		form2("Formulaire A2", 1, 150);

	form.signForm(bureaucrat);
	form2.signForm(bureaucrat);
	
}
