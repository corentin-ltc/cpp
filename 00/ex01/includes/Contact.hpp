#ifndef __CONTACT_H__
#define __CONTACT_H__

#include <string>
#include <iostream>

class Contact {
	private:
		bool slot_taken;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	darkest_secret;
		std::string phone_number;

	public:
		Contact() : slot_taken(false) {}
		std::string display_first_name();
		std::string display_last_name();
		std::string display_nickname();
		std::string display_darkest_secret();
		std::string display_phone_number();
		bool is_slot_taken();
		void fill_contact();
		std::string get_input(std::string prompt);
};

#endif