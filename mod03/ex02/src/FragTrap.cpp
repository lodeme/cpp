#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

// Canonical Form
FragTrap::FragTrap(void) {
  std::cout << "Default FragTrap constructor called." << std::endl;
}

FragTrap::~FragTrap(void) {
  std::cout << "FragTrap Destructor called." << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name) {
  std::cout << "FragTrap Named constructor called." << std::endl;
}

FragTrap::FragTrap(FragTrap& other): ClapTrap(other) {
  std::cout << "FragTrap Copy constructor called." << std::endl;
  *this = other;
}

FragTrap& FragTrap::operator=(FragTrap& other) {
  std::cout << "Assignment overload operator called." << std::endl;
  ClapTrap::operator=(other);
  return *this;
}

// Other Public Functions
void FragTrap::attack(const std::string& target) {
  if (getEnergy() > 0 && getHp() > 0) {
    setEnergy(-1);
    std::cout  << "FragTrap " << getName()
              << " attacks " << target
              << ", causing " << getAttack() << " points of damage!"
              << std::endl;
  } else {
    std::cout   << "FragTrap " << getName()
                << " cannot attack: insufficient hit points or energy." << std::endl;
  }
}

void FragTrap::highFivesGuys(void) {
  if (getEnergy() > 0 && getHp() > 0) {
    std::cout  << "FragTrap " << getName()
              << " accepted high five request. "
              << std::endl;
  } else {
    std::cout   << "FragTrap " << getName()
                << " cannot high five: insufficient hit points or energy." << std::endl;
  }
}
