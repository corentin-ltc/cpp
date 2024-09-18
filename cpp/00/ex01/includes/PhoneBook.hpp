#include <iostream>
#include <string>

#ifndef __PHONEBOOK_H__
#define __PHONEBOOK_H__
#include "Contact.hpp"

class PhoneBook {
	public:

		Contact contacts[8];
		int		get_index();
		void	add_a_contact();
		void	display_contacts();
};

#endif