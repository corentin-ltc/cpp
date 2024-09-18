#include "Contact.hpp"

void Contact::fill_contact(){
	
	std::string	input;

	slot_taken = true;
	std::cout << "Enter first name: ";
	std::getline(std::cin, first_name);
	std::cout << "Enter last name: ";
	std::getline(std::cin, last_name);
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickname);
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phone_number);
	std::cout << "Enter darkest secret: ";
	std::getline(std::cin, darkest_secret);
}

bool Contact::is_slot_taken(){
	return (this->slot_taken);
}