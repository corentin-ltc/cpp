#include "PhoneBook.hpp"

void PhoneBook::add_a_contact(){

	for (int i = 6; i >= 0; i--)
		contacts[i + 1] = contacts[i];
	contacts[0].fill_contact();
}

void PhoneBook::display_contacts(){

	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     Index|First name| Last name|  Nickname|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;

	for (int i = 0; i < 8 && contacts[i].is_slot_taken() ; i++)
	{
		std::cout << "|         " << i + 1 << '|';
		display_values(&(contacts[i].first_name));
		display_values(&(contacts[i].last_name));
		display_values(&(contacts[i].nickname));
		std::cout << std::endl;
	}
	std::cout << "|___________________________________________|" << std::endl;
	search_contact();
}

bool PhoneBook::is_index_valid(std::string index){
	if (index[0] < '1' || index [0] > '8' || index [1] != '\0')
		return (false);
	if (contacts[index[0] - 49].is_slot_taken())
		return (true);
	return (false);
}

void PhoneBook::search_contact(){
	std::string	input;

	do{
		std::cout << "Enter a valid contact index or \"LEAVE\" to leave: " << std::endl;
		getline(std::cin, input);
		if (input == "LEAVE")
			return ;
	} while (!is_index_valid(input));
	std::cout << "First name: " << contacts[input[0] - 49].first_name << std::endl;
	std::cout << "Last name: " << contacts[input[0] - 49].last_name << std::endl;
	std::cout << "Nickname: " << contacts[input[0] - 49].nickname << std::endl;
	std::cout << "Phone number: " << contacts[input[0] - 49].phone_number << std::endl;
	std::cout << "Darkest secret: " << contacts[input[0] - 49].darkest_secret << std::endl;
}

void PhoneBook::display_values(std::string *category){

	bool is_truncated = true;

	for (int j = 0; category->length() + j < 10; j++){
			std::cout << ' ';
			is_truncated = false;
		}
		for (int j = 0; j < 10 && (*category)[j]; j++)
		{
			if (is_truncated && j == 9 ){
				std::cout << '.';
				break;
			}
			std::cout << (*category)[j];
		}
		std::cout << "|";
}