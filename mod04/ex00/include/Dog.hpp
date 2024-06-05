#pragma once
#include "Animal.hpp"

class Dog : public Animal {
  protected:
    std::string _type;

  public:
    Dog(void);
    ~Dog(void);

    const std::string& getType(void) const;
    void makeSound(void) const;
};

