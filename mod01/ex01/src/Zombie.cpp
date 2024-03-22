#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	_name = name;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie destroyed: " << _name << std::endl;
}

void Zombie::announce(void) const {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::changeName(std::string newName) {
	_name = newName;
}