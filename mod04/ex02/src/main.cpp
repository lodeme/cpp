#include <iostream>
#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
#include <iostream>

int main(void) {

  // Animals array creation
  unsigned int n = 3;
  Animal* animals[n];

  for (unsigned int i = 0; i < n; i++) {
    std::cout << "Creating Animal number " << i << std::endl;
    if (i < n / 2) {
      animals[i] = new Dog();
    } else {
      animals[i] = new Cat();
    }
  }

  for (unsigned int i = 0; i < n; i++) {
    std::cout << "Destroying Animal number " << i << std::endl;
    delete animals[i];
  }

  // Virtual Class Testing
  // Animal test;

  return 0;
}
