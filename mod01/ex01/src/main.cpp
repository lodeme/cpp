#include "Zombie.hpp"

int main(void) {
  // Use default constructor
  Zombie def;
  def.announce();

  // Create horde
	int n = 4;
	Zombie* horde = zombieHorde(n, "Foo");
	for (int i = 0; i < n; i++) {
		horde[i].announce();
	}
	delete[] horde;
	return (0);
}
