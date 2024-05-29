#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void)
  : _name("John Doe"), _hp(10), _energy(10), _attack(0) {
  std::cout << "Default constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
  : _name(name), _hp(10), _energy(10), _attack(0) {
  std::cout << "Named constructor called" << std::endl;
}

