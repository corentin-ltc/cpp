#include "Brain.hpp"

using std::cout;
using std::endl;

Brain::Brain()
{
	cout << "Brain default constructor called." << endl;
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	cout << "Brain copy constructor called." << endl;
}

Brain &Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	cout << "Brain destructor called." << endl;
}
