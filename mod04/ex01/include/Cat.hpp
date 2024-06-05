#pragma once
#include <Animal.hpp>
#include <Brain.hpp>

class Cat : public Animal {
  private:
    Brain* _brain;

  protected:
    std::string _type;

  public:
    Cat(void);
    ~Cat(void);
    Cat(const Cat& other);
    Cat& operator=(const Cat& other);

    const std::string& getType(void) const;
    void makeSound(void) const;
};
