#include <Dog.hpp>
#include <iostream>

Dog::Dog(void) : _type("Dog") {}

Dog::~Dog(void) {}

const std::string& Dog::getType(void) {
  return _type;
}

void Dog::makeSound(void) const {
  std::cout << "The dog is barking" << std::endl;
}


