#include <iostream>
#include "ScavTrap.hpp"

void ScavLifecycle(ScavTrap scav) {
  std::cout << std::endl
            << "Starting lifecycle for ScavTrap: "
            << scav.getName()
            << std::endl;
  const std::string target("targetScav");
  scav.takeDamage(5);
  scav.beRepaired(3);
  scav.attack(target);
  scav.guardGate();
  scav.takeDamage(10);
  scav.takeDamage(200);
  scav.beRepaired(5);
  scav.attack(target);
  scav.guardGate();
}

int main(void) {
  ScavTrap scav1;
  ScavTrap scav2("NewScav");
  ScavTrap scav3(scav2);
  ScavTrap scav4("LastScav");
  ScavTrap scav5 = scav4;

  ScavLifecycle(scav1);
  ScavLifecycle(scav2);
  ScavLifecycle(scav3);
  ScavLifecycle(scav5);

  return 0;
}
