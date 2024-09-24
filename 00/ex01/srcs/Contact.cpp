#include "Contact.hpp"

void Contact::fill_contact(){
	
	std::string	input;

	slot_taken = true;
	first_name = get_input("Enter first name: ");
	last_name = get_input("Enter last name: ");
	nickname = get_input("Enter nickname: ");
	darkest_secret = get_input("Enter darkest secret: ");
	phone_number = get_input("Enter phone number: ");
}

std::string Contact::get_input(std::string prompt){

	std::string	input;

	do{
		std::cout << prompt;
		getline(std::cin, input);
	} while (input == "");
	return (input);
}

bool Contact::is_slot_taken(){
	return (slot_taken);
}