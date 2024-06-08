#pragma once
#include <Animal.hpp>
#include <Brain.hpp>

class Dog : public Animal {
  private:
    Brain* _brain;

  protected:
    std::string _type;

  public:
    Dog(void);
    ~Dog(void);
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);

    const std::string& getType(void) const;
    void setType(std::string& type);
    void makeSound(void) const;
};

