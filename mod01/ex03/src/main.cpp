#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
#include <iostream>

int main()
{
	{
    Weapon club = Weapon("crude spiked club");
    std::cout << "Weapon " << club.getType() << " created" << std::endl;
    HumanA bob("Bob", club);
    bob.attack();
    club.setType("some other type of club");
    bob.attack();
	}

	{
    Weapon club = Weapon("other crude spiked club");
    std::cout << "Weapon " << club.getType() << " created" << std::endl;
    HumanB jim("Jim");
    jim.setWeapon(&club);
    jim.attack();
    club.setType("some new other type of club");
    jim.attack();
	}

	return 0;
}
