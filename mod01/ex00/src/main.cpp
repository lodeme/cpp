#include "Zombie.hpp"

int main(void) {
	Zombie z1("Foo");
	z1.announce();

	Zombie* z2 = newZombie("Bar");
	z2->announce();

	randomChump("Baz");

	delete z2;
	return (0);
}