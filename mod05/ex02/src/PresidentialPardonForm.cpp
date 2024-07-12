#include <BureaucratForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
  : AForm("PresidentialPardonForm", 25, 5), _target("Default") {
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
  : AForm("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
  : AForm(other), _target(other._target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& other) {
  (void)other;
  return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const {
  if (getIsSigned() == false)
    throw formNotSignedException();
  if (bureaucrat.getGrade() > getGradeToExecute())
    throw gradeTooLowException();
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
