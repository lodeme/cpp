#ifndef PP_FORM_HPP
#define PP_FORM_HPP

#include <string>
#include <AForm.hpp>

class PresidentialPardonForm : public AForm {
  private:
    const std::string _target;

  public:
    // canonical form
    PresidentialPardonForm();
    ~PresidentialPardonForm();
    PresidentialPardonForm(const std::string& target);
    PresidentialPardonForm& operator=(PresidentialPardonForm& other);
    PresidentialPardonForm(const PresidentialPardonForm& other);

    // other
    void execute(const Bureaucrat& bureaucrat) const;
};

#endif
