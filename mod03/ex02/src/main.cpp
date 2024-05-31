#include <iostream>
#include "FragTrap.hpp"

void FragLifecycle(FragTrap frag) {
  std::cout << std::endl
            << "Starting lifecycle for FragTrap: "
            << frag.getName()
            << std::endl;
  const std::string target("targetFrag");
  frag.takeDamage(5);
  frag.beRepaired(3);
  frag.attack(target);
  frag.highFivesGuys();
  frag.takeDamage(10);
  frag.takeDamage(200);
  frag.beRepaired(5);
  frag.attack(target);
  frag.highFivesGuys();
}

int main(void) {
  FragTrap frag1;
  FragTrap frag2("NewFrag");
  FragTrap frag3(frag2);
  FragTrap frag4("LastFrag");
  FragTrap frag5 = frag4;

  FragLifecycle(frag1);
  FragLifecycle(frag2);
  FragLifecycle(frag3);
  FragLifecycle(frag5);

  return 0;
}
