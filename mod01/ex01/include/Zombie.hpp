#include <string>

class Zombie
{
	public:
    Zombie(void);
		Zombie(std::string);
		~Zombie(void);
		void announce(void) const;
		void changeName(std::string newName);

	private:
		std::string _name;
};

Zombie* zombieHorde(int N, std::string name);
