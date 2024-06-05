#include <iostream>
#include <Animal.hpp>
#include <Cat.hpp>
#include <Dog.hpp>

int main(void) {
  const Animal* meta = new Animal();
  const Animal* j = new Dog();
  const Animal* i = new Cat();
  const Animal* k = new Dog("Border Collie");

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  std::cout << k->getType() << " " << std::endl;

  i->makeSound(); //will output the cat sound!
  j->makeSound();
  meta->makeSound();
  k->makeSound();

  delete meta;
  delete j;
  delete i;
  delete k;
  return 0;
}
