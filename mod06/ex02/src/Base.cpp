#include <Base.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

Base::~Base() {};

Base* generate() {
  static bool seeded = false;
  if (!seeded) {
    std::srand(std::time(0));
    seeded = true;
  }

  int pick = std::rand() % 3;

  if (pick == 0)
    return new A;
  else if (pick == 1)
    return new B;
  else
    return new C;
}

void identify(Base* p) {
  if (dynamic_cast<A*>(p))
    std::cout << "Pointer of class A detected" << std::endl;
  else if (dynamic_cast<B*>(p))
    std::cout << "Pointer of class B detected" << std::endl;
  else if (dynamic_cast<C*>(p))
    std::cout << "Pointer of class C detected" << std::endl;
  else
    std::cout << "Pointer type could not be detected" << std::endl;
}

void identify(Base& p) {
  try {
   (void)dynamic_cast<A&>(p);
    std::cout << "Reference of class A detected" << std::endl;
    return;
  } catch (std::exception& e) {}

  try {
   (void)dynamic_cast<B&>(p);
    std::cout << "Reference of class B detected" << std::endl;
    return;
  } catch (std::exception& e) {}

  try {
   (void)dynamic_cast<C&>(p);
    std::cout << "Reference of class C detected" << std::endl;
    return;
  } catch (std::exception& e) {}

  std::cout << "Reference type could not be detected" << std::endl;
}
