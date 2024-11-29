#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public:
		WrongDog();
		WrongDog(std::string type);
		WrongDog(const WrongDog &other);
		WrongDog &operator=(const WrongDog &other);
		~WrongDog();
		void makeSound() const;
	
};

#endif
