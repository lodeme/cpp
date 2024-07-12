#pragma once

#include <AForm.hpp>
#include <string>

class Intern {
  public:
    // Canonical Form
    Intern();
    ~Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);

    // Other
    AForm* makeForm(std::string name, std::string target);
};
