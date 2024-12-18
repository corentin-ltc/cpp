#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
	protected:
		std::string name;
	public:
		Data();
		Data(std::string name);
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data();
		std::string getName() const ;
};

#endif
