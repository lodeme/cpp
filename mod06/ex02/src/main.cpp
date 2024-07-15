#include <Base.hpp>
#include <iostream>

int main() {

  for (int i = 1; i <= 10; i++) {
    std::cout << "Generating class number " << i << std::endl;
    Base* b = generate();
    identify(b);
    identify(*b);
    std::cout << std::endl;
  }

  return 0;
}
