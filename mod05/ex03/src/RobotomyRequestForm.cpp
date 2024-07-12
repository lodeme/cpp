#include <BureaucratForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
  : AForm("RobotomyRequestForm", 72, 45), _target("Default") {
  seedGenerator();
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
  : AForm("RobotomyRequestForm", 72, 45), _target(target) {
  seedGenerator();
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
  : AForm(other), _target(other._target) {
  seedGenerator();
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm& other) {
  (void)other;
  return *this;
}

void RobotomyRequestForm::seedGenerator() {
  srand(static_cast<unsigned int>(std::time(0)));
}

bool RobotomyRequestForm::flipCoin() const {
  return std::rand() % 2 == 0;
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
