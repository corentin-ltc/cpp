#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void){

	std::string input;
	PhoneBook phonebook;

	std::cout << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
	do{
		std::cin >> input;
		std::cin.ignore();
		if (input == "ADD")
			phonebook.add_a_contact();
		 if (input == "SEARCH")
		 	phonebook.display_contacts();
		if (input != "EXIT")
			std::cout << std::endl << "Enter command (ADD, SEARCH, EXIT): " << std::endl;
	}
	while (input != "EXIT");
	return 0;
}