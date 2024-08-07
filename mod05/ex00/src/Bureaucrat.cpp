#include <Bureaucrat.hpp>
#include <iostream>

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(75) {};

Bureaucrat::~Bureaucrat(void) {};

Bureaucrat::Bureaucrat(const std::string& name, int grade):
  _name(name), _grade(grade) {
  if (grade < 1)
    throw GradeTooHighException();
  if (grade > 150)
    throw GradeTooLowException();
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    this->_grade = other._grade;
  }
  return *this;
};

Bureaucrat::Bureaucrat(Bureaucrat& other) 
  :_name(other._name), _grade(other._grade) {
}

const std::string& Bureaucrat::getName(void) const {
  return _name;
}

int Bureaucrat::getGrade(void) const {
  return _grade;
}

void Bureaucrat::incrementGrade(void) {
  _grade--;
  if (_grade < 1)
    throw GradeTooHighException();
}

void Bureaucrat::decrementGrade(void) {
  _grade++;
  if (_grade > 150)
    throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw() {
  return "Grade cannot be better than 1";
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw() {
  return "Grade cannot be worse than 150";
}

std::ostream &operator<<(std::ostream &str, Bureaucrat const &b) {
  return str << b.getName() << ", bureaucrat grade " << b.getGrade();
}

