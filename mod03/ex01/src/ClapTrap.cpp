#include "ClapTrap.hpp"
#include <iostream>

// Canonical Form
ClapTrap::ClapTrap(void)
  : _name("John Doe"), _hp(100), _energy(50), _attack(20) {
  std::cout << "Default ClapTrap constructor called." << std::endl;
}

ClapTrap::~ClapTrap(void) {
  std::cout << "ClapTrap Destructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name)
  : _name(name), _hp(100), _energy(50), _attack(20) {
  std::cout << "ClapTrap Named constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& other) {
  std::cout << "ClapTrap Copy constructor called." << std::endl;
  *this = other;
}

ClapTrap& ClapTrap::operator=(ClapTrap& other) {
  std::cout << "ClapTrap Assignment overload operator called." << std::endl;
  if (this != &other) {
    this->_name = other.getName();
    this->_hp = other.getHp();
    this->_energy = other.getEnergy();
    this->_attack = other.getAttack();
  }
  return *this;
}

// Getters and Setters
std::string& ClapTrap::getName(void) {
  return _name;
}

unsigned int ClapTrap::getHp(void) {
  return _hp;
}

unsigned int ClapTrap::getEnergy(void) {
  return _energy;
}

unsigned int ClapTrap::getAttack(void) {
  return _attack;
}

void ClapTrap::setEnergy(int change) {
  _energy += change;
}

// Other Public Functions
void ClapTrap::attack(const std::string& target) {
  if (_energy > 0 && _hp > 0) {
    _energy--;
    std::cout  << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attack << " points of damage!"
              << std::endl;
  } else {
    std::cout   << "ClapTrap " << _name
                << " cannot attack: insufficient hit points or energy." << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hp < amount) {
    _hp = 0;
  } else {
    _hp -= amount;
  }
  std::cout << "ClapTrap " << _name
            << " lost " << amount 
            << " health points, " << _hp << " remaining."
            << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hp > 0 && _energy > 0) {
    _hp += amount;
    _energy--;
    std::cout << "ClapTrap " << _name
      << " repaired, gaining " << amount << " health points ("
      << _hp << " total)."
      << std::endl;
  } else {
    std::cout << "ClapTrap " << _name
      << " cannot repair: insufficient hit points or energy." << std::endl;
  }
}

