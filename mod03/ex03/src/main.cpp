#include <iostream>
#include "DiamondTrap.hpp"

void DiamondLifecycle(DiamondTrap diamond) {
  std::cout << std::endl
            << "Starting lifecycle for DiamondTrap: "
            << diamond.getName()
            << std::endl;
  const std::string target("targetDiamond");
  diamond.takeDamage(5);
  diamond.beRepaired(3);
  diamond.attack(target);
  diamond.highFivesGuys();
  diamond.guardGate();
  diamond.takeDamage(10);
  diamond.takeDamage(200);
  diamond.beRepaired(5);
  diamond.attack(target);
  diamond.highFivesGuys();
  diamond.guardGate();
  diamond.whoAmI();
}

int main(void) {
  DiamondTrap diamond1;
  DiamondTrap diamond2("NewDiamond");
  DiamondTrap diamond3(diamond2);
  DiamondTrap diamond4("LastDiamond");
  DiamondTrap diamond5 = diamond4;

  DiamondLifecycle(diamond1);
  DiamondLifecycle(diamond2);
  DiamondLifecycle(diamond3);
  DiamondLifecycle(diamond5);

  return 0;
}
