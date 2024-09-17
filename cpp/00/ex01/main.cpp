#include "phonebook.hpp"
#include "contact.hpp"



void save_inputs(Contact contact ){
	
	std::string	input;

	std::cout << "Enter its first name" << std::endl;
	std::cin >> input;
	contact.first_name = input;
	std::cout << "Enter its last name" << std::endl;
	std::cin >> input;
	contact.last_name = input;
	std::cout << "Enter its nickname" << std::endl;
	std::cin >> input;
	contact.nickname = input;
	std::cout << "Enter its darkest secret" << std::endl;
	std::cin >> input;
	contact.darkest_secret = input;
	std::cout << "Enter its phone number" << std::endl;
	std::cin >> input;
	contact.darkest_secret = input;
}

int get_index(Contact contacts[8]){
	
}

void add_a_contact(PhoneBook phonebook){

	int index;

	index = get_index(phonebook.contacts);
	save_inputs(phonebook.contacts[index]);
}

/*
void search_a_contact(void)
{
	PhoneBook
} */

int main(void){

	std::string input;
	PhoneBook phonebook;

	do{
		std::cin >> input;
		if (input == "ADD"){
			add_a_contact(phonebook);
		}
		if (!input.compare("SEARCH")){
			std::cout << "cc";
		}
	}
	while (input != "EXIT");
}