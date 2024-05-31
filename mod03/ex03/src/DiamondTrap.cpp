#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

// Canonical Form
DiamondTrap::DiamondTrap(void) {
  std::cout << "Default DiamondTrap constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap Destructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name) {
  std::cout << "DiamondTrap Named constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& other): ClapTrap(other) {
  std::cout << "DiamondTrap Copy constructor called." << std::endl;
  *this = other;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& other) {
  std::cout << "Assignment overload operator called." << std::endl;
  ClapTrap::operator=(other);
  if (this != &other) {
    this->_gkMode = other.getGkMode();
  }
  return *this;
}

// Getters and Setters
bool DiamondTrap::getGkMode(void) {
  return _gkMode;
}

// Other Public Functions
void DiamondTrap::attack(const std::string& target) {
  if (getEnergy() > 0 && getHp() > 0) {
    setEnergy(-1);
    std::cout  << "DiamondTrap " << getName()
              << " attacks " << target
              << ", causing " << getAttack() << " points of damage!"
              << std::endl;
  } else {
    std::cout   << "DiamondTrap " << getName()
                << " cannot attack: insufficient hit points or energy." << std::endl;
  }
}

void DiamondTrap::guardGate(void) {
  if (getEnergy() > 0 && getHp() > 0) {
    _gkMode = true;
    std::cout << "DiamondTrap " << getName()
              << " is guarding gate."
              << std::endl;
  } else {
    std::cout << "DiamondTrap " << getName()
              << " cannot guard gate: insufficient hit points or energy."
              << std::endl;
  }
}
