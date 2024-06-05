#include <WrongCat.hpp>
#include <iostream>

// Canonical Othodox Form
WrongCat::WrongCat(void): _type("WrongCat") {
  std::cout << "WrongCat created with default constructor of type " << _type << std::endl;
}

WrongCat::~WrongCat(void) {
  std::cout << "WrongCat destroyed of type " << _type << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
  this->_type = other._type;
  std::cout << "WrongCat created with copy constructor of type " << _type << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
  WrongAnimal::operator=(other);
  this->_type = other._type;
  std::cout << "WrongCat created with copy assignment operator of type " << _type << std::endl;
  return *this;
}

// Custom Functions
const std::string& WrongCat::getType(void) const {
  return _type;
}

void WrongCat::makeSound(void) const {
  std::cout << "The wrong cat is meowing" << std::endl;
}

