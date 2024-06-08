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
