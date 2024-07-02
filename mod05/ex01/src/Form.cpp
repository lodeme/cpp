#include <Form.hpp>

Form::Form():
  _name("Default"), _signed(false), _gradeToSign(75), _gradeToExecute(75) {
};

Form::Form(std::string& name, int gradeToSign, int gradeToExecute):
  _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
  if (_gradeToSign < 1 || _gradeToExecute < 1)
    throw gradeTooHighException();
  if (_gradeToSign > 150 || _gradeToExecute > 150)
    throw gradeTooLowException();
}

Form& Form::operator=(Form& other) {
  if (this != &other)
    this->_signed = other._signed;
  return *this;
}

const std::string& Form::getName() {
  return _name;
}

bool Form::getIsSigned() {
  return _signed;
}

int Form::getGradeToSign() {
  return _gradeToSign;
}

int Form::getGradeToExecute() {
  return _gradeToExecute;
}

const char* Form::gradeTooHighException::what() const throw() {
  return "Grade cannot be better than 1";
}

const char* Form::gradeTooLowException::what() const throw() {
  return "Grade cannot be worse than 150";
}

std::ostream& operator<<(std::ostream& str, Form& form) {
  return str  << "Form " << form.getName()
              << ", is signed: " << form.getIsSigned()
              << ". Requires grades of " << form.getGradeToSign()
              << " to sign and " << form.getGradeToExecute()
              << " to execute";
}
