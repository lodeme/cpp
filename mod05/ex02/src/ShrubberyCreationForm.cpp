#include <BureaucratForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
  : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
  : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
  : AForm(other), _target(other._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& other) {
  (void)other;
  return *this;
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
  if (getIsSigned() == false)
    throw formNotSignedException();
  if (bureaucrat.getGrade() > getGradeToExecute())
    throw gradeTooLowException();
  std::ofstream file(getName() + "_shrubbery");
  file << "      /||" << std::endl;
  file << "     |||||" << std::endl;
  file << "     |||||" << std::endl;
  file << " /|  |||||" << std::endl;
  file << "|||| |||||" << std::endl;
  file << "|||| |||||  /|" << std::endl;
  file << "|||| ||||| ||||" << std::endl;
  file << " ||`-'|||| ||||" << std::endl;
  file << "  |__ |||| ||||" << std::endl;
  file << "     ||||`-'|||" << std::endl;
  file << "     |||| ___/" << std::endl;
  file << "     |||||" << std::endl;
  file << "     |||||" << std::endl;
  file << "-----------------" << std::endl;
}
