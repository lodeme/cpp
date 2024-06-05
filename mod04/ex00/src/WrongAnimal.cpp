#include <WrongAnimal.hpp>
#include <iostream>

// Canonical Othodox Form
WrongAnimal::WrongAnimal(void) : _type("WrongAnimal") {
  std::cout << "WrongAnimal created with default constructor of type " << _type << std::endl;
}

WrongAnimal::~WrongAnimal(void) {
  std::cout << "WrongAnimal destroyed of type " << _type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
  this->_type = other._type;
  std::cout << "WrongAnimal created with copy constructor of type " << _type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
  this->_type = other._type;
  std::cout << "WrongAnimal created with copy assignment operator of type " << _type << std::endl;
  return *this;
}

// Custom Functions
const std::string& WrongAnimal::getType(void) const {
  return _type;
}

void WrongAnimal::makeSound(void) const {
  std::cout << "The wrong animal is vocalizing of type " << _type << std::endl;
}
