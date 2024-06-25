#include <Bureaucrat.hpp>
#include <iostream>

Bureaucrat::Bureaucrat(void): _name("Default"), _grade(75) {};

Bureaucrat::~Bureaucrat(void) {};

Bureaucrat::Bureaucrat(const std::string& name, int grade):
  _name(name) {
  try {
    if (grade < 1 || grade > 150) {
      throw 1;
    }
    _grade = grade;
  } catch (int e) {
    std::cerr << "Could not create bureaucrat: grade must be between 1 and 150" << std::endl;
  }
};

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
  if (this != &other) {
    /* this->_name = other._name; */
    this->_grade = other._grade;
  }
  return *this;
};

const std::string& Bureaucrat::getName(void) const {
  return _name;
}

int Bureaucrat::getGrade(void) const {
  return _grade;
}

void Bureaucrat::incrementGrade(void) {
  try {
    if (_grade - 1 < 1) {
      throw 1;
    }
    _grade--;
  }
  catch (int e) {
    std::cerr << "Cannot increment grade: it is already 1" << std::endl;
  }
}

void Bureaucrat::decrementGrade(void) {
  try {
    if (_grade + 1 > 150) {
      throw 1;
    }
    _grade++;
  }
  catch (int e) {
    std::cerr << "Cannot decrement grade: it is already 150" << std::endl;
  }
}

