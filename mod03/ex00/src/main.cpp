#include "ClapTrap.hpp"
#include <iostream>

void ClapLifecycle(ClapTrap clap) {
  std::cout << std::endl << "Starting lifecycle for ClapTrap: " << clap.getName() << std::endl;
  const std::string target("targetClap");
  clap.takeDamage(5);
  clap.beRepaired(3);
  clap.attack(target);
  clap.takeDamage(10);
  clap.takeDamage(2);
  clap.beRepaired(5);
  clap.attack(target);
}

int main(void) {
  ClapTrap clap1;
  ClapTrap clap2("NewClap");
  ClapTrap clap3(clap2);
  ClapTrap clap4("LastClap");
  ClapTrap clap5 = clap4;

  ClapLifecycle(clap1);
  ClapLifecycle(clap2);
  ClapLifecycle(clap3);
  ClapLifecycle(clap5);

  return 0;
}
