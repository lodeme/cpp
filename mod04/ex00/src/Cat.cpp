#include <Cat.hpp>
#include <iostream>

Cat::Cat(void) : _type("Cat") {}

Cat::~Cat(void) {}

const std::string& Cat::getType(void) const {
  return _type;
}

void Cat::makeSound(void) const {
  std::cout << "The cat is meowing" << std::endl;
}

