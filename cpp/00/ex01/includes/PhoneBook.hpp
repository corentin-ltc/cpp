#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__

#include "Contact.hpp"
#include <iostream>
#include <string>

class PhoneBook {
	public:

		Contact contacts[8];
		int		get_index();
		void	add_a_contact();
		void	display_contacts();
		void	search_contact();
		void	display_values(std::string *category);
		bool	is_index_valid(std::string index);
};

#endif