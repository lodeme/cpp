#pragma once
#include <string>

class Animal {
  protected:
    std::string _type;

  public:
    Animal(void);
    ~Animal(void);

    const std::string& getType(void) const;
    void makeSound(void) const;
};
