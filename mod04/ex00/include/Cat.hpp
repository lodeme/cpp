#pragma once
#include "Animal.hpp"

class Cat : public Animal {
  protected:
    std::string _type;

  public:
    Cat(void);
    ~Cat(void);

    const std::string& getType(void);
    void makeSound(void) const;
};
