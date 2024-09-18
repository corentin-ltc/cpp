#include "PhoneBook.hpp"

int PhoneBook::get_index(){
	
	for (int i = 0; i < 8; i++){
		if (!contacts[i].is_slot_taken())
			return (i);
	}
	for (int i = 6; i >= 0; i--){
		contacts[i + 1] = contacts[i];
	}
	return (0);
}

void PhoneBook::add_a_contact(){

	int index;

	index = get_index();
	contacts[index].fill_contact();
}

void PhoneBook::display_contacts(){

	for (int i = 0; i < 8 && contacts[i].is_slot_taken() ; i++)
	{
		std::cout << "Index : " << i << "|";
		for (int j = 0; j < 10 && contacts[i].first_name[j]; j++)
			std::cout << contacts[i].first_name;
		
	}
}