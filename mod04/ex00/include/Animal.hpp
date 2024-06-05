#pragma once
#include <string>

class Animal {
  protected:
    std::string _type;

  public:
    Animal(void);
    virtual ~Animal(void);
    Animal(const std::string& type);
    Animal(const Animal& other);
    Animal& operator=(const Animal& other);

    virtual const std::string& getType(void) const;
    virtual void makeSound(void) const;
};
