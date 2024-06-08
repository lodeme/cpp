#include <iostream>
#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>
#include <iostream>

int main(void) {

  // Animals array creation
  unsigned int n = 7;
  Animal* animals = new Animal[n];

  for (unsigned int i = 0; i < n; i++) {
    std::cout << "Creating Animal number " << i << std::endl;
    if (i < n / 2) {
      animals[i] = Dog();
    } else {
      animals[i] = Cat();
    }
  }

  delete[] animals;

  // Deep copy testing
    Cat kitty;
    Cat furball = kitty;  // Calls the copy constructor

    std::cout << "Original data: " << kitty.getType() << std::endl;
    std::cout << "Copy data: " << furball.getType() << std::endl;

    // Modify original
    std::string newstr = "Tiger";
    kitty.setType(newstr);

    std::cout << "After modifying original:" << std::endl;
    std::cout << "Original data: " << kitty.getType() << std::endl;
    std::cout << "Copy data: " << furball.getType() << std::endl;

  return 0;
}
