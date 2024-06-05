#pragma once
#include "Animal.hpp"

class Dog : public Animal {
  protected:
    std::string _type;

  public:
    Dog(void);
    ~Dog(void);
    Dog(const std::string& type);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);

    const std::string& getType(void) const;
    void makeSound(void) const;
};

