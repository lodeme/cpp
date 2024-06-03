#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

// Canonical Form
DiamondTrap::DiamondTrap(void) {
  ClapTrap::_name = "default_clap_name";
  this->_name = "default";
  std::cout << "Default DiamondTrap constructor called." << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
  std::cout << "DiamondTrap Destructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name)
    : ClapTrap(name + "_clap_name") {
  this->_name = name;
  this->_hp = FragTrap::_hp;
  this->_energy = ScavTrap::_energy;
  this->_attack = FragTrap::_attack;
  std::cout << "DiamondTrap Named constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& other)
  : ClapTrap(other), ScavTrap(other), FragTrap(other) {
  this->_name = other._name;
  *this = other;
  std::cout << "DiamondTrap Copy constructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& other) {
  std::cout << "Assignment overload operator called." << std::endl;
  ClapTrap::operator=(other);
  return *this;
}

// Other Public Functions
void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
  std::cout << "DiamondTrap Attack function called" << std::endl;
}

void DiamondTrap::whoAmI(void) {
  std::cout << "Current DiamondTrap: " << this->_name
            << " (" << ClapTrap::_name << ")"
            << std::endl;
}
