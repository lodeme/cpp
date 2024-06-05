#include <Animal.hpp>
#include <iostream>

// Canonical Othodox Form
Animal::Animal(void) : _type("Animal") {
  std::cout << "Animal created with default constructor of type " << _type << std::endl;
}

Animal::~Animal(void) {
  std::cout << "Animal destroyed of type " << _type << std::endl;
}

Animal::Animal(const std::string& type) : _type(type) {
  std::cout << "Animal created with custom constructor of type " << _type << std::endl;
}

Animal::Animal(const Animal& other) {
  this->_type = other._type;
  std::cout << "Animal created with copy constructor of type " << _type << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
  this->_type = other._type;
  std::cout << "Animal created with copy assignment operator of type " << _type << std::endl;
  return *this;
}

// Custom Functions
const std::string& Animal::getType(void) const {
  return _type;
}

void Animal::makeSound(void) const {
  std::cout << "The animal is vocalizing of type " << _type << std::endl;
}
