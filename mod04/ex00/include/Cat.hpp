#pragma once
#include "Animal.hpp"

class Cat : public Animal {
  protected:
    std::string _type;

  public:
    Cat(void);
    ~Cat(void);
    Cat(const std::string& type);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);

    const std::string& getType(void) const;
    void makeSound(void) const;
};
