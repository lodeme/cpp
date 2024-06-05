#include <Dog.hpp>
#include <iostream>


// Canonical Othodox Form
Dog::Dog(void): _type("Dog") {
  _brain = new Brain();
  std::cout << "Dog created with default constructor of type " << _type << std::endl;
}

Dog::~Dog(void) {
  delete _brain;
  std::cout << "Dog destroyed of type " << _type << std::endl;
}

Dog::Dog(const Dog& other): Animal(other) {
  this->_type = other._type;
  _brain = new Brain(*other._brain);
  std::cout << "Dog created with copy constructor of type " << _type << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
  Animal::operator=(other);
  this->_type = other._type;
  _brain = other._brain;
  std::cout << "Dog created with copy assignment operator of type " << _type << std::endl;
  return *this;
}

// Custom Functions
const std::string& Dog::getType(void) const {
  return _type;
}

void Dog::makeSound(void) const {
  std::cout << "The dog is barking" << std::endl;
}


