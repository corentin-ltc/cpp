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

	index = this->get_index();
	this->contacts[index].fill_contact();
}