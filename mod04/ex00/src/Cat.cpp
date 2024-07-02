#include <Cat.hpp>
#include <iostream>

// Canonical Othodox Form
Cat::Cat(void): _type("Cat") {
  std::cout << "Cat created with default constructor of type " << _type << std::endl;
}

Cat::~Cat(void) {
  std::cout << "Cat destroyed of type " << _type << std::endl;
}

Cat::Cat(const Cat& other): Animal(other) {
  this->_type = other._type;
  std::cout << "Cat created with copy constructor of type " << _type << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
  Animal::operator=(other);
  this->_type = other._type;
  std::cout << "Cat created with copy assignment operator of type " << _type << std::endl;
  return *this;
}

// Custom Functions
const std::string& Cat::getType(void) const {
  return _type;
}

void Cat::makeSound(void) const {
  std::cout << "The cat is meowing" << std::endl;
}

