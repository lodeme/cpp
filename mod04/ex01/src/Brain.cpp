#include <Brain.hpp>
#include <iostream>

Brain::Brain(void) {
  std::cout << "Constructor of brain called" << std::endl;
}

Brain::~Brain(void) {
  std::cout << "Destructor of brain called" << std::endl;
}

Brain::Brain(const Brain& other) {
  std::cout << "Copy constructor of brain called" << std::endl;
  *this = other;
}

Brain& Brain::operator=(const Brain& other) {
  std::cout << "Copy assignment operator of Brain called" << std::endl;
  std::copy(other._ideas, other._ideas + 100, this->_ideas);
  return *this;
}
