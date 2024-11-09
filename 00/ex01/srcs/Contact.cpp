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
		if (!getline(std::cin, input))
			exit(EXIT_FAILURE);
	} while (input == "");
	return (input);
}

bool Contact::is_slot_taken(){
	return (slot_taken);
}

std::string Contact::display_first_name(){
	return first_name;
}
std::string Contact::display_last_name(){
	return last_name;

}
std::string Contact::display_nickname(){
	return nickname;

}
std::string Contact::display_darkest_secret(){
	return darkest_secret;
}
std::string Contact::display_phone_number(){
	return phone_number;
}
