#include <BureaucratForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <iostream>
#include <random>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm()
  : AForm("RobotomyRequestForm", 72, 45), _target("Default") {
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
  : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
  : AForm(other), _target(other._target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other) {
  (void)other;
  return *this;
}

bool RobotomyRequestForm::flipCoin() const {
  static std::mt19937 generator(std::time(0));
  return generator() % 2 == 0;
}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
  if (getIsSigned() == false)
    throw formNotSignedException();
  if (bureaucrat.getGrade() > getGradeToExecute())
    throw gradeTooLowException();
  std::cout << "Makes drilling noises... ";
  if (flipCoin()) {
    std::cout << _target << " has been robotomized." << std::endl;
  } else {
    std::cout << "The robotomy has failed." << std::endl;
  }
}
