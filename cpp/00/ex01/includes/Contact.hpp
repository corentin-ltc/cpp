#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include <iostream>

class Contact {
	private:
		bool slot_taken;

	public:
		Contact() : slot_taken(false) {}

		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	darkest_secret;
		std::string phone_number;

		bool is_slot_taken();
		void fill_contact();
		std::string get_input(std::string prompt);
};

#endif