#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

// Canonical Form
ScavTrap::ScavTrap(void): _gkMode(false) {
  std::cout << "Default ScavTrap constructor called." << std::endl;
}

ScavTrap::~ScavTrap(void) {
  std::cout << "ScavTrap Destructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name), _gkMode(false) {
  std::cout << "ScavTrap Named constructor called." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& other): ClapTrap(other) {
  std::cout << "ScavTrap Copy constructor called." << std::endl;
  *this = other;
}

ScavTrap& ScavTrap::operator=(ScavTrap& other) {
  std::cout << "Assignment overload operator called." << std::endl;
  ClapTrap::operator=(other);
  if (this != &other) {
    this->_gkMode = other.getGkMode();
  }
  return *this;
}

// Getters and Setters
bool ScavTrap::getGkMode(void) {
  return _gkMode;
}

// Other Public Functions
void ScavTrap::attack(const std::string& target) {
  if (_energy > 0 && _hp > 0) {
    _energy--;
    std::cout  << "ScavTrap " << _name
              << " attacks " << target
              << ", causing " << _attack << " points of damage!"
              << std::endl;
  } else {
    std::cout   << "ScavTrap " << _name
                << " cannot attack: insufficient hit points or energy." << std::endl;
  }
}

void ScavTrap::guardGate(void) {
  if (_energy > 0 && _hp > 0) {
    _gkMode = true;
    std::cout << "ScavTrap " << _name
              << " is guarding gate."
              << std::endl;
  } else {
    std::cout << "ScavTrap " << _name
              << " cannot guard gate: insufficient hit points or energy."
              << std::endl;
  }
}
