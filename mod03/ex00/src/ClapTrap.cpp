#include "ClapTrap.hpp"
#include <iostream>

// Canonical Form
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

ClapTrap::ClapTrap(ClapTrap& other) {
  *this = other;
}

ClapTrap& ClapTrap::operator=(ClapTrap& other) {
  if (this != &other) {
    this->_name = other.getName();
  }
  return *this;
}

// Getters and Setters
std::string& ClapTrap::getName(void) {
  return _name;
}
