#ifndef SC_FORM_HPP
#define SC_FORM_HPP

#include <string>
#include <AForm.hpp>

class ShrubberyCreationForm : public AForm {
  private:
    const std::string _target;

  public:
    // canonical form
    ShrubberyCreationForm();
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string& target);
    ShrubberyCreationForm& operator=(ShrubberyCreationForm& other);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
};

    // other
    void execute(const Bureaucrat& bureaucrat) const;

#endif
