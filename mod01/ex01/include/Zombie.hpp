#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name = "");
		~Zombie(void);
		void announce(void) const;
		void changeName(std::string newName);

	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);
