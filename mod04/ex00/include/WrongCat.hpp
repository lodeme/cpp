#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
  protected:
    std::string _type;

  public:
    WrongCat(void);
    ~WrongCat(void);
    WrongCat(const std::string& type);
    WrongCat(const WrongCat& other);
    WrongCat& operator=(const WrongCat& other);

    const std::string& getType(void) const;
    void makeSound(void) const;
};
