#pragma once
#include <string>

class Animal {
  protected:
    std::string _type;

  public:
    Animal(void);
    ~Animal(void);

    virtual const std::string& getType(void) const;
    virtual void makeSound(void) const;
};
