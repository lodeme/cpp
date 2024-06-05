#pragma once
#include <string>

class WrongAnimal {
  protected:
    std::string _type;

  public:
    WrongAnimal(void);
    virtual ~WrongAnimal(void);
    WrongAnimal(const WrongAnimal& other);
    WrongAnimal& operator=(const WrongAnimal& other);

    const std::string& getType(void) const;
    void makeSound(void) const;
};
