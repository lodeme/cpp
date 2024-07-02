#include <Brain.hpp>
#include <iostream>

Brain::Brain(void) {
  std::cout << "Brain created with default constructor" << std::endl;
}

Brain::~Brain(void) {
  std::cout << "Brain destroyed" << std::endl;
}

Brain::Brain(const Brain& other) {
  std::cout << "Brain created with copy constructor" << std::endl;
  *this = other;
}

Brain& Brain::operator=(const Brain& other) {
  std::cout << "Brain created with copy assignment operator" << std::endl;
  std::copy(other._ideas, other._ideas + 100, this->_ideas);
  return *this;
}
