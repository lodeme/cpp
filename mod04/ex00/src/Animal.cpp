#include <Animal.hpp>
#include <iostream>

Animal::Animal(void) : _type("Animal") {}

Animal::~Animal(void) {}

const std::string& Animal::getType(void) const {
  return _type;
}

void Animal::makeSound(void) const {
  std::cout << "The animal is vocalizing" << std::endl;
}
