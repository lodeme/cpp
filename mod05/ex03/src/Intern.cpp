#include <iostream>
#include <Intern.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <PresidentialPardonForm.hpp>

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern& other) {
  *this = other;
}

Intern& Intern::operator=(const Intern& other) {
  (void)other;
  return *this;
}

AForm* Intern::makeForm(std::string name, std::string target) {

  std::string formNames[] = {
    "shrubbery creation",
    "robotomy request",
    "presidential pardon"
  };
  AForm* formFunctions[] = {
    new ShrubberyCreationForm(target),
    new RobotomyRequestForm(target),
    new PresidentialPardonForm(target)
  };

  for (int i = 0; i < 3; i++) {
    if (name == formNames[i]) {
      std::cout << "Intern created " << name << std::endl;
      return formFunctions[i];
    }
  }
  std::cout << "The requested form could not be created as its type does not exist" << std::endl;
  return 0;
};

